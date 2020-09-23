#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int n = 0;
	cout << "¬ведите число\n";
	cin >> n;
	int a = 0, b = 1, c = 0;
	a = sqrt(n);
	while (b <= a)
	{
		if (n % b == 0)
		{
			++c;
		}
		++b;
	}
	c = c * 2;
	if (a * a==n)
	{
		c = c - 1;
	}
	cout << c;
	return EXIT_SUCCESS;
}



