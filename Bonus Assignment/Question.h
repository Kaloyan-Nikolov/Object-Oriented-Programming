#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "StringCheck.h"

class Question
{
private:
	std::string body;	
public:
	void setBody(const std::string body);
	const std::string getBody() const;	

	Question();
	Question(const std::string body);

	virtual const std::string ask() const = 0;
	virtual const int grade(std::string givenAnswer) const = 0;
	void print() const;
};