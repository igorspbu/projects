#include <iostream>
#include <list>
#include <cstdlib>
#include <string>

using namespace std;

struct Subscriber
{
	string phonenumber, name, address;
};

ostream& operator << (ostream& st, Subscriber x)
{
	return st << x.phonenumber << ' ' << x.name << ' ' << x.address << endl;
}

istream& operator >>(istream& st, Subscriber& x)
{
	st >> x.phonenumber >> x.name >> x.address;
	return st;
}

ostream& operator<<(ostream& st, list<Subscriber> l)
{
	list<Subscriber>::iterator i;
	for (i = l.begin(); i != l.end(); ++i)
	{
		st << *i << endl;
	}
	return st;
}

istream& operator>>(istream& st, list<Subscriber>& l)
{
	Subscriber x;
	while (st >> x)
	{
		l.push_back(x);
	}
	return st;
}

void menu()
{
	cout << "Чтобы добавить абонента, введите 1\n" << "Чтобы удалить абонента по номеру, введите 2\n" << "Чтобы распечатать имя и адрес абонента по номеру телефона, введите 3\n" << "Чтобы выйти из программы, введите 4" << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian"); 
	list<Subscriber> l;
	cout << "Введите данные (Ctrl Z - конец ввода)" << endl;
	cin >> l;
	cout << l;
	cin.clear();
	int introduced = 0;
	while (introduced != 4)
	{
		menu();
		cin >> introduced;
		if (introduced == 1)
		{
			Subscriber x;
			cout << "Введите данные" << endl;
			cin >> x;
			l.push_back(x);
			cout << "Данные обработаны" << endl << "Список абонентов:" << endl;
			cout << l;
		}
		if (introduced == 2)
		{
			string s;
			cout << "Введите номер" << endl;
			cin >> s;
			list<Subscriber>::iterator i;
			for (i = l.begin(); i != l.end(); ++i)
			{
				if ((*i).phonenumber == s)
				{
					l.erase(i);
					break;
				}
			}
			cout << "Данные обработаны:" << endl;
			cout << l;
		}
		if (introduced == 3)
		{
			string s;
			cout << "Введите номер" << endl;
			cin >> s;
			list<Subscriber>::iterator i;
			for (i = l.begin(); i != l.end(); ++i)
			{
				if ((*i).phonenumber == s)
				{
					cout << "Адрес абонента: " << (*i).address << endl << "Имя абонента: " << (*i).name << endl;
					break;
				}
			}
		}
	}
	/*Данные
		89163801085
		Igor
		Petergof
		89859243528
		Yuriy
		Zelenograd
		89851331266
		Olga
		Zelenograg
		89161335567
		Galina
		
		*/

	return EXIT_SUCCESS;
}
