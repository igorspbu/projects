#include<iostream>
using namespace std;
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	int n = 0;
	cout << "������� �����\n";
	cin >> n;
	int a = 1, b = 1;
	while (a <= n)
	{
		b = b * a;
		++a;
	}
	cout << b << endl;
	return EXIT_SUCCESS;
}
