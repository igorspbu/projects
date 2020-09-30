#include <iostream>
using namespace std;

void expandArr(int*& a, int& cap)
{
	int cap1 = cap * 2;
	int* temp = new int[cap1];
	for (int i = 0; i < cap; ++i)
	{
		temp[i] = a[i];
	}
	delete[]a;
	a = temp;
	cap = cap1;
}

void Menu()
{
	cout << "0 - Выход из программы" << endl;
	cout << "1 - Добавить число в массив" << endl;
	cout << "2 - Вывести массив на экран" << endl;
	cout << "3 - Найти номер максимального элемента массива" << endl;
	cout << "4 - Найти минимальный элемент массива" << endl;
	cout << "5 - Посчитать сумму элементов массива" << endl;
	cout << "6 - Вывести массив в обратном порядке" << endl;
	cout << "Введите операцию" << endl;
}

void addNumber(int*& a, int& cap, int& count, int x)
{
	if (count == cap)
	{
		expandArr(a, cap);
	}

	a[count] = x;
	count++;
}

void allNumber(int* a, int count)
{
	for (int i = 0; i < count; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl << endl;
}

void cinArr(int*& a, int& cap, int& count)
{
	while (true)
	{
		int x = 0;
		cin >> x;
		if (x == 0)
			break;
		if (count == cap)
		{
			expandArr(a, cap);
		}
		a[count] = x;
		++count;
	}
}

int numMaxEl(int* a, int count)
{
	int max = 0;
	int i = 0;
	for (i, count; i < count; ++i)
	{
		if (a[i] >a [max])
		{
			max = i;
		}
	}
	return max;
}

int minEl(int* a, int count)
{
	int min = 0;
	min = a[0];
	for (int i = 0; i < count; ++i)
	{
		if (a[i] < min)
		{
			min == a[i];
		}
	}
	return min;
}

int sum(int* a, int count)
{
	int sum = 0;
	for (int i = 0; i < count; ++i)
	{
		sum = sum + a[i];
	}
	return sum;
}

void reverse(int* a, int count)
{
	for (int i = count - 1; i >= 0; --i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

void cinMenu(int*& a, int& cap, int& count)
{
	int choice = -1;

	while (choice != 0)
	{
		Menu();
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << "Введите число" << endl;
			int x = 0;
			cin >> x;
			addNumber(a, cap, count, x);
			break;
		}
		case 2:
		{
			allNumber(a, count);
			break;
		}
		case 3:
		{
			cout << "Номер наибольшего элемента - " << numMaxEl(a, count);
			cout << endl;
			break;
		}
		case 4:
		{
			cout << "Минимальный элемент- " << minEl(a, count);
			cout << endl;
			break;
		}
		case 5:
		{
			cout << "Сумма элементов - " << sum(a, count);
			cout << endl;
			break;
		}
		case 6:
		{
			reverse(a, count);
			break;
		}
		}
	}
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");

	int cap = 10;
	int* a = new int[cap];
	int count = 0;

	cout << "Введите элементы массива " << endl;
	cinArr(a, cap, count);
	cinMenu(a, cap, count);

	delete[]a;
	return EXIT_SUCCESS;
}