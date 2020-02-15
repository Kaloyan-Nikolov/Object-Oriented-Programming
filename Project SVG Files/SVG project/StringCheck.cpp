#include "StringCheck.h"

const int NOT_FOUND = -1;

const string StringCheck::checkColour(const string & input, bool shouldPrintMessage)
{
	string colour = input;
	vector<string> possibleColours = { "aliceblue", "azure", "coral", "cyan", "darkgray", "darkmagenta",
		"darkred", "deeppink", "goldenrod", "grey", "indigo", "lightcoral", "lightgreen", "lightseagreen" ,
		"lightsteelblue", "mediumblue", "midnightblue", "plum", "rosybrown", "sandybrown",
		"silver", "tan", "turquoise", "whitesmoke", "antiquewhite", "beige", "blue" ,
		"cornflowerblue", "darkblue", "darkgreen", "darkolivegreen", "darksalmon", "deepskyblue",
		"firebrick", "gray", "ivory", "lawngreen", "lightcyan", "lightgrey", "lightskyblue" ,
		"lightyellow", "magenta", "mediumspringgreen", "navy", "orange", "palegreen", "peachpuff" ,
		"powderblue", "royalblue", "seagreen", "skyblue", "snow", "teal", "violet", "yellow",
		"aqua", "blueviolet", "darkcyan", "darkgrey", "darkorange", "darkseagreen", "darkturquoise" ,
		"green", "hotpink", "lightpink", "lime", "maroon", "mediumpurple", "mediumturquoise" ,
		"paleturquoise", "peru", "purple", "springgreen", "wheat", "yellowgreen", "aquamarine" ,
		"black", "brown", "chocolate", "darkgoldenrod", "darkviolet", "forestgreen", "gold" ,
		"greenyellow", "indianred", "lavender", "lightblue", "lightgray", "lightsalmon", "limegreen" ,
		"mediumaquamarine", "mediumseagreen", "mediumvioletred", "olive", "orchid", "pink", "palevioletred" ,
		"red", "salmon", "tomato", "white" };


	unsigned int size = possibleColours.size();
	for (unsigned int i = 0; i < size; i++)
	{
		if (possibleColours[i] == colour)
		{
			return colour;
		}
	}

	colour = "blue";
	if (shouldPrintMessage)
	{
		cerr << "Colour was not recognized! Default colour blue was set!" << endl;
	}
	return colour;
}


bool StringCheck::isNumber(string & input, bool &isNegative)
{
	isNegative = false;
	if ('+' == input[0])
	{
		input.erase(input.begin());		
	}
	else if ('-' == input[0])
	{
		input.erase(input.begin());
		isNegative = true;
	}

	return (NOT_FOUND == input.find_first_not_of("0123456789")); 
}

bool StringCheck::isNotTooBig(const string & strNumber)
{
	// we should not accept numbers with more than 9 digits
	if ("" == strNumber)
	{
		return false;
	}

	return (strNumber.size() <= 9);
}

bool StringCheck::isFound(int a)
{
	return (NOT_FOUND != a);
}

bool StringCheck::areAllFound(int a, int b, int c, int d, int e)
{
	bool areAandBok = (NOT_FOUND != a) && (NOT_FOUND != b); // a,b,c,d,e are changed to positive before this check;
	bool areCandDok = (NOT_FOUND != c) && (NOT_FOUND != d);
	bool isEok = (NOT_FOUND != e);
	return (areAandBok && areCandDok && isEok);
}

bool StringCheck::isThereMoreInfo(const string & input)
{
	return (NOT_FOUND != input.find_first_not_of(" "));
}

// we check whether the number of words is numberWords;
bool StringCheck::isThereExcessiveInfo(const string & input, int numberWords)
{
	string content = input;
	string word;
	for (int i = 0; i < numberWords; i++)
	{
		word = getFirstWord(content);
	}

	if ("" != content)
	{
		return true;
	}

	return false;
}

void StringCheck::removeIntervalsInBeginning(string & input)
{
	while ("" != input && ' ' == input[0])
	{
		input.erase(input.begin());
	}
}

void StringCheck::removeIntervalsInTheEnd(string & input)
{
	// if "" !=input is not true the other condition: ' ' == input.back() is not checked at all;
	// if the condition in the while was: ' ' == input.back() && "" != input, we would have problem
	// because we can try to check last element of empty string.
	while ("" != input && ' ' == input.back())
	{
		input.pop_back();		
	}
}

bool StringCheck::isRealFileName(const string & input)
{
	if ("" == input)
	{
		return false;
	}

	int positionLastSlash = input.find_last_of("\\");

	if (!isFound(positionLastSlash))
	{
		return (NOT_FOUND == input.find_first_of("/?!:*\"',<>|")); // true if there is no "/?!:*\"',<>|"
	}
	string FileName(input, positionLastSlash + 1);	
	if ("" == FileName)
	{
		return false;
	}
	return (NOT_FOUND == FileName.find_first_of("/?!:*\"',<>|"));
}

void StringCheck::findRemainingContent(string & content, int position)
{
	string newContent(content, position);
	content = newContent;
}

// we find the substring from row which is between the end of searchedInfo and the char until;
const string StringCheck::findInfoFromWord(string row, string searchedInfo, char until)
{
	string info;
	int position = row.find(searchedInfo);
	if (!isFound(position))
	{
		return info; // empty string
	}
	unsigned int size = searchedInfo.size();
	for (int i = position + size; (row[i] != until) && (row[i] != 0); i++)
	{
		info.push_back(row[i]);
	}
	return info;
}

// if possible returns the number from the string returned by findInfoFromWord;
const int StringCheck::findValueFromWord(string row, string searchedInfo, char until)
{
	string str = findInfoFromWord(row, searchedInfo, until);
	int result = NOT_FOUND;
	bool isNegative;
	if (StringCheck::isNumber(str, isNegative) && isNotTooBig(str))
	{
		result = stoi(str);
		// always return positive number because we have removed the sign;			
	}

	return result;
}

const int StringCheck::findAnyValueFromWord(string row, string searchedInfo, char until, bool & shouldAccept)
{
	string str = findInfoFromWord(row, searchedInfo, until);
	int result = NOT_FOUND;
	bool isNegative;
	if (StringCheck::isNumber(str, isNegative) && isNotTooBig(str))
	{
		result = stoi(str);
		shouldAccept = true;
		// always return positive number because we have removed the sign;	
		if (isNegative)
		{			
			result *= -1; // adds the sign			
		}
	}

	return result;
}

// returns the first word from input and removes it from input;
const string StringCheck::getFirstWord(string & input)
{
	removeIntervalsInBeginning(input);
	// now we are sure that our string does not start with intervals	
	int position = input.find(" ");
	string foundWord(input, 0, position); // copies the characters before the first ' ';	
	if (isFound(position))
	{		
		findRemainingContent(input, position);	
	}
	else
	{
		input = "";
	}
	return foundWord;
}

const string StringCheck::findText(string & input)
{
	string result = getFirstWord(input);
	return result;
}

// if possible returns the number from the string returned by findText;
const int StringCheck::findNumber(string & input)
{
	string strNumber = findText(input);
	int result = NOT_FOUND;
	bool isNEgative = false;	
	if (isNumber(strNumber, isNEgative) && isNotTooBig(strNumber))
	{
		result = stoi(strNumber);
		// always return positive number because we have removed the sign;		
	}
	return result;
}
