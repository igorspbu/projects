#include<iostream>
using namespace std;
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	int n = 0;
	cout << "¬ведите число\n";
	cin >> n;
	int a = 1, b = 2, c = 1;
	while (a <= n)
	{
		for (a, b; b < a; ++b)
		{
			if (a % b == 0)
			{
				++c;
			}
		}
		if (c < 2)
		{
			cout << a << endl;
		}
		b = 2;
		c = 1;
		++a;
	}
	return EXIT_SUCCESS;
}