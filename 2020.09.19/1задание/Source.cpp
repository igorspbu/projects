#include<iostream>
using namespace std;
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	int x;
	cout << "������� �������� x\n";
	cin >> x;
	int b;
	int a = x * x;
	int c = b / x;
	int b = a * a;
	int d = b + c + a + x + 1;
	cout << "�������� ���������- " << d;

	return EXIT_SUCCESS;
}