#pragma once
#include <iostream>

// Sneakers

extern unsigned int SKU;

class Product
{
private:
	int currentSKU; // unique for every instance
	char* Brand = nullptr; 
	char* Model = nullptr;
	char Category; // 'm'for male and 'f' for female
	double Price;
	int Count;
	bool isLeatherArtificial;
	char* Country = nullptr; // the country the sneakers are made

	void increaseSKU();
	void copy(const Product& p); // for the code used in both copy constructor and operator=
public:
	
	void setCurrentSKU();
	void setDefaultSKU();
	void copyCurrentSKU(int number);
	int getCurrentSKU()const;

	void setBrand(const char* Brand);
	char* getBrand()const;

	void setModel(const char* Model);
	char* getModel()const;

	void setCategory(const char symbol);
	char getCategory() const;

	void setPrice(double Price);
	double getPrice()const;

	void setCount(int Count);
	int getCount()const;

	void setIsLeatherArtificial(bool isLeatherArtificial);
	bool getIsLeatherArtificial() const;

	void setCountry(const char* Country);
	char* getCountry()const;

	Product();
	Product(const char* Brand, const char* Model, char Category, double price, int count, bool isLeatherArtificial, const char* Country);
	Product(const Product& p); // receives a new SKU;
	Product& operator=(const Product& p); // receives a new SKU;

	void move(const Product& p); // copies the SKU of p;
	void copyWithoutSKU(const Product & p); // the SKU is not changed;
	void print() const;

	~Product();	
};