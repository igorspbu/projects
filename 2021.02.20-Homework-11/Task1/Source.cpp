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
	cout << "���������� ��� � int :";
	printBits(i);
	cout << endl;
	cout << "���������� ��� � long :";
	printBits(l);
	cout << endl;
	cout << "���������� ��� � long long :";
	printBits(ll);
	cout << endl;
	cout << "���������� ��� � float :";
	printBits(f);
	cout << endl;
	cout << "���������� ��� � double :";
	printBits(d);
	cout << endl;
	cout << "���������� ��� � long double :";
	printBits(ld);
	cout << endl;
	cout << endl;
	cout << endl;

	cout << "������� �������������� 5 ���� (10, 13, 47, 32 � 6 ) = " << average(5, 10, 13, 47, 32, 6);
	cout << endl;
	return EXIT_SUCCESS;
}