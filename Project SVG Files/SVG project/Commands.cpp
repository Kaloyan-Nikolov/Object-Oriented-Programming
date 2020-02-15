#include "Commands.h"

void Commands::printWrongCommand()
{
	cerr << "Error! Command not recognized!" << endl;
}

void Commands::printWrongParam()
{
	cerr << "Error! Wrong Parameters!" << endl;
}

void Commands::printNoOpenedFile()
{
	cerr << "Error! There is no file opened!" << endl;
}

void Commands::printFileNotOpen()
{
	cerr << "File was not opened!" << endl;
	cerr << "Check filename or directory!" << endl;
}

void Commands::printAlreadyOpened(const string & FileName)
{
	cout << "Error! " << FileName << " is already opened!" << endl;
}

void Commands::printFileClosed(const string & FileName)
{
	cout << "Closed " << FileName << endl;
}

void Commands::printFileNotSaved()
{
	cerr << "The file was not saved!" << endl;
	cerr << "Check filename or directory!" << endl;
}

void Commands::printWrongFileName()
{
	cerr << "Error! Wrong filename!" << endl;
}

void Commands::printSuccessfullyOpened(const string & FileName)
{
	cout << "Successfully opened " << FileName << endl;
}

void Commands::printSuccessfullyCreated(const string & FileName)
{
	cout << "Successfully created " << FileName << endl;
}

void Commands::printSuccessfullySaved(const string & FileName)
{
	cout << "Successfully saved " << FileName << endl;
}

void Commands::printExitingProgram()
{
	cout << "Exiting the program..." << endl;
}

void Commands::open(const string & input, string & FileName)
{
	if ("" != FileName)
	{
		printAlreadyOpened(FileName);
		return;
	}

	if (!StringCheck::isRealFileName(input))
	{
		printWrongFileName();
		return;
	}

	if ("" == input)
	{
		printWrongParam();
		return;
	}
	FileName = input;
	FileName += ".svg";

	bool isFileCreated = true;
	if (ShapeContainer::getInstance()->readAllShapes(FileName, isFileCreated))
	{
		printSuccessfullyOpened(FileName);
	}
	else
	{
		if (isFileCreated)
		{
			printSuccessfullyCreated(FileName);
		}
		else
		{
			printFileNotOpen();
			FileName = "";
		}
	}
}

void Commands::close(const string & input, string & FileName)
{
	if ("" == FileName)
	{
		printNoOpenedFile();
		return;
	}

	if (StringCheck::isThereMoreInfo(input))
	{
		printWrongParam();
		return;
	}

	printFileClosed(FileName);
	FileName = "";
	ShapeContainer::releaseInstance();
}

void Commands::save(const string & input, string & FileName)
{
	if ("" == FileName)
	{
		printNoOpenedFile();
		return;
	}

	if (StringCheck::isThereMoreInfo(input))
	{
		printWrongParam();
		return;
	}

	if (ShapeContainer::getInstance()->printInFileAllShapes(FileName))
	{
		printSuccessfullySaved(FileName);
	}	
}

void Commands::saveas(string & input, string & FileName)
{	
	if ("" == FileName)
	{
		printNoOpenedFile();
		return;
	}

	if (!StringCheck::isRealFileName(input))
	{
		printWrongFileName();
		return;
	}

	input += ".svg";
	if (ShapeContainer::getInstance()->printInFileAllShapes(input))
	{
		printSuccessfullySaved(input);
		FileName = input;
	}
	else
	{
		printFileNotSaved();
	}	
}

void Commands::print(const string & input, const string & FileName)
{
	if ("" == FileName)
	{
		printNoOpenedFile();
		return;
	}

	if (StringCheck::isThereMoreInfo(input))
	{
		printWrongParam();
		return;
	}
	ShapeContainer::getInstance()->printAllShapes();
}

void Commands::create(string & input, const string & FileName)
{
	if ("" == FileName)
	{
		printNoOpenedFile();
		return;
	}

	string type = StringCheck::getFirstWord(input);
	BasicShape* newShape = Factory::makeShape(type);

	if (nullptr == newShape)
	{
		printWrongParam();
		return;
	}

	if (newShape->getParameters(input))
	{
		ShapeContainer::getInstance()->addShape(newShape, true);
	}
	else
	{
		printWrongParam();
	}

}

void Commands::erase(string & input, const string & FileName)
{
	if ("" == FileName)
	{
		printNoOpenedFile();
		return;
	}

	int index = StringCheck::findNumber(input);
	
	if (!StringCheck::isFound(index) || StringCheck::isThereMoreInfo(input))
	{
		printWrongParam();
		return;
	}

	ShapeContainer::getInstance()->eraseShape(index);
}

void Commands::translate(string & input, const string & FileName)
{
	if ("" == FileName)
	{
		printNoOpenedFile();
		return;
	}
	bool shouldAcceptVertical = false;
	bool shouldAcceptHorizontal = false;
	int vertical = StringCheck::findAnyValueFromWord(input, " vertical=", ' ', shouldAcceptVertical);
	int horizontal = StringCheck::findAnyValueFromWord(input, " horizontal=", ' ', shouldAcceptHorizontal);
	int posIndex = input.find("index=");

	if (!shouldAcceptVertical)
	{
		if (!StringCheck::isFound(vertical))
		{
			printWrongParam();
			return;
		}
	}

	if (!shouldAcceptHorizontal)
	{
		if (!StringCheck::isFound(horizontal))
		{
			printWrongParam();
			return;
		}
	}	

	if (StringCheck::isFound(posIndex))
	{
		int index = StringCheck::findValueFromWord(input, "index=", ' ');
		// there should be only 3 words and and after index there must a number;
		if (StringCheck::isThereExcessiveInfo(input, 3) || !StringCheck::isFound(index))
		{
			printWrongParam();
			return;
		}
		ShapeContainer::getInstance()->translateOneShape(vertical, horizontal, index);
	}
	else
	{
		if (StringCheck::isThereExcessiveInfo(input, 2)) // there should be only 2 words;
		{
			printWrongParam();
			return;
		}
		ShapeContainer::getInstance()->translateAllShapes(vertical, horizontal);
	}
}

