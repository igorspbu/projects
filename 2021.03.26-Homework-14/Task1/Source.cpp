#include<iostream>
using namespace std;

void swap(int& a, int& b);
void fillArray(int* a, int len);
void inputArray(int* a, int len);
void printArray(int* a, int len);
void mixArray(int* a, int len);
bool isSorted(int* a, int len, bool ascending = true);
void bubbleSort(int* a, int len, int& count1, int& count2);
void insertionSort(int* a, int len, int& count1, int& count2);
void selectionSort(int* a, int len, int& count1, int& count2);
void fillAscending(int* a, int len);
void fillDescending(int* a, int len);



int main()
{
	setlocale(LC_ALL, "Russian");

	int q = 0;
	cout << "1 -- заполнить массив подряд идущими цифрами по возрастанию, 2 -- заполнить массив подряд идущими по убыванию, 3 -- заполнить случайными числами" << endl;
	cin >> q;

	for (int len = 5; len < 25; len += 5)
	{
		int count1Bubble = 0;
		int count2Bubble = 0;

		int count1Insertion = 0;
		int count2Insertion = 0;

		int count1Selection = 0;
		int count2Selection = 0;

		int* a = new int[len];

		for (int i = 0; i < 1000; ++i)
		{
			if (q == 1)
			{
				fillAscending(a, len);
			}
			if (q == 2)
			{
				fillDescending(a, len);
			}
			else
			{
				fillArray(a, len);
			}
			bubbleSort(a, len, count1Bubble, count2Bubble);
		}
		cout << "BubbleSort" << endl;
		cout << "Среднее количество сравнений " << count1Bubble / 1000 << endl;
		cout << "Среднее количество перестановок " << count2Bubble / 1000 << endl << endl;

		for (int i = 0; i < 1000; ++i)
		{
			if (q == 1)
			{
				fillAscending(a, len);
			}
			if (q == 2)
			{
				fillDescending(a, len);
			}
			else
			{
				fillArray(a, len);
			}
			insertionSort(a, len, count1Insertion, count2Insertion);
		}
		cout << "InsertionSort" << endl;
		cout << "Среднее количество сравнений " << count1Insertion / 1000 << endl;
		cout << "Среднее количество перестановок " << count2Insertion / 1000 << endl << endl;

		for (int i = 0; i < 1000; ++i)
		{
			if (q == 1)
			{
				fillAscending(a, len);
			}
			if (q == 2)
			{
				fillDescending(a, len);
			}
			else
			{
				fillArray(a, len);
			}
			selectionSort(a, len, count1Selection, count2Selection);
		}
		cout << "SelectionSort" << endl;
		cout << "Среднее количество сравнений " << count1Selection / 1000 << endl;
		cout << "Среднее количество перестановок " << count2Selection / 1000 << endl << endl;
		
		delete[]a;
	}

	return 0;
}

void swap(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}

void fillArray(int* a, int len)
{
	for (int i = 0; i < len; ++i)
	{
		a[i] = rand() % 90 + 10;
	}
}

void inputArray(int* a, int len)
{
	for (int i = 0; i < len; ++i)
	{
		cin >> a[i];
	}
}

void printArray(int* a, int len)
{
	for (int i = 0; i < len; ++i)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
}

void mixArray(int* a, int len)
{
	for (int i = 0; i < len; ++i)
	{
		swap(a[i], a[rand() % len]);
	}
}

bool isSorted(int* a, int len, bool ascending)
{
	for (int i = 0; i < len; ++i)
	{
		if (a[i] > a[i + 1] == ascending)
		{
			return false;
		}
	}
	return true;
}

void bubbleSort(int* a, int len, int& count1, int& count2)
{
	for (int i = 0; i < len - 1; ++i)
	{
		for (int j = 0; j < len - i - 1; ++j)
		{
			++count1;
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				++count2;
			}
		}
	}
}

void insertionSort(int* a, int len, int& count1, int& count2)
{
	for (int i = 0; i < len; ++i)
	{
		++count1;
		int q = a[i];
		int j = i;
		while (j > 0 && a[j - 1] > q)
		{
			++count1;
			a[j] = a[j - 1];
			--j;
			++count2;
		}
		a[j] = q;
	}
}

void selectionSort(int* a, int len, int& count1, int& count2)
{
	for (int i = 0; i < len - 1; ++i)
	{
		int index = i;
		for (int j = i + 1; j < len; ++j)
		{
			if (a[j] < a[index])
			{
				index = j;
			}
			++count1;
		}
		swap(a[i], a[index]);
		++count2;
	}
}

void fillAscending(int* a, int len)
{
	for (int i = 0; i < len; ++i)
	{
		a[i] = i;
	}
}

void fillDescending(int* a, int len)
{
	for (int i = len; i > 0; --i)
	{
		a[len - i] = i;
	}
}