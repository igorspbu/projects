#include <iostream>
using namespace std;

void expandArr(int*& arr, int& cap, int& count)
{
	cout << "Введите числа в массив" << endl;
	while (true)
	{
		int x = 0;
		cin >> x;
		if (x == 0)
			break;
		if (count == cap)
		{
			cap *= 2;
			int* temp = new int[cap];
			for (int i = 0; i < count; ++i)
				temp[i] = arr[i];
			delete[] arr;
			arr = temp;
		}

		arr[count] = x;
		count++;
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
	cout << "Введите n " << endl;
	cin >> n;
	cout << "Введите a и b, где a - нижняя граница промежутка" << endl;
	cin >> a;
	cin >> b;
	for (n; n > 0; --n)
	{
		if (count == cap)
		{
			cap*2;
			int* temp = new int[cap];
			for (int i = 0; i < count; ++i)
				temp[i] = arr[i];
			delete[] arr;
			arr = temp;
		}
		arr[count] = rand() % (b - a + 1) + a;
		count++;
	}
	
}

void reversecouple(int* arr, int count)
{
	for (int i = 0; i <= count; i = i + 2)
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
	cout << endl;
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
	cout << "Введите индекс элемента, разделяющего половинки" << endl;
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

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	int cap = 10;
	int* arr = new int[cap];
	int count = 0;
	expandArr(arr, cap, count);

	int choice = -1;
	while (choice != 0)
	{
		Menu();
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			addrand(arr, cap,count);
			allNumber(arr, count);
			break;
		}
		case 2:
		{
			reverse(arr,count);
			allNumber(arr, count);
			break;
		}
		case 3:
		{
			reversecouple( arr,count);
			allNumber(arr, count);
			break;
		}
		case 4:
		{
			shift(arr,count);
			allNumber(arr, count);
			break;
		}
		case 5:
		{
			turn( arr,count);
			allNumber(arr, count);
			break;
		}
		}
	}
	delete[]arr;
	return EXIT_SUCCESS;

}
