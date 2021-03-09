#include<iostream>
#include<string>
#include<fstream>
using namespace std;

/*
<вещественное число> :: = <мантисса> <порядок> | <знак> <мантисса> <порядок>
<мантисса> :: = . <целое без знака> | <целое без знака> . <целое без знака>
<порядок> :: = E <целое без знака> | E <знак> <целое без знака>
<целое без знака> :: = <цифра> | <цифра> <целое без знака>
<цифра> :: = 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
< знак > :: = +| -
*/

bool isDigit(char c);
bool isSign(char c);
bool isNatural(string str, int& index);
bool isOrder(string str, int& index);
bool isMant(string str, int& index);
bool isReal(string str);

int main(int argc, char* argv[])
{
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	while (!fin.eof())
	{
		string str;
		fin >> str;
		if (isReal(str)==1)
		{
			cout << "=)" << endl;
		}
		else
		{
			cout << "=(" << endl;
		}
	}
	fout.close();
	fin.close();

	return 0;
}

bool isDigit(char c)
{
	return c >= '0' && c <= '9';
}

bool isSign(char c)
{
	if (c == '+' || c == '-')
	{
		return true;
	}
	return false;
}

bool isNatural(string str, int& index)
{
	if (isDigit(str[index]))
	{
		while (isDigit(str[++index]));
		return true;
	}
	return false;
}

bool isOrder(string str, int& index)
{
	if (str[index] == 'E')
	{
		++index;
		if (isSign(str[index]))
		{
			++index;
			if (isNatural(str, index))
			{
				return true;
			}
		}
		if (isNatural(str, index))
		{
			return true;
		}
	}
	return false;
}

bool isMant(string str, int& index)
{
	return str[index] == '.' && isNatural(str, ++index) || isNatural(str, index) && str[index] == '.' && isNatural(str, ++index);
}

bool isReal(string str)
{
	int q = 0;
	return isMant(str, q) && isOrder(str, q) || isSign(str[q]) && isMant(str, ++q) && isOrder(str, q);
}
