#pragma once
#include "BasicShape.h"

class Line : public BasicShape
{
private:
	Point firstPoint;
	Point secondPoint;
	int strokeWidth;
	string stroke;

public:
	void setFirstPoint(const int x1, const int y1);
	const Point getFirstPoint() const;
	void setSecondPoint(const int x2, const int y2);
	const Point getSecondPoint() const;
	void setStrokeWidth(const int width);
	const int getStrokeWidth() const;
	void setStroke(const string stroke);
	const string getStroke() const;

	void setAll(const int x1, const int y1, const int x2, const int y2,
		const int width, const string stroke);
	bool doExist(const int x1, const int y1, const int x2, const int y2) const;
	bool isVisible(const int x1, const int y1, const int x2, const int y2) const;
	bool applyParameters(const int x1, const int y1, const int x2, const int y2,
		const int width, const string stroke);

	Line();
	Line(const int x1, const int y1, const int x2, const int y2,
		const int width, const string stroke);
	virtual ~Line();

	virtual void print() const override;
	virtual void printInFile(ofstream& myFile) const override;
	virtual bool getParameters(string & input) override;
	virtual bool readParameters(const string& row) override;
	virtual bool translate(int vertical, int horizontal) override;
	virtual bool isWithinCircle(int cxCircle, int cyCircle, int rCircle) const override;
	virtual bool isWithinRect(int xRect, int yRect, int widthRect, int heightRect) const override;
};