void Commands::within(string & input, const string & FileName)
{
	if ("" == FileName)
	{
		printNoOpenedFile();
		return;
	}

	string inShape = StringCheck::getFirstWord(input);	

	if ("rectangle" == inShape)
	{
		int x = StringCheck::findNumber(input);		
		int y = StringCheck::findNumber(input);		
		int width = StringCheck::findNumber(input);		
		int height = StringCheck::findNumber(input);			

		// there should be only 4 words - the 4 parameters 
		if (!StringCheck::areAllFound(x, y, width, height) || StringCheck::isThereMoreInfo(input))
		{
			printWrongParam();
			return;
		}

		ShapeContainer::getInstance()->WithinRectangle(x, y, width, height);
	}
	else if ("circle" == inShape)
	{
		int cx = StringCheck::findNumber(input);		
		int cy = StringCheck::findNumber(input);		
		int radius = StringCheck::findNumber(input);		

		// there should be only 3 words - the 3 parameters 
		if (!StringCheck::areAllFound(cx, cy, radius) || StringCheck::isThereMoreInfo(input))
		{
			printWrongParam();
			return;
		}

		ShapeContainer::getInstance()->WithinCircle(cx, cy, radius);
	}
	else
	{
		printWrongCommand();
	}
}

void Commands::welcome()
{
	cout << "Welcome! This is SVG Editor 1.0. ";
	cout << "You can read, create and edit rectangles, circles and lines." << endl;
	cout << "If you need help: type \"> help\"" << endl;
}

void Commands::help()
{
	cout << "______________________________________________________________________________" << endl;
	cout << "The SVG Editor 1.0 support the following commands:" << endl;
	cout << "\"> open\" - requares FileName (without extention, the extention is \"svg\")." << endl;
	cout << "\"> close\" - no parameters." << endl;
	cout << "\"> save\" - no parameters." << endl;
	cout << "\"> saveas\" - requares FileName (without extention, the extention is \"svg\")." << endl;
	cout << "\"> exit\" - no parameters." << endl << endl;

	cout << "\"> print\" - no parameters, prints the figures in the file." << endl;
	cout << "\"> create\" creates a figure, needs parameters:" << endl;
	cout << "   - rectangle <x> <y> <width> <height> (<fill>)" << endl;
	cout << "   - circle <cx> <cy> <radius> (<fill>)" << endl;
	cout << "   - line <x1> <y1> <x2> <y2> <stroke-widht> (<stroke>)" << endl;
	cout << "   The figure will be created only if it is visible!" << endl;
	cout << "\"> erase\" - requires an index." << endl;
	cout << "\"> translate\" - requares parameters:" << endl;
	cout << "   - vertical=<x> horizontal=<y> (index=<z> - optional)" << endl;
	cout << "   A figure is translated only if it will remain visible!" << endl;
	cout << "\"> within\" - print the figures located in the given figure: " << endl;
	cout << "   - rectangle <x> <y> <width> <height> " << endl;
	cout << "   - circle <cx> <cy> <radius> " << endl;
	cout << "______________________________________________________________________________" << endl;
}

bool Commands::exit(const string & input, string& FileName)
{	
	if (StringCheck::isThereMoreInfo(input))
	{
		printWrongParam();
		return false;
	}

	FileName = "";
	ShapeContainer::releaseInstance();
	printExitingProgram();
	return true;
}

void Commands::runProgramme()
{
	welcome();

	string FileName = "";
	string input;

	while (true)
	{
		getline(cin, input);		
		StringCheck::removeIntervalsInTheEnd(input);

		bool isRealCommand = (">" == StringCheck::getFirstWord(input));
		if (false == isRealCommand)
		{
			printWrongCommand();
		}
		else
		{
			string CommandType = StringCheck::getFirstWord(input);


			if ("print" == CommandType)
			{
				print(input, FileName);
			}
			else if ("create" == CommandType)
			{
				create(input, FileName);
			}
			else if ("erase" == CommandType)
			{
				erase(input, FileName);
			}
			else if ("translate" == CommandType)
			{
				translate(input, FileName);
			}
			else if ("within" == CommandType)
			{
				within(input, FileName);
			}
			else if ("open" == CommandType)
			{
				open(input, FileName);
			}
			else if ("close" == CommandType)
			{
				close(input, FileName);
			}
			else if ("save" == CommandType)
			{
				save(input, FileName);
			}
			else if ("saveas" == CommandType)
			{
				saveas(input, FileName);
			}
			else if ("help" == CommandType)
			{
				help();
			}
			else if ("exit" == CommandType)
			{
				if (exit(input, FileName))
				{
					break;
				}								
			}
			else
			{
				printWrongCommand();
			}
		}
	}
}