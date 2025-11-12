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


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int size = 5;

	int* arr = dynamicMemoryAllocation(size);
	initializeArray(arr,size);
	endElement(arr, size,4);
	printDynamicArray(arr, size);
	deleteDynamicArray(arr);
	


	return 0;
}