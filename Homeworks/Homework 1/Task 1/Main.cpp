#include "IntStack.h"

using namespace std;

IntStack sortStack(const IntStack &a)
{
	IntStack Sort(a);	

	//selection sort
	for (int i = 0; i <= Sort.getTop() - 1; i++)
	{
		int smallestElement = Sort.arr[i];
		int indexSmallestElement = i;

		for (int j = i + 1; j <= Sort.getTop(); j++)
		{
			if (smallestElement > Sort.arr[j])
			{
				smallestElement = Sort.arr[j];
				indexSmallestElement = j;
			}
		}

		int temp = Sort.arr[i];
		Sort.arr[i] = smallestElement;
		Sort.arr[indexSmallestElement] = temp;
	}	

	return Sort;
}

int main()
{
	IntStack Stack1;

	int n;
	cout << "How many numbers do you want to add in the stack?" << endl;
	cin >> n;

	int number;
	for (int i = 1; i <= n; i++)
	{
		cout << "number #" << i << " : ";
		cin >> number;
		Stack1.push(number);
	}

	Stack1.print();

	IntStack Stack2 = sortStack(Stack1);

	Stack2.print();	

	int x;
	cin >> x;
	return 0;
}
