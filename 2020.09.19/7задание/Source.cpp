#include<iostream>
using namespace std;
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	int n = 0, a = 0, b = 1;
	cout << "¬ведите число\n";
	cin >> n;
	cout << "¬ведите степень\n";
	cin >> a;
	while (a > 0)
	{
		b = b * n;
		--a;
	}
	cout << b << endl;
	return EXIT_SUCCESS;
}
