#pragma once
#include "BasicShape.h"

using namespace std;

class ReadFromFile
{
private:

	static void mySwap(int &x, int &y);
public:

	static bool readFile(string & FileName, string & content);
	static bool createEmptyFile(string& FileName);
	static int findFirstPosition(int pos1, int pos2, int pos3);
	static string info1Shape(string & content, int position);	
};