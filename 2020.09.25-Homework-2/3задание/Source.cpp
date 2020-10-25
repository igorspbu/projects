#include<iostream>
using namespace std;

void expand(int*& arr, int& cap)
{
	int cap1 = cap * 2;
	int* temp = new int[cap1];
	for (int i = 0; i < cap; ++i)
	{
		temp[i] = arr[i];
	}
	delete[]arr;
	arr = temp;
	cap = cap1;
}

void cinArr(int*& arr, int& cap, int& count)
{
	while (true)
	{
		int x = 0;
		cin >> x;
		if (x == 0)
		{
			break;
		}
		if (count >= cap)
		{
			expand(arr, cap);
		}
		arr[count] = x;
		++count;
	}
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	int cap = 10;
	int* arr = new int[cap];
	int count = 0;

	cout << "Введите числа в массив" << endl;
	cinArr(arr, cap, count);

	int a = 1;
	int sum = 0;
	for (int i = 0; i < count; ++i)
	{
		int c = 0;
		for (int b = i; b >= 0; --b)
		{
			c = arr[i];
			c = c * arr[b];
		}
		cout << c << endl;
		a = a * c;
		sum = sum + a;
	}
	float ans = 0;
	ans = sum / count;

	cout << "Среднее арифметическое факториалов последовательности чисел равняется " << endl << ans << endl;

	delete[]arr;
	return EXIT_SUCCESS;
}
