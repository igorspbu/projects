#include <iostream>
using namespace std;

void printBits(int)
{
	cout << sizeof(int) * 8 << endl;
}

void printBits(long)
{
	cout << sizeof(long) * 8 << endl;
}

void printBits(long long)
{
	cout << sizeof(long long) * 8 << endl;
}

void printBits(float)
{
	cout << sizeof(float) * 8 << endl;
}

void printBits(double)
{
	cout << sizeof(double) * 8 << endl;
}

void printBits(long double)
{
	cout << sizeof(long double) * 8 << endl;
}

double average(int n, ...)
{
	double sum = 0;
	int N = n;
	for (int* ptr = &n; n > 0; --n)
	{
		sum +=*(++ptr);
	}
	return (sum / N);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int i = 1;
	long l = 1;
	long long ll = 1;
	float f = 1;
	double d = 1;
	long double ld = 1;
	cout << "Количество бит в int :";
	printBits(i);
	cout << endl;
	cout << "Количество бит в long :";
	printBits(l);
	cout << endl;
	cout << "Количество бит в long long :";
	printBits(ll);
	cout << endl;
	cout << "Количество бит в float :";
	printBits(f);
	cout << endl;
	cout << "Количестов бит в double :";
	printBits(d);
	cout << endl;
	cout << "Количество бит в long double :";
	printBits(ld);
	cout << endl;
	cout << endl;
	cout << endl;

	cout << "Среднее арифметическое 5 цифр (10, 13, 47, 32 и 6 ) = " << average(5, 10, 13, 47, 32, 6);
	cout << endl;
	return EXIT_SUCCESS;
}