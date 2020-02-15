#include "ShapeContainer.h"

ShapeContainer * ShapeContainer::Instance = nullptr;

ShapeContainer::ShapeContainer()
{	
}

ShapeContainer::ShapeContainer(const ShapeContainer & shCont)
{
}

ShapeContainer & ShapeContainer::operator=(const ShapeContainer & shCont)
{
	return *this;
}

ShapeContainer::~ShapeContainer()
{
	unsigned int size = arr.size();
	for (unsigned int i = 0; i < size; i++)
	{
		delete arr[i];
	}
}

ShapeContainer * ShapeContainer::getInstance()
{
	if (nullptr == Instance)
	{
		Instance = new ShapeContainer();
	}

	return Instance;

}

void ShapeContainer::releaseInstance()
{
	if (nullptr != Instance)
	{
		delete Instance;
		Instance = nullptr;
	}
}

void ShapeContainer::addShape(BasicShape * shape, bool shouldPrintMessage)
{
	this->arr.push_back(shape);
	if (shouldPrintMessage)
	{
		cout << "Successfully created " << arr[arr.size() - 1]->getName() << "(" << arr.size() << ")" << endl;
	}
}

void ShapeContainer::eraseShape(int index)
{
	if (0 == arr.size())
	{
		cerr << "Error! No shapes entered!" << endl;
		return;
	}

	// if the user wants to erase the first shape he writes 1, not 0;
	int realIndex = index - 1;
	if (realIndex < 0 || realIndex >= arr.size())
	{
		cerr << "Error! Invalid index!";
		cerr << " There is no figure number " << index << "!" << endl;
		return;
	}

	cout << "Erased a " << arr[realIndex]->getName() << "(" << index << ")" << endl;

	delete arr[realIndex];
	arr.erase(arr.begin() + realIndex);
}

void ShapeContainer::printAllShapes() const
{
	unsigned int size = arr.size();

	if (0 == size)
	{
		cerr << "Error! No shapes found!" << endl;
		return;
	}

	for (unsigned int i = 0; i < size; i++)
	{
		cout << (i + 1) << ". ";
		arr[i]->print();
	}
}

bool ShapeContainer::printInFileAllShapes(string& FileName) const
{
	StringCheck::removeIntervalsInBeginning(FileName);
	ofstream myFile(FileName);	
	if (myFile.fail())
	{		
		return false;
	}

	myFile << "<?xml version=\"1.0\" standalone=\"no\"?>" << endl;
	myFile << "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\"" << endl;
	myFile << "  \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">" << endl;
	myFile << "<svg>" << endl;

	unsigned int size = arr.size();
	for (unsigned int i = 0; i < size; i++)
	{
		arr[i]->printInFile(myFile);
	}

	myFile << "</svg>" << endl;
	myFile.close();

	return true;
}

void ShapeContainer::translateAllShapes(int vertical, int horizontal)
{
	unsigned int size = arr.size();

	if (0 == size)
	{
		cerr << "Error! No shapes found!" << endl;
		return;
	}

	unsigned int counter = 0;
	for (unsigned int i = 0; i < size; i++)
	{
		if (arr[i]->translate(vertical, horizontal))
		{
			counter++;
		}
	}

	if (size == counter)
	{
		cout << "Translated all figures" << endl;
	}	
	else if (0 == counter)
	{
		cout << "No figures have been translated!" << endl;
	}
	else
	{
		cout << "Figures have been translated!" << endl;
	}
}

void ShapeContainer::translateOneShape(int vertical, int horizontal, int index)
{
	unsigned int size = arr.size();

	if (0 == size)
	{
		cerr << "Error! No shapes entered!" << endl;
		return;
	}

	// if the user wants to translate the first shape he writes 1, not 0;
	int realIndex = index - 1;
	if (realIndex < 0 || realIndex >= size)
	{
		cerr << "Error! Invalid index!";
		cerr << " There is no figure number " << index << "!" << endl;
		return;
	}
	
	if (arr[realIndex]->translate(vertical, horizontal))
	{
		cout << "Translated a " << arr[realIndex]->getName() << "(" << index << ")" << endl;
	}
	else
	{
		cout << arr[realIndex]->getName() << "(" << index << ")";
		cout << " was not translated as it would have stopped being visible!" << endl;
	}
}

void ShapeContainer::WithinCircle(int cxCircle, int cyCircle, int rCircle) const
{
	unsigned int size = arr.size();

	if (0 == size)
	{
		cerr << "Error! No shapes found!" << endl;
		return;
	}

	int counter = 0;
	bool isContained = false;

	for (unsigned int i = 0; i < size; i++)
	{
		isContained = arr[i]->isWithinCircle(cxCircle, cyCircle, rCircle);
		if (true == isContained)
		{
			counter++;
			cout << counter << ". ";
			arr[i]->print();
		}
	}

	if (0 == counter)
	{		
		cout << "No figures are located within circle " << cxCircle << " " << cyCircle << " " << rCircle << endl;
	}
}

void ShapeContainer::WithinRectangle(int xRect, int yRect, int widthRect, int heightRect) const
{
	unsigned int size = arr.size();

	if (0 == size)
	{
		cerr << "Error! No shapes found!" << endl;
		return;
	}

	int counter = 0;
	bool isContained = false;

	for (unsigned int i = 0; i < size; i++)
	{
		isContained = arr[i]->isWithinRect(xRect, yRect, widthRect, heightRect);
		if (isContained)
		{
			counter++;
			cout << counter << ". ";
			arr[i]->print();
		}
	}

	if (0 == counter)
	{		
		cout << "No figures are located within rectangle " << xRect << " ";
		cout << yRect << " " << widthRect << " " << heightRect << endl;
	}
}


bool ShapeContainer::readAllShapes(string& FileName, bool & isCreated)
{
	string content;

	if (!ReadFromFile::readFile(FileName, content)) // did not open file
	{
		if (ReadFromFile::createEmptyFile(FileName))
		{
			isCreated = true;
		}
		else
		{
			isCreated = false;
		}
		return false;
	}

	int position1;
	int position2;
	int position3;
	string newShapeCharacteristics;

	vector<string> readShapes;
	// the vector will contain the rows with information about the figures.	

	for (int i = 0; true; i++)
	{
		position1 = content.find("<rect");
		position2 = content.find("<circle");
		position3 = content.find("<line");

		int firstPos = ReadFromFile::findFirstPosition(position1, position2, position3);
		if (StringCheck::isFound(firstPos))
		{
			newShapeCharacteristics = ReadFromFile::info1Shape(content, firstPos);
			readShapes.push_back(newShapeCharacteristics);
		}
		else
		{
			break;			
		}
	}

	unsigned int size = readShapes.size();

	//we have to create a shape with the information in each row (in each string of our vector)	
	for (unsigned int i = 0; i < size; i++)
	{
		string type = StringCheck::getFirstWord((readShapes[i]));
		type.erase(type.begin()); // remove '<'
		if (type == "rect")
		{
			type = "rectangle";
		}

		BasicShape* newShape = Factory::makeShape(type);

		if (nullptr != newShape)
		{
			if (newShape->readParameters(readShapes[i]))
			{
				getInstance()->addShape(newShape, false); // no message should be printed				
			}
		}
	}

	return true;
}
