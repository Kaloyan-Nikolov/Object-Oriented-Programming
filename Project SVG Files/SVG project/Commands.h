#pragma once
#include "ShapeContainer.h"

class Commands
{
private:
	static void printWrongCommand();
	static void printWrongParam();
	static void printNoOpenedFile();
	static void printFileNotOpen();
	static void printAlreadyOpened(const string & FileName);
	static void printFileClosed(const string & FileName);
	static void printFileNotSaved();
	static void printWrongFileName();
	static void printSuccessfullyOpened(const string & FileName);
	static void printSuccessfullyCreated(const string & FileName);
	static void printSuccessfullySaved(const string & FileName);
	static void printExitingProgram();

	static void open(const string & input, string & FileName);
	static void close(const string & input, string & FileName);
	static void save(const string & input, string& FileName);
	static void saveas(string & input, string& FileName);
	static void print(const string & input, const string & FileName);
	static void create(string & input, const string & FileName);
	static void erase(string & input, const string & FileName);
	static void translate(string & input, const string & FileName);
	static void within(string & input, const string & FileName);
	static void welcome();
	static void help();
	static bool exit(const string & input, string& FileName);

public:
	static void runProgramme();
};