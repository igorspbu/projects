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
T1 divv(T1 a, T2 b)
{
	return (a / b);
}

template <typename T1, typename T2>
T1 mod(T1 a, T2 b)
{
	if (a < b)
		return a;
	else
	{
		while (a > b)
			a -= b;
		return a;
	}
}

int operationIndex(char operation)
{
	switch (operation)
	{
	case'+':
	{
		return 0;
	}
	case '-':
	{
		return 1;
	}
	case '*':
	{
		return 2;
	}
	case '/':
	{
		return 3;
	}
	case '%':
	{
		return 4;
	}
	cout << "Вы ввели что-то не то " << endl;
	break;
	}
}

template <typename T1, typename T2>
T1 calculate(T1 a, T2 b, T1(*operations[5])(T1, T2){ sum, diff, mult, divv, mod })
{
	return operations[operationIndex(operation)](a, b);
}

int main(int argc, const char* argv[] )
{
	setlocale(LC_ALL, "Russian");

	argv[1] = "--operand1";
	argv[2] = "--operand2";
	argv[3] = "--operator";

	char operation = '0';
	cout << "Введите операцию" << endl;
	cin >> operation;

	for (int i = 0; i < argc; ++i)
	{
		cout << i << argv[i] << endl;
	}

	calculate(34.31, 321, operation);
	return 0;
}