#include<iostream>
#include<cmath>
#include<string>
#include<clocale>
#include <iomanip>
using namespace std;

int nValid(int n)
{
	if (n > 0 && n < 10)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int xValid(double x)
{
	if (x >= -1 && x <=1)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

long double fact(int N)
{
	if (N < 0) return 0;
	if (N == 0) return 1;
	else return N * fact(N - 1);
}

double readDouble(double& number)
{
	string dabudidabuday;
	getline(cin, dabudidabuday);
	double d = 0.0;
	int point = 0;
	int blum = 0;
	int sign = 0;
	for (int i = 0; i < dabudidabuday.size(); ++i)
	{
		if (dabudidabuday[i] == '.')
		{
			++point;
		}
	}
	for (int i = 0; i < dabudidabuday.size(); ++i)
	{
		if (point == 1)
		{
			if (dabudidabuday[0] == '-')
			{
				sign = 1;
			}
			if (dabudidabuday[i] == '.')
			{
				blum = i;
			}
			if (dabudidabuday[i] == '\0')
			{
				return 10000;
			}
			if ((dabudidabuday[i] >= 33 && dabudidabuday[i] <= 44) || (dabudidabuday[i] >= 58 && dabudidabuday[i] <= 64) || (dabudidabuday[i] >= 91 && dabudidabuday[i] <= 96) || (dabudidabuday[i] >= 123 && dabudidabuday[i] <= 127) || (dabudidabuday[i] == 47))
			{
				return 100000;
			}
			if ((dabudidabuday[i] >= 65 && dabudidabuday[i] <= 90) || (dabudidabuday[i] >= 97 && dabudidabuday[i] <= 122))
			{
				return 10000;
			}
			if ((dabudidabuday[i] >= 128 && dabudidabuday[i] <= 175) || (dabudidabuday[i] >= 224 && dabudidabuday[i] <= 241))
			{
				return 10000;
			}
			if (dabudidabuday[i] >= 48 && dabudidabuday[i] <= 57)
			{
				d = 10 * d + dabudidabuday[i] - '0';
			}
		}
		else
		{
			return 10000;
		}
	}
	if (dabudidabuday.size() - blum < 10)
	{
		number = d;
		number /= pow(10, dabudidabuday.size() - blum - 1);
		if (sign == 1)
		{
			number = number * (-1);
		}
		return number;
	}
	else
	{
		return 100000;
	}
}

int readInt(int& number)
{
	string ll;
	int kokoko = 0;
	getline(cin, ll);
	for (int i = 0; i < ll.size(); ++i)
	{
		if (ll[i] == '\0')
		{
			return 0;
		}
		if ((ll[i] >= 33 && ll[i] <= 47) || (ll[i] >= 58 && ll[i] <= 64) || (ll[i] >= 91 && ll[i] <= 96) || (ll[i] >= 123 && ll[i] <= 127))
		{
			return 0;
		}
		if ((ll[i] >= 65 && ll[i] <= 90) || (ll[i] >= 97 && ll[i] <= 122))
		{
			return 0;
		}
		if (ll[i] >= 48 && ll[i] <= 57)
		{
			kokoko = 10 * kokoko + ll[i] - '0';
		}
		if ((ll[i] >= 128 && ll[i] <= 175) || (ll[i] >= 224 && ll[i] <= 241))
		{
			return 10000;
		}
	}
	number = kokoko;
	return number;
}

double myFunction(double x, int n)
{
	double num = 0.0;
	int denominator = 0;
	for (int i = 0; i <= n; ++i)
	{
		denominator = fact(2 * i);
		x = pow(x, (2 * i));
		num += x / denominator;
	}
	return num;
}

double ch(double x)
{
    double num = 0.0;
	num = (exp(x) + exp(-1 * x));
	num = num / 2;
	return num;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	double x = 0.0;
	int n = 0;
    cout << "¬ведите дробный X" << endl;
    x = readDouble(x);
	cout << "¬ведите число цифр после зап€той n " << endl;
	n = readInt(n);
	if (xValid(x) == 1 || nValid(n) == 1)
	{
		return -1;
	}
	double sum = myFunction(x, n);
	double sum1 = ch(x);
	cout << fixed << setprecision(9) << sum << endl;
	cout << fixed << setprecision(9) << sum1 << endl;

	return EXIT_SUCCESS;
}