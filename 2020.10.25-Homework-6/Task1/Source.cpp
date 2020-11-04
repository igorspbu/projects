#include <iostream>
#include<clocale>
#include<ctime>
#include "ArrayList.h"

using namespace std;

void printMenu()
{
	cout << "МЕНЮ" << endl;
	cout << "0 - Выход из программы" << endl;
	cout << "1 - добавить элемент, введенный с клавиатуры" << endl;
	cout << "2 - вывести массив" << endl;
	cout << "3 - проверить, является ли массив симметричным" << endl;
	cout << "4 - циклически сдвинуть массив на n элементов. n>0 - сдвиг вправо, n<0 - сдвиг влево" << endl;
	cout << "5 - проверить, может ли массив стать симметричным, если из него удалить один элемент" << endl;
}

void processChoice(ArrayList& a, int choice)
{
	switch (choice)
	{
	case 1:
	{
		int element = 1;
		cout << "Введите элемент" << endl;
		while (element != 0)
		{
			a.add(element);
			cin >> element;
		}
	}
	break;
	case 2:
	{
		cout << a.toString() << endl;
	}
	break;
	case 3:
	{
		int point = 0;
		for (int i = 0; i < (a.length()) / 2; ++i)
		{
			if (a.get(i) == a.get(a.length() - i - 1))
			{
				++point;
			}
		}
		if (point == a.length() / 2)
		{
			cout << "Массив симметричен" << endl;
		}
		else
		{
			cout << "Массив не симметричен" << endl;
		}
	}
	break;
	case 4:
	{
		int n = 0;
		cout << "Введите кол-во элементов" << endl;
		cin >> n;

		n *= -1;
		if (n < 0)
		{
			n = n + a.length();
		}
		if (n > a.length()-1)
		{
			break;
		}
		for (int i = 0; i < n / 2; ++i)
		{
			a.swap(i, n - 1 - i);
		}
		for (int i = n; i < ((a.length() + n) / 2); ++i)
		{
			a.swap(i, a.length() + n - 1 - i);
		}
		cout << a.toString() << endl;
	}
	break;
	case 5:
	{
		int p = 0;
		for (int i = 0; i < a.length() / 2; ++i)
		{
			if (a.get(i) != a.get(a.length() - 1 - i))
			{
				for (i; i < a.length() / 2; ++i)
				{
					if (a.get(i + 1) != a.get(a.length() - 1 - i) && a.get(i) != a.get(a.length() - 2 - i))
					{
						p = -1;
					}
				}
			}
		}
		if (p == -1)
		{
			cout << "Массив не симметричен" << endl;
		}
		else
		{
			cout << "Массив симметричен" << endl;
		}
	}
	break;
	}
}

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");

	ArrayList a;

	int choice = 0;
	do
	{
		system("cls");
		printMenu();
		cin >> choice;
		processChoice(a, choice);
		system("pause");
	} while (choice != 0);

	return 0;
}