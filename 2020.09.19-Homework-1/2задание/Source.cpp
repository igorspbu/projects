#include<iostream>
using namespace std;
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	int a, b;
	int c;
	cout << "Введите b и a\n";
	cin >> b;
	cin >> a;
	c = 0;
	while (b - (a * c) >= a)
	{
		++c;
	}
	cout << "Неполное частное от деления a на b = " << c;
	return EXIT_SUCCESS;
}