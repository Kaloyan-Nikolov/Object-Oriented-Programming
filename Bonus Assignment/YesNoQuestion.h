#pragma once
#include "question.h"

class YesNoQuestion : public Question
{
private:
	std::string answer;	
	int points;
public:
	void setAnswer(const std::string answer);
	const std::string getAnswer() const;
	void setPoints(const int points);
	const int getPoints() const;

	YesNoQuestion();
	YesNoQuestion(const std::string body, const int points, const std::string answer);

	virtual const std::string ask() const override;
	virtual const int grade(std::string givenAnswer) const override;
};

