#include<iostream>

using namespace std;

void FillArray(int* a, int b)
{
	for (int i = 0; i < b; ++i)
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

int main()
{
	int n = 10;
	int* a = new int[n];

	FillArray(a, n);

	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << ' ';
	}
	cout << endl;

	QuickSort(a, n);

	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << ' ';
	}
	cout << endl;

	return 0;
}