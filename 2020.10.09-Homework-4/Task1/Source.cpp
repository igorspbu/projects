#include<iostream>
#include<clocale>
#include<ctime>
#include"ArrayList.h"

using namespace std;

void printMenu()
{
	cout << "МЕНЮ" << endl;
	cout << "0 - Выход из программы" << endl;
	cout << "1 - Вывести массив на экран" << endl;
	cout << "2 - Добавить элемент" << endl;
	cout << "3 - Добавить элемент в позицию" << endl;
	cout << "4 - Удалить элемент по индексу" << endl;
	cout << "5 - Найти элемент" << endl;
	cout << "6 - Добавить несколько элементов" << endl;
	cout << "7 - Добавить несколько элементов, начиная с некоторой позиции" << endl;
}

void processChoice(ArrayList& a, int choice)
{
	switch (choice)
	{
	case 1:
	{
		a.print();
	}
	break;
	case 2:
	{
		int element = 0;
		cout << "Введите элементы" << endl;
		while (true)
		{
			cin >> element;
			if (element == 0)
				break;
			a.add(element);
		}
	}
	break;
	case 3:
	{
		int index = 0;
		int element = 0;
		cout << "Введите индекс и элемент" << endl;
		cin >> index >> element;
		a.add(index, element);
	}
	break;
	case 4:
	{
		int index = 0;
		cout << "Введите индекс удаляемого элемента" << endl;
		cin >> index;
		a.remove(index);
	}
	break;
	case 5:
	{
		int element = 0;
		cout << "Введите искомый элемент" << endl;
		cin >> element;
		a.indexOf(element);
	}
	break;
	case 6:
	{
		ArrayList list;
		int element = 0;
		cout << "Введите элементы в list" << endl;
		while (true)
		{
			cin >> element;
			if (element == 0)
				break;
			list.add(element);
		}
		a.addAll(list);
	}
	break;
	case 7:
	{
		ArrayList list;
		int index = 0;
		int q = 0;
		cout << "Введите индекс элемента" << endl;
		cin >> index;
		cout << "Введите элементы в массив" << endl;
		while (true)
		{
			cin >> q;
			if (q == 0)
				break;
			list.add(q);
		}
		a.addAll(index, list);
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

	return EXIT_SUCCESS;
}