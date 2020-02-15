#include "Rect.h"

void Rect::setTopLeftPoint(const int x, const int y)
{
	this->topLeftPoint.setX(x);
	this->topLeftPoint.setY(y);
}

const Point Rect::getTopLeftPoint() const
{
	return this->topLeftPoint;
}

void Rect::setWidth(const int width)
{
	this->width = width;
}

const int Rect::getWidth() const
{
	return this->width;
}

void Rect::setHeight(const int height)
{
	this->height = height;
}

const int Rect::getHeight() const
{
	return this->height;
}

void Rect::setFill(const string fill)
{
	this->fill = fill;
}

const string Rect::getFill() const
{
	return this->fill;
}

void Rect::setAll(const int x, const int y, const int width, const int height, const string fill)
{
	setTopLeftPoint(x, y);	
	setWidth(width);
	setHeight(height);
	setFill(fill);
}

bool Rect::doExist(const int width, const int height) const
{
	return (width > 0) && (height > 0);
}

bool Rect::isVisible(const int x, const int y) const
{
	Rect newRect(x, y, getWidth(), getHeight(), getFill());
	return (newRect.isWithinRect(0, 0, INT_MAX, INT_MAX));
}

bool Rect::applyParameters(const int x, const int y, const int width, const int height, const string fill)
{
	if (isVisible(x, y) && doExist(width, height))
	{
		setAll(x, y, width, height, fill);
		return true;
	}

	return false;
}

Rect::Rect() : BasicShape("rectangle")
{
	setAll(0, 0, 10, 5, "blue");
}

Rect::Rect(const int x, const int y, const int width, const int height, const string fill) :
	BasicShape("rectangle")
{
	setAll(x, y, width, height, fill);
}

Rect::~Rect()
{
}

const Point Rect::getTopRightPoint() const
{
	Point TopRightP(getTopLeftPoint().getX() + getWidth(), getTopLeftPoint().getY());
	return TopRightP;
}

const Point Rect::getBottomLeftPoint() const
{
	Point BottomLeft(getTopLeftPoint().getX(), getTopLeftPoint().getY() + getHeight());
	return BottomLeft;
}

const Point Rect::getBottomRightPoint() const
{
	Point BottomRight(getTopLeftPoint().getX() + getWidth(), getTopLeftPoint().getY() + getHeight());
	return BottomRight;
}

void Rect::print() const
{
	cout << "rectangle " << getTopLeftPoint().getX() << " " << getTopLeftPoint().getY() << " ";
	cout << getWidth() << " " << getHeight() << " " << getFill() << endl;
}

void Rect::printInFile(ofstream& myFile) const
{
	myFile << "<rect" << " x=\"";
	myFile << getTopLeftPoint().getX() << "\" y=\"" << getTopLeftPoint().getY();
	myFile << "\" width=\"" << getWidth();
	myFile << "\" height=\"" << getHeight();
	myFile << "\" fill=\"" << getFill();
	myFile << "\" />" << endl;
}

bool Rect::getParameters(string & input)
{
	int x = StringCheck::findNumber(input);
	int y = StringCheck::findNumber(input);
	int width = StringCheck::findNumber(input);
	int height = StringCheck::findNumber(input);
	string fill = StringCheck::findText(input);

	if (!StringCheck::areAllFound(x, y, width, height))
	{
		return false;
	}

	if (StringCheck::isThereMoreInfo(input))
	{
		return false;
	}	

	if (applyParameters(x, y, width, height, fill))
	{
		setFill(StringCheck::checkColour(getFill()));
		return true;
	}

	return false;
}

bool Rect::readParameters(const string & row)
{
	int x = StringCheck::findValueFromWord(row, "x=\"", '"');
	int y = StringCheck::findValueFromWord(row, "y=\"", '"');
	int width = StringCheck::findValueFromWord(row, "width=\"", '"');
	int height = StringCheck::findValueFromWord(row, "height=\"", '"');
	string fill = StringCheck::findInfoFromWord(row, "fill=\"", '"');

	if (!StringCheck::areAllFound(x, y, width, height))
	{
		return false;
	}	

	if (applyParameters(x, y, width, height, fill))
	{
		setFill(StringCheck::checkColour(getFill(), false)); // false to indicate that no message should be printed
		return true;
	}

	return false;
}

bool Rect::translate(int vertical, int horizontal)
{
	int newX = getTopLeftPoint().getX() + horizontal;
	int newY = getTopLeftPoint().getY() + vertical;

	// the rectangle will be translated only if it will remain visible	
	if(applyParameters(newX, newY, getWidth(), getHeight(), getFill()))
	{		
		return true;
	}
	return false;
}

bool Rect::isWithinCircle(int cxCircle, int cyCircle, int rCircle) const
{
	/*
	We will check whether every vertex of the rectangle is inside the given circle;
	*/

	Point centre(cxCircle, cyCircle);
	bool isTopLeftInCircle = getTopLeftPoint().isInCircle(centre, rCircle);
	bool isTopRightInCircle = getTopRightPoint().isInCircle(centre, rCircle);
	bool isBottomLeftInCircle = getBottomLeftPoint().isInCircle(centre, rCircle);
	bool isBottomRightInCircle = getBottomRightPoint().isInCircle(centre, rCircle);

	bool result = (isTopLeftInCircle && isTopRightInCircle && isBottomLeftInCircle && isBottomRightInCircle);

	return result;
}

bool Rect::isWithinRect(int xRect, int yRect, int widthRect, int heightRect) const
{
	/*
	We will check whether every vertex of the rectangle is inside the given rectangle;
	That is why we have to know the 4 vertices of our rectangle and the TopLeft and
	BottomRight point of the rectangle in which our rectangle must be in;
	*/

	// top left point of given rectangle;
	Point p1(xRect, yRect);
	// bottom right point of given rectangle;
	Point p2(xRect + widthRect, yRect + heightRect);

	bool isTopLeftInRect = getTopLeftPoint().isInRectangle(p1, p2);
	bool isTopRightInRect = getTopRightPoint().isInRectangle(p1, p2);
	bool isBottomLeftInRect = getBottomLeftPoint().isInRectangle(p1, p2);
	bool isBottomRightInRect = getBottomRightPoint().isInRectangle(p1, p2);

	bool result = (isTopLeftInRect && isTopRightInRect && isBottomLeftInRect && isBottomRightInRect);

	return result;
}