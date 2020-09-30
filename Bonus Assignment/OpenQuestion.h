#pragma once
#include "question.h"

class OpenQuestion : public Question
{
private:
	int MaxPoints;
public:
	void setMaxPoints(const int points);
	const int getMaxPoints() const;

	OpenQuestion();
	OpenQuestion(std::string body, const int points);

	virtual const std::string ask() const override;
	virtual const int grade(std::string givenAnswer) const override;
};