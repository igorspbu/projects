#include<iostream>
using namespace std;
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	int a = 0, n = 0;
	int c = 0, d = 0;
	cout << "������� �����\n";
	cin >> n;
	cout << "������� �������\n";
	cin >> a;
	c = n << a;
	c = -c;
	d = ~c;
	cout << d;
	return EXIT_SUCCESS;
}
