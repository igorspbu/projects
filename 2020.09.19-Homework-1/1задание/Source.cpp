#include<iostream>
using namespace std;
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	int x = 0;
	cout << "Введите значение x\n";
	cin >> x;
	int a = x * x, b = 0;
	b = (a + x) * (a + 1) + 1;
	cout << "Значение уравнения- " << b;
	return EXIT_SUCCESS;
}