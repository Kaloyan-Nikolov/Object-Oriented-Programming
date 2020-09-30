#pragma once
#include "question.h"
#include "YesNoQuestion.h"
#include "MultipleChoice.h"
#include "OpenQuestion.h"

class Test
{
private:
	std::vector<Question*> questions;
	std::vector<std::string> answers;
	static Test* Instance;

	Test();
	Test(const Test& t);
	Test& operator=(const Test& t);
	~Test();
public:
	static Test* getInstance();
	static void releaseInstance();

	void addQuestion();
	void doTest();
	void gradeTest() const;
};