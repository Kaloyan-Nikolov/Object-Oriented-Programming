#pragma once
#include "ReadingFromFile.h"
#include "Factory.h"

class ShapeContainer
{
private:
	static ShapeContainer* Instance;
	vector<BasicShape*> arr;

	ShapeContainer();
	ShapeContainer(const ShapeContainer & shCont);
	ShapeContainer& operator=(const ShapeContainer & shCont);
	~ShapeContainer();

public:
	//function to get the only instance -
	//if such exists it returns it, if not creates one;
	static ShapeContainer* getInstance();
	//function to release the instance when it is not longer needed;
	static void releaseInstance();


	void addShape(BasicShape * shape, bool shouldPrintMessage);

	void eraseShape(int index);

	void printAllShapes() const;
	bool printInFileAllShapes(string& FileName) const;

	void translateAllShapes(int vertical, int horizontal);
	void translateOneShape(int vertical, int horizontal, int index);

	void WithinCircle(int cxCircle, int cyCircle, int rCircle) const;
	void WithinRectangle(int xRect, int yRect, int widthRect, int heightRect) const;

	bool readAllShapes(string& FileName, bool & isCreated);

};
