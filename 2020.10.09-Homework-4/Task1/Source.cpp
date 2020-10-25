#include<iostream>
#include<clocale>
#include<ctime>
#include"ArrayList.h"

using namespace std;

void printMenu()
{
	cout << "����" << endl;
	cout << "0 - ����� �� ���������" << endl;
	cout << "1 - ������� ������ �� �����" << endl;
	cout << "2 - �������� �������" << endl;
	cout << "3 - �������� ������� � �������" << endl;
	cout << "4 - ������� ������� �� �������" << endl;
	cout << "5 - ����� �������" << endl;
	cout << "6 - �������� ��������� ���������" << endl;
	cout << "7 - �������� ��������� ���������, ������� � ��������� �������" << endl;
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
		cout << "������� ��������" << endl;
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
		cout << "������� ������ � �������" << endl;
		cin >> index >> element;
		a.add(index, element);
	}
	break;
	case 4:
	{
		int index = 0;
		cout << "������� ������ ���������� ��������" << endl;
		cin >> index;
		a.remove(index);
	}
	break;
	case 5:
	{
		int element = 0;
		cout << "������� ������� �������" << endl;
		cin >> element;
		a.indexOf(element);
	}
	break;
	case 6:
	{
		ArrayList list;
		int element = 0;
		cout << "������� �������� � list" << endl;
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
		cout << "������� ������ ��������" << endl;
		cin >> index;
		cout << "������� �������� � ������" << endl;
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