#pragma once
#include "question.h"
#include "Answer.h"

class MultipleChoice : public Question, public Answer
{
private:
	std::vector<Answer> possibleAnswers;

public:
	MultipleChoice();
	MultipleChoice(const std::string body);

	virtual const std::string ask() const override;
	virtual const int grade(std::string givenAnswer) const override;
};