#include <iostream>
#include "Functions.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	long long a = 0;
	cout << "���������� ���, ������� ����� ����� ��� ��������, ���� � ���� ��������" << endl;
	cout << readLong(a) << endl;

	double b = 0;
	cout << "������, ������� ������� ����� ��� ��������, ���� � ���� ��������" << endl;
	cout << readDouble(b) << endl;

	cout << a << " + " << b << "= " << a + b << endl;
	return 0;
}
