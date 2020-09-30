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

void addrand(int*&arr,int& cap,int& count)
{
	int n = 0;
	int a = 0;
	int b = 0;
	cin >> n;
	cin >> a;
	cin >> b;
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

void turn(int* arr, int count)
{
	int n = 0;
	cin >> n;
	if (n <= count - 1)
	{
		int x = 0;
		for (int i = 0; i < n / 2; ++i)
		{
			x = arr[i];
			arr[i] = arr[n - 1 - i];
			arr[n - 1 - i] = x;
		}
		int q = 0;
		for (int i = n; n + (count - n) / 2 > i; ++i)
		{
			x = arr[i];
			arr[i] = arr[count - 1 - q];
			arr[count - 1 - q] = x;
			++q;
		}
	}
}

void cinMenu(int*& arr, int& cap, int& count)
{
	int choice = -1;
	while (choice != 0)
	{
		Menu();
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << "Введите n, а затем введите a и b, где a - нижняя граница промежутка" << endl;
			addrand(arr, cap, count);
			allNumber(arr, count);
			break;
		}
		case 2:
		{
			reverse(arr, count);
			allNumber(arr, count);
			break;
		}
		case 3:
		{
			reversecouple(arr, count);
			allNumber(arr, count);
			break;
		}
		case 4:
		{
			shift(arr, count);
			allNumber(arr, count);
			break;
		}
		case 5:
		{
			cout << "Введите индекс элемента, разделяющего половинки" << endl;
			turn(arr, count);
			allNumber(arr, count);
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
	cout << "Введите числа в массив " << endl;
	cinArr(arr, cap, count);
	cinMenu(arr, cap, count);

	delete[]arr;
	return EXIT_SUCCESS;

}
