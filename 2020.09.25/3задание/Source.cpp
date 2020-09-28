#include<iostream>
using namespace std;

void expandArr(int*& arr, int& cap, int& count)
{
	cout << "¬ведите числа в массив" << endl;
	while (true)
	{
		int x = 0;
		cin >> x;
		if (x == 0)
			break;
		if (count == cap)
		{
			cap *= 2;
			int* temp = new int[cap];
			for (int i = 0; i < count; ++i)
				temp[i] = arr[i];
			delete[] arr;
			arr = temp;
		}

		arr[count] = x;
		count++;
	}
}


int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	int cap = 10;
	int* arr = new int[cap];
	int count = 0;
	expandArr(arr, cap, count);

	for (int i = 0; i < count - 1; ++i)
	{
		int x = 0;
		
	}
}
