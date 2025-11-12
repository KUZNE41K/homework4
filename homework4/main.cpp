#include <iostream>
#include <Windows.h>

int* dynamicMemoryAllocation(int size)
{
	int* arr = new int[size];
	return arr;
}

void initializeArray(int*arr,int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = 0;
	}

}
void printDynamicArray(int*arr,int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i];
	}
}


void endElement(int*&arr,int& size,int Newvalue)
{
	int* NewArr = new int[size + 1];

	for (int i = 0; i < size; i++)
	{
		NewArr[i] = arr[i];
	}

	NewArr[size] = Newvalue;
	delete[]arr;
	arr = NewArr;
	size++;
}
void deleteDynamicArray(int* arr)
{
	delete[]arr;
}

void addElement(int*& arr, int& size)
{
	int index;
	int add;
	int* NewArr = new int[size + 1];

	for (int i = 0; i < size; i++)
	{
		NewArr[i] = arr[i];
	}
	while (true)
	{
		std::cout << "\n¬ведите индекс по которому будет вставлен элемент ";
		std::cin >> index;
		if (index < 0 || index >= size)
		{
			std::cout << "ќшибка введите еще раз ";
		}
		else
		{
			break;
		}
	}
	std::cout << "\n¬ведите число которое будет добавл€ть ";
	std::cin >> add;

	NewArr[index] = add;
	deleteDynamicArray(arr);
	arr = NewArr;
}

void deleteElement(int*& arr, int& size)
{
	int index;
	int* NewArr = new int[size - 1];

	while (true)
	{
		std::cout << "\n¬ведите индекс по которому будет удален элемент ";
		std::cin >> index;
		if (index < 0 || index >= size)
		{
			std::cout << "ќшибка введите еще раз ";
		}
		else
		{ 
			break; 
		}
	}
	
	for (int i = 0, j=0; i < size; i++)
	{
		if (i!=index)
		{
			NewArr[j] = arr[i];
			j++;
		}
	}
	deleteDynamicArray(arr);
	arr = NewArr;
	size--;
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i];
	}
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int size = 5;

	int* arr = dynamicMemoryAllocation(size);

	initializeArray(arr,size);

	endElement(arr, size,4);

	printDynamicArray(arr, size);

	addElement(arr, size);

	printDynamicArray(arr, size);

	deleteElement(arr, size);

	deleteDynamicArray(arr);
	return 0;
}