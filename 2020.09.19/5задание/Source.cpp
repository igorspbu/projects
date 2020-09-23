#include<iostream>
using namespace std;
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	int n = 0;
	cout << "¬ведите число\n";
	cin >> n;
	int a = 1, b = 0;
	while (a <= n)
	{
		for (; a <= n; ++a)
		{
			if (n % a == 0)
			{
				++b;
			}
		}

		++a;
	}
	cout << b;
	return EXIT_SUCCESS;
}