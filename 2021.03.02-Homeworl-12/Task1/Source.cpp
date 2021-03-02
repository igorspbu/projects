#include <iostream>
using namespace std;

template <typename T1, typename T2>
T1 sum(T1 a, T2 b)
{
	return (a + b);
}

template <typename T1, typename T2>
T1 diff(T1 a, T2 b)
{
	return (a - b);
}

template <typename T1, typename T2>
T1 mult(T1 a, T2 b)
{
	return (a * b);
}

template <typename T1, typename T2>
T1 div(T1 a, T2 b)
{
	return (a / b);
}

template <typename T1, typename T2>
T1 mod(T1 a, T2 b)
{
	return (a % b);
}

int operationIndex(char operation)
{
	int q = 0;
	switch (operation)
	{
	case'+':
	{
		return q = 1;
	}
	case '-':
	{
		return q = 2;
	}
	case '*':
	{
		return q = 3;
	}
	case '/':
	{
		return q = 4;
	}
	case '%':
	{
		return q = 5;
	}
	cout << "Вы ввели что-то не то " << endl;
	break;
	}
}

template <typename T1, typename T2>
T1 calculate(T1 a, T2 b, char operation)
{
	int q = operationIndex(operation);
	if (q == 1)
	{
		cout << a << ' ' << operation << b << ' = ' << sum(a, b) << endl;
	}
	if (q == 2)
	{
		cout << a << ' ' << operation << b << ' = ' << diff(a, b) << endl;
	}
	if (q == 3)
	{
		cout << a << ' ' << operation << b << ' = ' << mult(a, b) << endl;
	}
	if (q == 4)
	{
		cout << a << ' ' << operation << b << ' = ' << div(a, b) << endl;
	}
	if (q == 5)
	{
		cout << a << ' ' << operation << b << ' = ' << mod(a, b) << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	char operation = '0';
	cout << "Введите операцию" << endl;
	cin >> operation;
	calculate(34, 21, operation);
	return 0;
}