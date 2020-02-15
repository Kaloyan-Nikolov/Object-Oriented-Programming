#pragma once
#include "Rect.h"
#include "Circle.h"
#include "Line.h"

class Factory
{
public:
	static BasicShape* makeShape(string input);
};
