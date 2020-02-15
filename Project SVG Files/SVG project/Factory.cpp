#include "Factory.h"

BasicShape * Factory::makeShape(string input)
{
	if ("rectangle" == input)
	{
		return new Rect();
	}
	else if ("circle" == input)
	{
		return new Circle();
	}
	else if ("line" == input)
	{
		return new Line();
	}
	else
	{
		return nullptr;
	}
}
