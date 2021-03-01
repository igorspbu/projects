#include <iostream>
using namespace std;

void printBitsInt(int s)
{
	int bitLength = sizeof(s) * 8;
	for (int i = 0; i < bitLength; ++i)
	{
		unsigned int bit = s;
		bit = bit << i;
		bit = bit >> (bitLength - 1);
		cout << bit;
	}
}

void printBitsLongInt(long long int s)
{
	int bitLength = sizeof(s) * 8;
	for (int i = 0; i < bitLength; ++i)
	{
		unsigned long long int bit = s;
		bit = bit << i;
		bit = bit >> (bitLength - 1);
		cout << bit;
	}
}

void printBits(short s)
{
	int bitlength = sizeof(s) * 8;
	for (int i = 0; i < bitlength; ++i)
	{
		unsigned short bit = s;
		bit = bit << i;
		bit = bit >> (bitlength - 1);
		cout << bit;
	}
}

void printBitslong(long s)
{
	int bitlength = sizeof(s) * 8;
	for (int i = 0; i < bitlength; ++i)
	{
		unsigned short bit = s;
		bit = bit << i;
		bit = bit >> (bitlength - 1);
		cout << bit;
	}
}

void printBits(float s)
{
	void* ptr = &s;
	int a = *(int*)(ptr);
	printBitsInt(a);
}

void printBits(long long s)
{
	void* ptr = &s;
	long long int a = *(long long int*)(ptr);
	printBitsLongInt(a);
}

void printBits(double s)
{
	void* ptr = &s;
	long long int a = *(long long int*)(ptr);
	printBitsLongInt(a);
}

void printBits(long double s)
{
	void* ptr = &s;
	long long int a = *(long long int*)(ptr);
	printBitsLongInt(a);
}

double average(int n, ...)
{
	double sum = 0;
	int N = n;
	for (int* ptr = &n; n > 0; --n)
	{
		sum += *(++ptr);
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
	cout << "int :";
	printBitsInt(i);
	cout << endl;
	cout << "long :";
	printBitslong(l);
	cout << endl;
	cout << "long long :";
	printBits(ll);
	cout << endl;
	cout << "float :";
	printBits(f);
	cout << endl;
	cout << "double :";
	printBits(d);
	cout << endl;
	cout << "long double :";
	printBits(ld);
	cout << endl;
	cout << endl;
	cout << endl;

	cout << "Среднее арифметическое 5 цифр (10, 13, 47, 32 и 6 ) = " << average(5, 10, 13, 47, 32, 6);
	cout << endl;
	return EXIT_SUCCESS;
}