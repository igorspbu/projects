#include <iostream>
using namespace std;

void expandArr(int*& a, int& cap, int& count)
{
	cout << "Введите числа в массив" << endl;
	while (true)
	{
		int x = 0;
		;
		cin >> x;
		if (x == 0)
			break;
		if (count == cap)
		{
			cap *= 2;
			int* temp = new int[cap];
			for (int i = 0; i < count; ++i)
				temp[i] = a[i];
			delete[] a;
			a = temp;
		}

		a[count] = x;
		count++;
	}
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

void addNumber(int*& a, int& cap, int& count)
{

	int x = 0;
	cin >> x;
	if (count == cap)
	{
		cap++;
		int* temp = new int[cap];
		for (int i = 0; i < count; ++i)
			temp[i] = a[i];
		delete[] a;
		a = temp;
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

void numMaxEl(int* a, int count)
{
	int max = a[0];
	int i = 0;
	for (i,count;i < count; ++i)
	{
		if (a[i]>max)
		{
			max=i;
		}
	}
	cout << "Номер наибольшего элемента - " << max << endl;
}

void minEl(int* a, int count)
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
	cout << "Наименьший элемент - " << min << endl;
}

void sum(int* a, int count)
{
	int sum = 0;
	for (int i = 0; i < count; ++i)
	{
		sum = sum + a[i];
	}
	cout << "Сумма элементов - " << sum << endl;
}

void reverse(int* a, int count)
{
	for (int i = count - 1; i >= 0; --i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	int cap = 10;
	int* a = new int[cap];
	int count = 0;
	expandArr(a, cap, count);
	int choice = -1;

	while (choice!=0)
	{
		Menu();
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			addNumber(a, cap, count);
			break;
		}
		case 2:
		{
			allNumber(a, count);
			break;
		}
		case 3:
		{
			numMaxEl(a, count);
			break;
		}
		case 4:
		{
			minEl(a, count);
			break;
		}
		case 5:
		{
			sum(a, count);
			break;
		}
		case 6:
		{
			reverse(a, count);
			break;
		}
		if (choice == 0)
		{
			exit;
		}
		}
	}
	delete[]a;
	return EXIT_SUCCESS;

}




