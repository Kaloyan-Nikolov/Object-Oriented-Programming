#include "Test.h"

int main()
{
	Test::getInstance()->addQuestion();
	Test::getInstance()->addQuestion();
	//Test::getInstance()->addQuestion();
	//Test::getInstance()->addQuestion();
	//Test::getInstance()->addQuestion();

	std::cout << std::endl << std::endl;
	std::cout << "Let's do the test:" << std::endl;
	Test::getInstance()->doTest();

	std::cout << std::endl << std::endl;
	std::cout << "Grading test..." << std::endl;
	Test::getInstance()->gradeTest();

	std::cin.ignore();
	std::cin.get();
	return 0;
}