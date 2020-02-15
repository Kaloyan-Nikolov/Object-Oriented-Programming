#include "ReadingFromFile.h"

void ReadFromFile::mySwap(int & x, int & y)
{
	int temp = x;
	x = y;
	y = temp;
}

bool ReadFromFile::readFile(string & FileName, string & content)
{
	StringCheck::removeIntervalsInBeginning(FileName);
	ifstream myfile(FileName, std::ios_base::binary);
	if (myfile.fail())
	{
		return false; // Did not open file
	}

	if (myfile.is_open()) {
		string newLine;		
		while (getline(myfile, newLine)) 
		{
			content += newLine;
		}
	}

	myfile.close();
	return true; // Successfully read file
}

bool ReadFromFile::createEmptyFile(string & FileName)
{
	ofstream newFile(FileName);
	if (newFile.fail())
	{		
		return false;
	}	
	newFile.close();
	return true;
}

// returns the smallest number different from -1;
// if all are -1, retunrs -1;
int ReadFromFile::findFirstPosition(int pos1, int pos2, int pos3)
{
	int arr[3] = { pos1, pos2, pos3 };	

	if (arr[1] <= arr[0] && arr[1] <= arr[2])
	{
		mySwap(arr[1], arr[0]);
	}
	else if (arr[2] <= arr[0] && arr[2] <= arr[1])
	{
		mySwap(arr[2], arr[0]);
	}

	if (arr[2] <= arr[1])
	{
		mySwap(arr[2], arr[1]);
	}	

	for (int i = 0; i < 3; i++)
	{
		if (StringCheck::isFound(arr[i]))
		{
			return arr[i];
		}
	}

	return arr[2];
}

// copies information to row from content until /> is found;
// at the end of function, in row is stored enough information to create 1 figure
// (if the information in the file is correct)
string ReadFromFile::info1Shape(string & content, int position)
{
	string row;
	while (true)
	{
		row.push_back(content[position]);
		position++;
		int shouldRowFinish = row.find("/>");
		if (StringCheck::isFound(shouldRowFinish))
		{
			break;
		}
	}

	StringCheck::findRemainingContent(content, position);
	return row;
}