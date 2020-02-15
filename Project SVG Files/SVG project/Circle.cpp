#include "Circle.h"

void Circle::setCentre(const int cx, const int cy)
{
	this->centre.setX(cx);
	this->centre.setY(cy);
}

const Point Circle::getCentre() const
{
	return this->centre;
}

void Circle::setR(const int r)
{
	this->r = r;
}

const int Circle::getR() const
{
	return this->r;
}

void Circle::setFill(const string fill)
{
	this->fill = fill;
}

const string Circle::getFill() const
{
	return this->fill;
}

void Circle::setAll(const int cx, const int cy, const int r, const string fill)
{
	setCentre(cx, cy);
	setR(r);
	setFill(fill);
}

bool Circle::doExist(const int r) const
{
	return (r > 0);
}

bool Circle::isVisible(const int cx, const int cy, const int r) const
{
	Circle newCircle(cx, cy, r, getFill());
	return (newCircle.isWithinRect(0, 0, INT_MAX, INT_MAX));
}

bool Circle::applyParameters(const int cx, const int cy, const int r, const string fill)
{
	if (isVisible(cx, cy, r) && doExist(r))
	{
		setAll(cx, cy, r, fill);
		return true;
	}
	return false;
}

Circle::Circle() : BasicShape("circle")
{
	setAll(10, 10, 5, "blue");	
}

Circle::Circle(const int cx, const int cy, const int r, const string fill) : BasicShape("circle")
{
	setAll(cx, cy, r, fill);
}

Circle::~Circle()
{
}

void Circle::print() const
{
	cout << "circle " << getCentre().getX() << " " << getCentre().getY() << " ";
	cout << getR() << " " << getFill() << endl;
}

void Circle::printInFile(ofstream& myFile) const
{
	myFile << "<" << getName() << " cx=\"";
	myFile << getCentre().getX() << "\" cy=\"" << getCentre().getY();
	myFile << "\" r=\"" << getR();
	myFile << "\" fill=\"" << getFill();
	myFile << "\" />" << endl;
}

bool Circle::getParameters(string & input)
{
	int cx = StringCheck::findNumber(input);
	int cy = StringCheck::findNumber(input);
	int r = StringCheck::findNumber(input);
	string fill = StringCheck::findText(input);

	if (!StringCheck::areAllFound(cx, cy, r))
	{
		return false;
	}	

	if (StringCheck::isThereMoreInfo(input))
	{
		return false;
	}	

	if (applyParameters(cx, cy, r, fill))
	{
		setFill(StringCheck::checkColour(getFill()));
		return true;
	}

	return false;
}

bool Circle::readParameters(const string & row)
{
	int cx = StringCheck::findValueFromWord(row, "cx=\"", '"');
	int cy = StringCheck::findValueFromWord(row, "cy=\"", '"');
	int r = StringCheck::findValueFromWord(row, "r=\"", '"');
	string fill = StringCheck::findInfoFromWord(row, "fill=\"", '"');

	if (!StringCheck::areAllFound(cx, cy, r))
	{
		return false;
	}	

	if (applyParameters(cx, cy, r, fill))
	{
		setFill(StringCheck::checkColour(getFill(), false)); // false to indicate that no message should be printed
		return true;
	}

	return false;
}

bool Circle::translate(int vertical, int horizontal)
{
	int newCx = getCentre().getX() + horizontal;
	int newCy = getCentre().getY() + vertical;
	
	// the circle will be translated only if it will remain visible;
	if (applyParameters(newCx, newCy, getR(), getFill()))
	{
		return true;
	}	
	
	return false;
}

bool Circle::isWithinCircle(int cxCircle, int cyCircle, int rCircle) const
{
	/*
	We will check whether the rCircle is bigger than (or equal) the distance between the centre
	of given circle and the centre of our circle + the radius of our circle;
	*/

	Point centreGivenCircle(cxCircle, cyCircle);
	double d = getCentre().distanceFromPoint(centreGivenCircle);
	bool result = (rCircle >= (getR() + d));

	return result;
}

bool Circle::isWithinRect(int xRect, int yRect, int widthRect, int heightRect) const
{
	/*
	First we must chech whether every vertex of the given rectangle is outside our circle;
	Than we have to see whether the circle intersects the rectangle;
	*/

	Point TopLeftRect(xRect, yRect);
	Point TopRightRect(xRect + widthRect, yRect);
	Point BottomLeftRect(xRect, yRect + heightRect);
	Point BottomRightRect(xRect + widthRect, yRect + heightRect);

	bool isTopLeftInCircle = TopLeftRect.isInCircle(getCentre(), getR());
	bool isTopRightInCircle = TopRightRect.isInCircle(getCentre(), getR());
	bool isBottomLeftInCircle = BottomLeftRect.isInCircle(getCentre(), getR());
	bool isBottomRightInCircle = BottomRightRect.isInCircle(getCentre(), getR());

	bool isThereVertexInCircle = (isTopLeftInCircle || isTopRightInCircle || isBottomLeftInCircle || isBottomRightInCircle);
	bool areAllverticesOutside = !isThereVertexInCircle;

	// conditions which have to be met in order the circle not to intersects the rectangle;

	bool condition1 = ((getCentre().getY() - getR()) >= TopLeftRect.getY());
	bool condition2 = ((getCentre().getY() + getR()) <= BottomRightRect.getY());
	bool condition3 = ((getCentre().getX() - getR()) >= TopLeftRect.getX());
	bool condition4 = ((getCentre().getX() + getR()) <= BottomRightRect.getX());

	/*
	finalCondition = 0 if the circle and rectangle have a point in common;
	finalCondition = 1 if the circle and rectangle do not have a point in common;
	*/
	bool finalCondition = (condition1 && condition2 && condition3 && condition4);

	bool result = (areAllverticesOutside && finalCondition);

	return result;
}
