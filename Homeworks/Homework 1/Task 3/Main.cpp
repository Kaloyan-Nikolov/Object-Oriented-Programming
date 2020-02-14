#include "Store.h"
using namespace std;

int main()
{
	cout << "Menu: " << endl;
	cout << "A \t Add new product" << endl;
	cout << "X \t Delete product" << endl;
	cout << "C \t Change product" << endl;
	cout << "D \t Display product" << endl;
	cout << "Q \t Quit" << endl;

	char symbol;
	Store FirstStore;

	const int MAX_SIZE = 100;

	while (true)
	{
		cout << endl;
		cout << "Waiting for command: " << endl;

		std::cin >> symbol;

		if (symbol == 'A')
		{
			cout << "Please enter the characteristics of the product: " << endl;
			char Brand[MAX_SIZE];
			cout << "Brand: ";
			std::cin >> Brand;

			char Model[MAX_SIZE];
			cout << "Model: ";
			std::cin >> Model;

			char Category;
			cout << "Category(m for male and f for female): ";
			while (true)
			{
				std::cin >> Category;
				if (Category == 'm' || Category == 'f')
				{
					break;
				}
				else
				{
					std::cout << "Error! You have to enter 'm' or 'f'!" << std::endl;
				}
			}
			double price;
			cout << "Price: ";
			std::cin >> price;

			int count;
			cout << "Count: ";
			std::cin >> count;

			int isLeatherArtificial;
			cout << "Is the leather artificial(1 for YES and 0 for NO): ";
			while (true)
			{
				std::cin >> isLeatherArtificial;
				if (isLeatherArtificial == 0 || isLeatherArtificial == 1)
				{
					break;
				}
				else 
				{
					std::cout << "Error! You have to enter 0 or 1!" << std::endl;
				}
			}
			char Country[MAX_SIZE];
			cout << "Country: ";
			std::cin >> Country;

			Product Pr1(Brand, Model, Category, price, count, isLeatherArtificial, Country);
			FirstStore.add(Pr1);
		}
		else if (symbol == 'X')
		{
			cout << "Enter the position of the product which you want to delete: ";
			unsigned int position;
			std::cin >> position;
			FirstStore.remove(position);
		}
		else if(symbol == 'C')
		{
			cout << "Enter the position of the product which you want to change: ";
			unsigned int position;
			std::cin >> position;

			cout << "Please enter the characteristics of the product: " << endl;
			char Brand[MAX_SIZE];
			cout << "Brand: ";
			std::cin >> Brand;

			char Model[MAX_SIZE];
			cout << "Model: ";
			std::cin >> Model;

			char Category;
			cout << "Category(m for male and f for female): ";
			while (true)
			{
				std::cin >> Category;
				if (Category == 'm' || Category == 'f')
				{
					break;
				}
				else
				{
					std::cout << "Error! You have to enter 'm' or 'f'!" << std::endl;
				}
			}
			double price;
			cout << "Price: ";
			std::cin >> price;

			int count;
			cout << "Count: ";
			std::cin >> count;

			int isLeatherArtificial;
			cout << "Is the leather artificial(1 for YES and 0 for NO): ";
			while (true)
			{
				std::cin >> isLeatherArtificial;
				if (isLeatherArtificial == 0 || isLeatherArtificial == 1)
				{
					break;
				}
				else
				{
					std::cout << "Error! You have to enter 0 or 1!" << std::endl;
				}
			}
			char Country[MAX_SIZE];
			cout << "Country: ";
			std::cin >> Country;

			Product Pr1(Brand, Model, Category, price, count, isLeatherArtificial, Country);
			FirstStore.change(position, Pr1);
		}
		else if (symbol == 'D')
		{
			FirstStore.printStore();
		}
		else if (symbol == 'Q')
		{
			cout << "You have closed the programme." << endl;
			break;
		}
	}	

	int x = 0;
	cin >> x;
	return 0;
}
