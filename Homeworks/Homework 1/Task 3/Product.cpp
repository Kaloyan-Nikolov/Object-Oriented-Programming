#include "Product.h"

unsigned int SKU = 0;

void Product::increaseSKU()
{
	SKU++;	
}

void Product::copy(const Product & p)
{
	setCurrentSKU();
	setBrand(p.Brand);
	setModel(p.Model);
	setCategory(p.Category);
	setPrice(p.Price);
	setCount(p.Count);
	setIsLeatherArtificial(p.isLeatherArtificial);
	setCountry(p.Country);
}

void Product::setCurrentSKU()
{		
	increaseSKU();
	this->currentSKU = SKU;	
}

void Product::setDefaultSKU()
{
	this->currentSKU = -1;
}

void Product::copyCurrentSKU(int number)
{
	this->currentSKU = number;	
}

int Product::getCurrentSKU() const
{
	return this->currentSKU;
}

void Product::setBrand(const char * Brand)
{	
	if (Brand == nullptr)
	{
		return;
	}
	delete[] this->Brand;	
	this->Brand = new char[strlen(Brand) + 1];
	strcpy_s(this->Brand, strlen(Brand) + 1, Brand);
}

char * Product::getBrand() const
{
	return this->Brand;
}

void Product::setModel(const char * Model)
{
	if (Model == nullptr)
	{
		return;
	}
	delete[] this->Model;
	this->Model = new char[strlen(Model) + 1];
	strcpy_s(this->Model, strlen(Model) + 1, Model);
}

char * Product::getModel() const
{
	return this->Model;
}

void Product::setCategory(const char symbol)
{	
	if (symbol == 'm')
	{
		this->Category = 'm';
		return;
	}
	else if (symbol == 'f')
	{
		this->Category = 'f';
		return;
	}	
}

char Product::getCategory() const
{
	return this->Category;
}

void Product::setPrice(double Price)
{
	if (Price > 0)
	{
		this->Price = Price;
	}	
}

double Product::getPrice() const
{
	return this->Price;
}

void Product::setCount(int Count)
{	
	if (Count > 0)
	{
		this->Count = Count;
	}
}

int Product::getCount() const
{	
	return this->Count;
}

void Product::setIsLeatherArtificial(bool isLeatherArtificial)
{
	this->isLeatherArtificial = isLeatherArtificial;
}

bool Product::getIsLeatherArtificial() const
{
	return this->isLeatherArtificial;
}

void Product::setCountry(const char * Country)
{
	if (Country == nullptr)
	{
		return;
	}
	delete[] this->Country;
	this->Country = new char[strlen(Country) + 1];
	strcpy_s(this->Country, strlen(Country) + 1, Country);
}

char * Product::getCountry() const
{
	return this->Country;
}

Product::Product()
{	
	setDefaultSKU();
	setBrand("Def brand");
	setModel("Def model");
	setCategory('m');
	setPrice(50);
	setCount(1);
	setIsLeatherArtificial(true);
	setCountry("China");	
}

Product::Product(const char * Brand, const char * Model, char Category, double Price, int Count, bool isLeatherArtificial, const char * Country)
{
	setCurrentSKU();
	setBrand(Brand);
	setModel(Model);
	setCategory(Category);
	setPrice(Price);
	setCount(Count);
	setIsLeatherArtificial(isLeatherArtificial);
	setCountry(Country);
}

Product::Product(const Product & p)
{
	copy(p);
}

Product & Product::operator=(const Product & p)
{
	if (this != &p)
	{		
		copy(p);		
	}

	return *this;
}

void Product::move(const Product & p) // copies the SKU of p;
{
	copyCurrentSKU(p.currentSKU);
	setBrand(p.Brand);
	setModel(p.Model);
	setCategory(p.Category);
	setPrice(p.Price);
	setCount(p.Count);
	setIsLeatherArtificial(p.isLeatherArtificial);
	setCountry(p.Country);
}

void Product::copyWithoutSKU(const Product & p)
{	
	setBrand(p.Brand);
	setModel(p.Model);
	setCategory(p.Category);
	setPrice(p.Price);
	setCount(p.Count);
	setIsLeatherArtificial(p.isLeatherArtificial);
	setCountry(p.Country);
}

void Product::print() const
{	
	std::cout << "SKU:      " << getCurrentSKU() << std::endl;
	std::cout << "Brand:    " << getBrand() << std::endl;
	std::cout << "Model:    " << getModel() << std::endl;
	std::cout << "Category: ";
	if (getCategory() == 'm')
	{
		std::cout << "Male" << std::endl;
	}
	else
	{
		std::cout << "Female" << std::endl;
	}
	std::cout << "Price:    " << getPrice() << std::endl;
	std::cout << "Count:    " << getCount() << std::endl;
	std::cout << "Is the leather artificial: ";
	if (this->isLeatherArtificial == true)
	{
		std::cout << "yes" << std::endl;
	}
	else
	{
		std::cout << "no" << std::endl;
	}
	std::cout << "Country of origin: " << getCountry() << std::endl;
	std::cout << std::endl;
}

Product::~Product()
{
	delete[] this->Brand;
	delete[] this->Model;
	delete[] this->Country;
}
