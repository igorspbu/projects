#include<iostream>
using namespace std;
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	int a, b;
	int c;
	cout << "������� b � a\n";
	cin >> b;
	cin >> a;
	c = 0;
	while (b - (a * c) >= a)
	{
		++c;
	}
	cout << "�������� ������� �� ������� a �� b = " << c;
	return EXIT_SUCCESS;
}