#include<iostream>
#include<string>
#include<stack>

using namespace std;

int f2()
{
	char x;
	int num;
	stack<int>s;
	int a = 0;
	int b = 0;
	while (cin >> x)
	{
		if (isdigit(x))
		{
			cin.putback(x);
			cin >> num;
			s.push(num);
		}
		if (x == '*' || x == '/' || x == '+' || x == '-')
		{
			a = s.top();
			s.pop();
			b = s.top();
			s.pop();
			if (x == '*')
			{
				s.push(a * b);
			}
			else if (x == '/')
			{
				s.push(b / a);
			}
			else if (x == '+')
			{
				s.push(a + b);
			}
			else if (x == '-')
			{
				s.push(b - a);
			}
		}
	}
	return s.top();
}

string f1()
{
	stack<char>sym;
	char x;
	string s;
	int number;
	char symbol;

	while (cin >> x)
	{
		if (isdigit(x))
		{
			cin.putback(x);
			cin >> number;
			s += to_string(number);
		}
		if (x == '(')
		{
			sym.push(x);
		}
		else if (x == '+' || x == '-')
		{
			while (!sym.empty() && (sym.top() == '+' || sym.top() == '-' || sym.top() == '*' || sym.top() == '/'))
			{
				s += sym.top();
				sym.pop();
			}
			cin.putback(x);
			cin >> symbol;
			sym.push(symbol);
		}
		else if (x == '*' || x == '/')
		{
			while (!sym.empty() && (sym.top() == '*' || sym.top() == '/'))
			{
				s += sym.top();
				sym.pop();
			}
			cin.putback(x);
			cin >> symbol;
			sym.push(symbol);
		}
		else if (x == ')')
		{
			while (sym.top() != '(')
			{
				s += sym.top();
				sym.pop();
			}
			sym.pop();
		}

	}
	if (!sym.empty())
	{
		while (!sym.empty())
		{
			s += sym.top();
			sym.pop();
		}
	}
	return s;
}

int main()
{
	//3+4*2/(1-5)
	//3 4 2 * 1 5 - / +
	setlocale(LC_ALL, "Russian");
	cout << "Обратная польская запись выражения: " << f1() << endl;
	cin.clear();
	cout << "Значение выражения, записанного в ОПЗ: " << f2() << endl;


	return EXIT_SUCCESS;
}