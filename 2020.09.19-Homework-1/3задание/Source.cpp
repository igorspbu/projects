#include<iostream>
using namespace std;
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Введите сумму цифр \n";
	cin >> n;
	int i = 100, r = 100;
	while (i < 1000)
	{
		int a = i / 100, b = i / 10 % 10, c = i % 10;
		if (a + b + c == n)
		{
			while (r < 1000)
			{
				int d = r / 100, e = r / 10 % 10, f = r % 10;
				if (d + e + f == n)
				{
					cout << a << b << c << d << e << f << endl;
				}
				++r;
			}
			r = 0;
		}
		++i;
	}
	return EXIT_SUCCESS;
}