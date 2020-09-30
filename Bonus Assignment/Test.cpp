#include "Test.h"

Test * Test::Instance = nullptr;


Test::Test()
{
}

Test::Test(const Test & t)
{
}

Test & Test::operator=(const Test & t)
{
	return *this;
}

Test::~Test()
{
	unsigned int size = questions.size();
	for (int i = 0; i < size; i++)
	{
		delete questions[i];
	}
}

Test * Test::getInstance()
{
	if (nullptr == Instance)
	{
		Instance = new Test();
	}

	return Instance;
}

void Test::releaseInstance()
{
	if (nullptr != Instance)
	{
		delete Instance;
		Instance = nullptr;
	}
}

void Test::addQuestion()
{
	std::cout << "Enter the type of question you want to add!" << std::endl;
	std::cout << "1 for yes/no question, 2 for multiple choice and 3 for open question" << std::endl;
	string input;
	getline(cin, input);
	string type = StringCheck::getFirstWord(input);

	if (type == "1")
	{
		std::cout << "body: ";
		std::string body;		
		std::getline(std::cin, body);

		std::cout << "points: ";
		getline(cin, input);
		int points = StringCheck::findNumber(input);
		
		std::cout << "answer: ";
		getline(cin, input);
		std::string answer = StringCheck::getFirstWord(input);		

		YesNoQuestion* q1 = new YesNoQuestion(body, points, answer);
		Question *qPtr = q1;
		questions.push_back(qPtr);

	}
	else if (type == "2")
	{
		std::cout << "body: ";
		std::string body;		
		std::getline(std::cin, body);

		MultipleChoice* q1 = new MultipleChoice(body);
		Question *qPtr = q1;
		questions.push_back(qPtr);
	}
	else if (type == "3")
	{
		std::cout << "body: ";
		std::string body;		
		std::getline(std::cin, body);

		std::cout << "points: ";
		getline(cin, input);
		int points = StringCheck::findNumber(input);

		OpenQuestion* q1 = new OpenQuestion(body, points);
		Question *qPtr = q1;
		questions.push_back(qPtr);
	}
}

void Test::doTest()
{
	unsigned int size = questions.size();
	if (size == 0)
	{
		std::cout << "No questions!" << std::endl;
	}

	std::string tempAnswer;
	for (unsigned int i = 0; i < size; i++)
	{
		tempAnswer = questions[i]->ask();
		answers.push_back(tempAnswer);
	}
}

void Test::gradeTest() const
{
	unsigned int size = questions.size();
	if (size == 0)
	{
		std::cout << "No questions!" << std::endl;
	}

	int overAllPoints = 0;
	for (unsigned int i = 0; i < size; i++)
	{
		int newPoints = questions[i]->grade(answers[i]);
		overAllPoints += newPoints;
	}
	std::cout << "_____________________________________________________" << endl;
	std::cout << "received points: " << overAllPoints << std::endl;
}
