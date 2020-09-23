#include<iostream>
using namespace std;
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	int x;
	cout << "Введите значение x\n";
	cin >> x;
	int a, b, c, d;
	int a = x * x;
	int b = a * a;
	int c = b / x;
	int d = b + c + a + x + 1;
	cout << "Значение уравнения- " << d;

	return EXIT_SUCCESS;
}