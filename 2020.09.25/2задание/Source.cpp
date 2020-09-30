#include <iostream>
using namespace std;

void expandArr(int*& arr, int& cap)
{
	int cap1 = cap * 2;
	int* temp = new int[cap1];
	for (int i = 0; i < cap; ++i)
	{
		temp[i] = arr[i];
	}
	delete[]arr;
	arr = temp;
	cap = cap1;
}

void cinArr(int*& arr, int& cap, int count)
{
	while (true)
	{
		int x = 0;
		cin >> x;
		if (x == 0)
		{
			break;
		}
		if (count >= cap)
		{
			expandArr(arr, cap);
		}
		arr[count] = x;
		++count;
	}
}

void Menu()
{
	cout << "0 - Выход из программы" << endl;
	cout << "1 - Добавить в массив n случайных чисел в промежутке от a до b" << endl;
	cout << "2 - Развернуть массив" << endl;
	cout << "3 - Поменять элементы массива местами в парах. Если число элементов нечетно, последний элемент остается на своем месте" << endl;
	cout << "4 - Циклический сдвиг вправо на 1" << endl;
	cout << "5 - Развернуть две половинки массива. n - индекс элемента, разделяющего половинки." << endl;
	cout << "Введите операцию" << endl;
}

void addrand(int*& arr, int& cap, int& count, int n, int a, int b)
{
	for (n; n > 0; --n)
	{
		if (count >= cap)
		{
			expandArr(arr, cap);
		}
		arr[count] = rand() % (b - a + 1) + a;
		count++;
	}
	
}

void reversecouple(int* arr, int count)
{
	for (int i = 0; i < count; i = i + 2)
	{
		int x = 0;
		if (i + 1 == count)
		{
			break;
		}
		x = arr[i];
		arr[i] = arr[i + 1];
		arr[i + 1] = x;
	}
}

void allNumber(int* arr, int count)
{
	for (int i = 0; i < count; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl << endl;
}

void reverse(int* arr, int count)
{
	int x = 0;
	for (int i = 0; i < count / 2; ++i)
	{
		x = arr[i];
		arr[i] = arr[count - 1 - i];
		arr[count - 1 - i] = x;
	}
}

void shift(int* arr, int count)
{
	int x = 0;
	x = arr[count - 1];
	int q = 0;
	for (int i = count - 1; i > 0; --i)
	{
		arr[i] = q;
		arr[i] = arr[i - 1];
		q = arr[i - 1];
	}
	arr[0] = x; 
}

void turn(int* arr, int count, int w)
{
	if (w <= count - 1)
	{
		int x = 0;
		for (int i = 0; i < w / 2; ++i)
		{
			x = arr[i];
			arr[i] = arr[w - 1 - i];
			arr[w - 1 - i] = x;
		}
		int q = 0;
		for (int i = w; w + (count - w) / 2 > i; ++i)
		{
			x = arr[i];
			arr[i] = arr[count - 1 - q];
			arr[count - 1 - q] = x;
			++q;
		}
	}
}

void cinMenu(int*& arr, int& cap, int& count,int choice)
{
	while (choice != 0)
	{
		switch (choice)
		{
		case 1:
		{

			int n = 0;
			int a = 0;
			int b = 0;
			cout << "Введите n, а затем введите a и b, где a - нижняя граница промежутка" << endl;
			cin >> n;
			cin >> a;
			cin >> b;
			addrand(arr, cap, count, a, b, n);
			break;
		}
		case 2:
		{
			reverse(arr, count);
			break;
		}
		case 3:
		{
			reversecouple(arr, count);
			break;
		}
		case 4:
		{
			shift(arr, count);
			break;
		}
		case 5:
		{
			int w = 0;
			cout << "Введите индекс элемента, разделяющего половинки" << endl;
			cin >> w;
			turn(arr, count, w);
			break;
		}


		}
	}
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	int cap = 10;
	int* arr = new int[cap];
	int count = 0;
	int choice = 0;

	cinArr(arr, cap, count);

	do
	{
		system("cls");
		Menu(); 
		cin >> choice;
		cinMenu(arr, count, cap, choice);
		system("pause");
	} while (choice != 0);

	delete[]arr;
	return EXIT_SUCCESS;
}
