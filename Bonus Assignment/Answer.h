#pragma once
#include <iostream>
#include <string>

class Answer
{
private:
	std::string answerBody;
	bool isCorrect;
	int points;	

public:
	void setAnswerBody(const std::string answer);
	const std::string getAnswerBody() const;
	void setIsCorrect(const bool isCorrect);
	const bool getIsCorrect() const;	
	void setPoints(const int points);
	const int getPoitns() const;

	Answer();
	Answer(const std::string answer, const bool isCorrect, const int points);

};