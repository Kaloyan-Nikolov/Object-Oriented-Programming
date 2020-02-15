#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class StringCheck
{	
public:
	static const string checkColour(const string & input, bool shouldPrintMessage = true);
	static bool isNumber(string &input, bool &isNegative);
	static bool isNotTooBig(const string & strNumber);
	static bool isFound(int a);
	static bool areAllFound(int a, int b, int c = 0, int d = 0, int e = 0);
	static bool isThereMoreInfo(const string &input);
	static bool isThereExcessiveInfo(const string &input, int numberWords);
	static void removeIntervalsInBeginning(string & input);
	static void removeIntervalsInTheEnd(string & input);
	static bool isRealFileName(const string & input);
	static void findRemainingContent(string & content, int position);

	static const string findInfoFromWord(string row, string searchedInfo, char until);
	static const int findValueFromWord(string row, string searchedInfo, char until);
	static const int findAnyValueFromWord(string row, string searchedInfo, char until, bool & shouldAccept);

	static const string getFirstWord(string & input);
	static const string findText(string & input);
	static const int findNumber(string & input);
};
