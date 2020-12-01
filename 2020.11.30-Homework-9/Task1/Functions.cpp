#include "Functions.h"
#include<iostream>
#include<string>
using namespace std;

void resolveError(int errorCode)
{
	string output[10] = { "����� ������","����� ������","����� �����","����� �� ������� ����� ��� �� ���� �����" };
	int answer = 0;
	answer = rand() % 2;
	if (answer == 0)
	{
		cout << "��������, ��� ��������� ������� ����������, ����������, ��������� ����, ���� ��, �������������� ���, " << output[errorCode] << ", � ��� �����������." << endl;
	}
	if (answer == 1)
	{
		cout << "��, �����, �������������� ���, ������� ������ ����� ������ �����. ��� ���, ����� ��� ������ ����� ��� ���, ���� ��, �����������, " << output[errorCode] << ", � ��� �����������" << endl;
	}
}

int readLong(long long& number)
{
	string ll;
	long long kokoko = 0;
	getline(cin, ll);
	for (int i = 0; i < ll.size(); ++i)
	{
		if (ll[i] == '\0')
		{
			resolveError(0);
			return 0;
		}
		if ((ll[i] >= 33 && ll[i] <= 47) || (ll[i] >= 58 && ll[i] <= 64) || (ll[i] >= 91 && ll[i] <= 96) || (ll[i] >= 123 && ll[i] <= 127))
		{
			resolveError(1);
			return 0;
		}
		if ((ll[i] >= 65 && ll[i] <= 90) || (ll[i] >= 97 && ll[i] <= 122))
		{
			resolveError(2);
			return 0;
		}
		if (ll[i]>= 48 && ll[i] <= 57)
		{
			kokoko = 10 * kokoko + ll[i] - '0';
		}
	}
	number = kokoko;
	return number;
}

double readDouble(double& number)
{
	string dabudidabuday;
	getline(cin, dabudidabuday);
	double d = 0.0;
	int point = 0;
	int blum = 0;
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
			if (dabudidabuday[i] == '.')
			{
				blum = i;
			}
			if (dabudidabuday[i] == '\0')
			{
				resolveError(0);
				return 0;
			}
			if ((dabudidabuday[i] >= 33 && dabudidabuday[i] <= 45) || (dabudidabuday[i] >= 58 && dabudidabuday[i] <= 64) || (dabudidabuday[i] >= 91 && dabudidabuday[i] <= 96) || (dabudidabuday[i] >= 123 && dabudidabuday[i] <= 127)||(dabudidabuday[i]==47))
			{
				resolveError(1);
				return 0;
			}
			if ((dabudidabuday[i] >= 65 && dabudidabuday[i] <= 90) || (dabudidabuday[i] >= 97 && dabudidabuday[i] <= 122))
			{
				resolveError(2);
				return 0;
			}
			if (dabudidabuday[i] >= 48 && dabudidabuday[i] <= 57)
			{
				d = 10 * d + dabudidabuday[i] - '0';
			}
		}
		else
		{
			resolveError(3);
			return 0;
		}
	}
	number = d;
	number /= pow(10, dabudidabuday.size() - blum - 1);
	return number;
}