#include<iostream>
using namespace std;
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	int x = 0;
	cout << "������� �������� x\n";
	cin >> x;
	int a = x * x, b = 0;
	b = (a + x) * (a + 1) + 1;
	cout << "�������� ���������- " << b;
	return EXIT_SUCCESS;
}