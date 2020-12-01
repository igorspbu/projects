#include <iostream>
#include "Functions.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	long long a = 0;
	cout << "Дорожайшая моя, введите целое число без пробелов, букв и иных символов" << endl;
	cout << readLong(a) << endl;

	double b = 0;
	cout << "Родная, введите дробное число без пробелов, букв и иных символов" << endl;
	cout << readDouble(b) << endl;

	cout << a << " + " << b << "= " << a + b << endl;
	return 0;
}
