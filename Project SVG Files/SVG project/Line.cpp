#include "Line.h"

void Line::setFirstPoint(const int x1, const int y1)
{
	this->firstPoint.setX(x1);
	this->firstPoint.setY(y1);
}

const Point Line::getFirstPoint() const
{
	return this->firstPoint;
}

void Line::setSecondPoint(const int x2, const int y2)
{
	this->secondPoint.setX(x2);
	this->secondPoint.setY(y2);
}

const Point Line::getSecondPoint() const
{
	return this->secondPoint;
}

void Line::setStrokeWidth(const int width)
{
	this->strokeWidth = width;
}

const int Line::getStrokeWidth() const
{
	return this->strokeWidth;
}

void Line::setStroke(const string stroke)
{
	this->stroke = stroke;
}

const string Line::getStroke() const
{
	return this->stroke;
}

void Line::setAll(const int x1, const int y1, const int x2, const int y2, const int width, const string stroke)
{
	setFirstPoint(x1, y1);
	setSecondPoint(x2, y2);	
	setStrokeWidth(width);
	setStroke(stroke);
}

bool Line::doExist(const int x1, const int y1, const int x2, const int y2) const
{
	// we will check whether the two points are diffrent
	// if they are different, the line exists;
	Point first(x1, y1);
	Point second(x2, y2);
	return !(first.isTheSameAs(second));
}

bool Line::isVisible(const int x1, const int y1, const int x2, const int y2) const
{
	Line newLine(x1, y1, x2, y2, getStrokeWidth(), getStroke());
	return  (newLine.isWithinRect(0, 0, INT_MAX, INT_MAX));
}

bool Line::applyParameters(const int x1, const int y1, const int x2, const int y2, const int width, const string stroke)
{
	if (isVisible(x1, y1, x2, y2) && doExist(x1, y1, x2, y2))
	{
		setAll(x1, y1, x2, y2, width, stroke);
		return true;
	}

	return false;
}

Line::Line() : BasicShape("line")
{
	setAll(0, 0, 5, 5, 10, "blue");	
}

Line::Line(const int x1, const int y1, const int x2, const int y2, const int width, const string stroke) :
	BasicShape("line")
{
	setAll(x1, y1, x2, y2, width, stroke);
}

Line::~Line()
{
}

void Line::print() const
{
	cout << "line " << getFirstPoint().getX() << " " << getFirstPoint().getY() << " ";
	cout << getSecondPoint().getX() << " " << getSecondPoint().getY() << " ";
	cout << getStrokeWidth() << " " << getStroke() << endl;
}

void Line::printInFile(ofstream& myFile) const
{
	myFile << "<" << getName() << " x1=\"";
	myFile << getFirstPoint().getX() << "\" y1=\"" << getFirstPoint().getY();
	myFile << "\" x2=\"" << getSecondPoint().getX();
	myFile << "\" y2=\"" << getSecondPoint().getY();
	myFile << "\" stroke-width=\"" << getStrokeWidth();
	myFile << "\" stroke=\"" << getStroke();
	myFile << "\" />" << endl;
}

bool Line::getParameters(string & input)
{
	int x1 = StringCheck::findNumber(input);
	int y1 = StringCheck::findNumber(input);
	int x2 = StringCheck::findNumber(input);
	int y2 = StringCheck::findNumber(input);
	int strokeWidth = StringCheck::findNumber(input);
	string stroke = StringCheck::findText(input);

	if (!StringCheck::areAllFound(x1, y1, x2, y2, strokeWidth))
	{
		return false;
	}

	if (StringCheck::isThereMoreInfo(input))
	{
		return false;
	}	

	if (applyParameters(x1, y1, x2, y2, strokeWidth, stroke))
	{
		setStroke(StringCheck::checkColour(getStroke()));
		return true;
	}
	
	return false;
}

bool Line::readParameters(const string & row)
{
	int x1 = StringCheck::findValueFromWord(row, "x1=\"", '"');
	int y1 = StringCheck::findValueFromWord(row, "y1=\"", '"');
	int x2 = StringCheck::findValueFromWord(row, "x2=\"", '"');
	int y2 = StringCheck::findValueFromWord(row, "y2=\"", '"');
	int strokeWidth = StringCheck::findValueFromWord(row, "stroke-width=\"", '"');
	string stroke = StringCheck::findInfoFromWord(row, "stroke=\"", '"');

	if (!StringCheck::areAllFound(x1, y1, x2, y2, strokeWidth))
	{
		return false;
	}	

	if (applyParameters(x1, y1, x2, y2, strokeWidth, stroke))
	{
		setStroke(StringCheck::checkColour(getStroke(), false)); // false to indicate that no message should be printed
		return true;
	}

	return false;
}

bool Line::translate(int vertical, int horizontal)
{
	int newX1 = getFirstPoint().getX() + horizontal;
	int newY1 = getFirstPoint().getY() + vertical;
	int newX2 = getSecondPoint().getX() + horizontal;
	int newY2 = getSecondPoint().getY() + vertical;

	// the line will be translated only of it will remain visible	
	if (applyParameters(newX1, newY1, newX2, newY2, getStrokeWidth(), getStroke()))
	{		
		return true;
	}
	return false;
}

bool Line::isWithinCircle(int cxCircle, int cyCircle, int rCircle) const
{
	/*
	We will check whether both ends of the line segment are inside the given circle;
	*/

	Point centre(cxCircle, cyCircle);
	bool isFirstPointInCricle = getFirstPoint().isInCircle(centre, rCircle);
	bool isSecondPointInCircle = getSecondPoint().isInCircle(centre, rCircle);

	bool result = (isFirstPointInCricle && isSecondPointInCircle);
	return result;
}

bool Line::isWithinRect(int xRect, int yRect, int widthRect, int heightRect) const
{
	/*
	We will check whether both ends of the line segment are inside the given rectangle;
	*/

	// top left point of given rectangle;
	Point p1(xRect, yRect);
	// bottom right point of given rectangle;
	Point p2(xRect + widthRect, yRect + heightRect);

	bool isFirstPointInRect = getFirstPoint().isInRectangle(p1, p2);
	bool isSecondPointInRect = getSecondPoint().isInRectangle(p1, p2);

	bool result = (isFirstPointInRect && isSecondPointInRect);

	return result;
}
