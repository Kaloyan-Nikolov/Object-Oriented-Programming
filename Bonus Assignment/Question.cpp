#include "Question.h"

void Question::setBody(const std::string body)
{
	this->body = body;
}

const std::string Question::getBody() const
{
	return this->body;
}

Question::Question()
{
	setBody("Default question: what day is it? ");	
}

Question::Question(const std::string body)
{
	setBody(body);	
}

void Question::print() const
{
	std::cout << getBody() << std::endl;
}
