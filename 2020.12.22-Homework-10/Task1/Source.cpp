#include<iostream>
#include <clocale>
using namespace std;

int** initMatrix(int n)
{
	int** data = new int* [n] { 0 };
	for (int i = 0; i < n; ++i)
	{
		data[i] = new int[n] { 0 };

	}
	return data;
}

void print(int** data, int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			printf("%3d ", data[i][j]);
		}
		cout << endl;
	}
	cout << endl << endl << endl;
}

void free(int** data, int n)
{
	for (int i = 0; i < n; ++i)
	{
		delete[] data[i];
	}
	delete[] data;
}

void task1(int** data, int n)
{
	int q = 1;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			data[i][j] = q + j;
		}
		++q;
	}
}

void task2(int** data, int n)
{
	int q = 1;
	for (int i = n-1; i >= 0; --i)
	{
		int w = 0;
		for (int j = n-1; j >= 0; --j)
		{
			data[i][j] = q + w;
			++w;
		}
		w = 0;
		++q;
	}
}

void task3(int** data, int n)
{
	int q = 1;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			data[i][j] = q;
			++q;
		}
		q = 1;
	}
}

void task4(int** data, int n)
{
	int q = 0;
	int w = 1;
	for (int j = 0; j < n; ++j)
	{
		for (int i = q; i < n; ++i)
		{
			data[i][q] = w;
		}
		for (int i = q; i < n; ++i)
		{
			data[q][i] = w;
		}
		++q;
		++w;
	}
}

void rightCorner(int** data, int n, int& string, int& column, int& q)
{
	for (int i = 0; i < n; ++i)
	{
		data[string][column] = q;
		++column;
		++q;
	}
	--column;
	for (int i = 0; i < n - 1; ++i)
	{
		++string;
		data[string][column] = q;
		++q;
	}
}

void leftCorner(int** data, int n, int& string, int& column, int& q)
{
	for (int i = n - 1; i > 0; --i)
	{
		--column;
		data[string][column] = q;
		++q;
	}
	for (int i = n - 1; i > 1; --i)
	{
		--string;
		data[string][column] = q;
		++q;
	}

}

void task5(int** data, int n)
{
	int i = 0;
	int string = 0;
	int column = 0;
	int q = 1;
	while (i < (n + 1) / 2)
	{
		rightCorner(data, n - 2 * i, string, column, q);
		leftCorner(data, n - 2 * i, string, column, q);
		++column;
		++i;
	}
		
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int n = 0;
	cout << "¬ведите кол-во столбцов и строк" << endl;
	cin >> n;
	int** A = initMatrix(n);
	task1(A, n);
	print(A, n);
	task2(A, n);
	print(A, n);
	task3(A, n);
	print(A, n);
	task4(A, n);
	print(A, n);
	task5(A, n);
	print(A, n);

	free(A, n);
	return 0;
}