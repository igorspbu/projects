#include<iostream>
using namespace std;
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	int n = 0, a = 0;
	cout << "¬ведите число\n";
	cin >> n;
	cout << "¬ведите степень\n";
	cin >> a;
	int c = n << a;
	cout << c;
	return EXIT_SUCCESS;
}
