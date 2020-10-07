#include<iostream>
#include<clocale>
#include<ctime>

using namespace std;

void printMenu()
{
	cout << "МЕНЮ" << endl;
	cout << "0 - Выход из программы" << endl;
	cout << "1 - Ввести несколько элемнетов с клавиатуры" << endl;
	cout << "2 - Добавить в массив n случайных чисел в промежутке от a до b(n, a, b вводится с клавиатуры)" << endl;
	cout << "3 - Вывести массив на экран" << endl;
	cout << "4 - Поиск индекса элемента" << endl;
	cout << "5 - Добавление массив к массиву" << endl;
	cout << "6 - Объединение массивов" << endl;
	cout << "7 - Вставка элемента в массив" << endl;
	cout << "8 - Удаление нескольких подряд идущих элементов массива" << endl;
	cout << "9 - Поиск подпоследовательности" << endl;
}

int* initArray(int capacity = 10, int count = 5)
{
	int* result = new int[capacity + 2]{ 0 };
	*(result + 1) = capacity;
	*(result) = count;
	result += 2;
	return result;
}

void deleteArray(int* arr)
{
	arr -= 2;
	delete[] arr;
}

void expandArray(int*& arr)
{
	int* temp = initArray(2 * (*(arr - 1)));
	for (int i = 0; i < *(arr - 1); ++i)
	{
		*(temp + i) = *(arr + i);
	}
	*(temp - 2) = *(arr - 2);
	deleteArray(arr);
	arr = temp;
}

void addElement(int*& arr, int element)
{
	if (*(arr - 2) == *(arr - 1))
	{
		expandArray(arr);
	}
	*(arr + *(arr - 2)) = element;
	++(*(arr - 2));
}

void addRandomElements(int*& arr, int n, int min, int max)
{
	for (int i = 0; i < n; ++i)
	{
		addElement(arr, rand() % (max - min + 1) + min);
	}
}

void printArray(int* arr)
{
	cout << "[" << *(arr - 2) << "/" << *(arr - 1) << "] {";
	for (int i = 0; i < *(arr - 2); ++i)
	{
		cout << *(arr + i) << (i == *(arr - 2) - 1 ? "}\n" : ", ");
	}
}

int search(int* arr, int element, int start = 0)
{
	int qwe = -1;
	for (int i = start; i < *(arr - 2); ++i)
	{
		if (*(arr + i) = element)
		{
			qwe = i;
		}
	}
	return qwe;
}

void add(int*& arr, int* addedArr)
{
	if ((*(arr - 1) - *(arr - 2)) < *(addedArr - 2))
	{
		expandArray(arr);
	}
	for (int i = 0; i < *(addedArr - 2); ++i)
	{
		int x = 0;
		*(arr + *(arr - 2) + i) = x;
		x = *(addedArr + i);
		++(*(arr - 2));
	}
}

int* unify(int* a, int* b)
{
	int* result = initArray(*(a - 2) + *(b - 2), 0);
	int* min = (*(a - 2) < *(b - 2) ? a : b);
	int* max = (*(a - 2) <= *(b - 2) ? b : a);
	for (int i = 0; i < *(min - 2); ++i)
	{
		addElement(result, *(a + i));
		addElement(result, *(b + i));
	}
	for (int i = *(min - 2); i < *(max - 2); ++i)
	{
		addElement(result, *(max + i));
	}
	return result;
}

int extract(int* a, int index)
{
	if (index < *(a - 2))
	{
		for (int i = 0; i < *(a - 2); ++i)
		{
			if (i == index)
			{
				int q = i;
				for (q; q < *(a - 2); ++q)
				{
					*(a + q) = *(a + q - 1);
				}
				return index;
				break;

			}
		}
	}

	else
		return -1;
}

int insert(int*& a, int index, int element)
{
	if (*(a - 1) == *(a - 2))
	{
		expandArray(a);
	}
	if (index > * (a - 2) - 1)
	{
		return 1;
	}
	if (index <= *(a - 2) - 1)
	{
		for (int i = index; i < *(a - 2); ++i)
		{
			*(a + i) = *(a + i + 1);
		}
		*(a + index) = element;
		++(*(a - 2));
		return 0;
	}
}

int deleteGroup(int*& a, int startIndex, int count = 1)
{
	if (startIndex >= *(a - 2))
	{
		return 1;
	}
	if (startIndex < *(a - 2))
	{
		for (int i = startIndex; i + count < *(a - 2); ++i)
		{
			*(a + i) = *(a + i + count);
		}
		for (; count > 0; count--)
		{
			--* (a - 2);
		}
		return 0;
	}
}

int subSequence(int* a, int* b)
{
	int q = 0;
	if (*(a - 2) < *(b - 2))
	{
		return -1;
	}
	if (*(a - 2) >= *(b - 2))
	{
		for (int i = 0; i < *(a - 2); ++i)
		{
			if (*(a + i) == *(b + i))
			{
				++q;
			}
			if (q == *(b - 2))
			{
				return *(a + i);
				break;
			}
		}
	}
}


void processChoice(int*& arr1, int*& arr2, int choice)
{
		switch (choice)
		{
		case 1:
		{
			int element = 0;
			cout << "Введите элемент, который хотите добавить в массив a " << endl;
			while (1)
			{
				cin >> element;
				if (element == 0)
				{
					break;
				}
				addElement(arr1, element);
			}
			break;
		}
		case 2:
		{
			int n = 0;
			int min = 0;
			int max = 0;
			cout << "Введите кол-во добавляемых чисел в массив a" << endl;
			cin >> n;
			cout << "Введите промежуток от a до b" << endl;
			cin >> min;
			cin >> max;
			addRandomElements(arr1, n, min, max);
			break;
		}
		case 3:
		{
			int q = 0;
			cout << "Введите 0, если хотите вывести массив a. 1, если b" << endl;
			while (3)
			{
				cin >> q;
				if (q == 0)
				{
					printArray(arr1);
					break;
				}
				
				if (q == 1)
				{
					printArray(arr2);
					break;
				}
			}
			break;
		}
		case 4:
		{
			int start = 0;
			int element = 0;
			cout << "Введите элемент" << endl;
			cin >> element;
			cout << search(arr1, element, start) << endl;
			break;
		}
		case 5:
		{
			cout << "Добаление массива b к a" << endl;
			add(arr1, arr2);

			break;
		}
		case 6:
		{
			cout << "Объединение двух массивов таким образом, что элементы массива a стоят на нечетных местах, а элементы b - на нечетных" << endl;
			unify(arr1, arr2);
			break;
		}
		case 7:
		{
			int index = 0;
			int element = 0;
			cout << "Введите индекс элемента и сам элемент" << endl;
			cin >> index;
			cin >> element;
			insert(arr1, index, element);
			break;
		}
		case 8:
		{
			int startIndex = 0;
			int count = 0;
			cout << "Введите индекс элемента, с которого начинается удаление элементов" << endl;
			cin >> startIndex;
			deleteGroup(arr1, startIndex, count = 1);
			break;
		}
		case 9:
		{
			cout << "Поиск подпоследовательности b в массиве a" << endl;
			cout << subSequence(arr1, arr2) << endl;
			break;
		}
		}

}

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	int* a = initArray(10, 5);
	int* b = initArray(10, 5);

	int choice = 0;
	do
	{
		system("cls");
		printMenu();
		cin >> choice;
		processChoice(a, b, choice);
		system("pause");
	} while (choice != 0);

	deleteArray(a);
	deleteArray(b);
	return EXIT_SUCCESS;
}