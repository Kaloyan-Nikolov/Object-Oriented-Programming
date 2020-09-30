#include "YesNoQuestion.h"

void YesNoQuestion::setAnswer(const std::string answer)
{
	this->answer = answer;
}

const std::string YesNoQuestion::getAnswer() const
{
	return this->answer;
}

void YesNoQuestion::setPoints(const int points)
{
	this->points = points;
}

const int YesNoQuestion::getPoints() const
{
	return this->points;
}

YesNoQuestion::YesNoQuestion()
{
	setAnswer("yes");
	setPoints(5);
}

YesNoQuestion::YesNoQuestion(const std::string body, const int points, const std::string answer) :
	Question(body)
{
	if (answer == "yes" || answer == "no")
	{
		setAnswer(answer);
	}
	else
	{
		setAnswer("yes");
		std::cout << "Default answer yes was set! " << std::endl;
	}

	setPoints(points);
}

const std::string YesNoQuestion::ask() const
{
	std::cout << "Yes/No question: " << std::endl;
	print();
	std::string input;
	std::getline(std::cin, input);
	string givenAnswer = StringCheck::getFirstWord(input);
	return givenAnswer;
}

const int YesNoQuestion::grade(std::string givenAnswer) const
{
	if (givenAnswer != "yes" && givenAnswer != "no")
	{
		givenAnswer = "yes";
	}

	if (givenAnswer == getAnswer())
	{
		return getPoints();
	}
	else
	{
		return 0;
	}
}