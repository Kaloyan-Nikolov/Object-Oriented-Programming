#include "OpenQuestion.h"

void OpenQuestion::setMaxPoints(const int points)
{
	this->MaxPoints = points;
}

const int OpenQuestion::getMaxPoints() const
{
	return this->MaxPoints;
}

OpenQuestion::OpenQuestion()
{
	setMaxPoints(10);
}

OpenQuestion::OpenQuestion(std::string body, const int points) : Question(body)
{
	setMaxPoints(points);
}

const std::string OpenQuestion::ask() const
{
	std::cout << "Open question: " << std::endl;
	print();
	std::string givenAnswer;	
	std::getline(std::cin, givenAnswer);
	return givenAnswer;
}

const int OpenQuestion::grade(std::string givenAnswer) const
{
	print();
	std::cout << "Given answer: " << std::endl;
	std::cout << givenAnswer << std::endl;
	std::cout << "Write in % the grade of the question!" << std::endl;
	
	std::cout << "grade: ";
	string input;
	getline(cin, input);
	int grade = StringCheck::findNumber(input);	
	return (grade * 0.01 * getMaxPoints());
}
