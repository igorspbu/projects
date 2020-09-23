#include<iostream>
using namespace std;
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	int n = 0;
	cout << "¬ведите число\n";
	cin >> n;
	int a = 0, b = 2, c = 0;
	a = pow(n, 1 / 2.0);
	a = ceil(a);
	while (b <= a)
	{
		if (n % b == 0)
		{
			++c;
		}
		++b;
	}

	c = c * 2 + 1;
	cout << c;
	return EXIT_SUCCESS;
}



