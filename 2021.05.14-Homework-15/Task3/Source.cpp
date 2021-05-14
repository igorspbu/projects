#include<iostream>

using namespace std;

void FillArray(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		a[i] = rand() % 100;
	}
}

void QuickSort(int* a, int n)
{
	int i = 0;
	int j = n - 1;
	int mid = a[n / 2];
	do
	{
		while (a[i] < mid)
		{
			i++;
		}
		while (a[j] > mid)
		{
			j--;
		}

		if (i <= j)
		{
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;

			i++;
			j--;
		}
	} while (i <= j);


	if (j > 0)
	{
		QuickSort(a, j + 1);
	}
	if (i < n)
	{
		QuickSort(&a[i], n - i);
	}
}

void merge(int* a, int* b, int* c, int n1, int n2)
{
	for (int i = 0; i < n1; ++i)
	{
		c[i] = a[i];
	}
	for (int i = n1; i < n1 + n2; ++i)
	{
		c[i] = b[i - n1];
	}
}

int main()
{
	int n1 = 10;
	int n2 = 10;
	int* a = new int[n1];
	int* b = new int[n2];
	int* c = new int[n1 + n2]{ 0 };

	FillArray(a, n1);
	FillArray(b, n2);

	cout << "Array a:" << endl;
	for (int i = 0; i < n1; ++i)
	{
		cout << a[i] << ' ';
	}
	cout << endl << endl;

	cout << "Array b:" << endl;
	for (int i = 0; i < n1; ++i)
	{
		cout << b[i] << ' ';
	}
	cout << endl << endl;

	QuickSort(a, n1);
	QuickSort(b, n2);

	cout << "Ordered array a:" << endl;
	for (int i = 0; i < n1; ++i)
	{
		cout << a[i] << ' ';
	}
	cout << endl << endl;

	cout << "Ordered array b:" << endl;
	for (int i = 0; i < n1; ++i)
	{
		cout << b[i] << ' ';
	}
	cout << endl << endl;

	merge(a, b, c, n1, n2);

	cout << "Array c:" << endl;
	for (int i = 0; i < n1 + n2; ++i)
	{
		cout << c[i] << ' ';
	}
	cout << endl << endl;

	QuickSort(c, n1 + n2);

	cout << "Ordered array c:" << endl;
	for (int i = 0; i < n1 + n2; ++i)
	{
		cout << c[i] << ' ';
	}

	return 0;
}