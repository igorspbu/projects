#include"ArrayList.h"

ArrayList::ArrayList()
{
	capacity = 10;
	count = 0;
	data = new int[10];
}

ArrayList::ArrayList(int cap)
{
	capacity = cap;
	count = 0;
	data = new int[cap];
}

ArrayList::~ArrayList()
{
	delete[] data;
}

void ArrayList::ExpandArr(int*& data, int& capacity)
{
	int* newData = new int[capacity * 2];
	for (int i = 0; i < capacity; i++)
	{
		newData[i] = data[i];
	}

	capacity *= 2;
	delete[] data;
	data = newData;  
}

void ArrayList::add(int element)
{
	if (count == capacity)
	{
		ExpandArr(data, capacity);
	}
	data[count] = element;
	++count;
}

void ArrayList::add(int index, int element)
{
	if (count == capacity)
	{
		ExpandArr(data, capacity);
	}
		for (int i = count; i > index + 1; --i)
	{
		data[i - 1] = data[i];
	}
	++count;
	data[index] = element;
}

bool ArrayList::addAll(ArrayList& list)
{
	if (list.count < 0)
	{
		return false;
	}
	for (int i = count; i < count + list.count; ++i)
	{
		if (count == capacity)
			ExpandArr(data, capacity);
		data[i] = list.data[i - count];
	}
	count += list.count;
	return true;
}

bool ArrayList::addAll(int index, ArrayList& list)
{
	if (index > count || index < 0)
	{
		return false;
	}
	else
	{
		for (int i = count - 1; i > index - 1; --i)
		{
			if (capacity == count)
			{
				ExpandArr(data, capacity);
			}
			data[i + list.count] = data[i];
		}
		for (int i = index; i < index + list.count; ++i)
		{
			data[i] = list.data[i - index];
		}
		count += list.count;
		return true;
	}
}

void ArrayList::clear()
{
	for (int i = count - 1; i >= 0; --i)
	{
		data[i] = 0;
		--count;
	}
}

bool ArrayList::contains(int element)
{
	int q = 0;
	for (int i = 0; i < count; ++i)
	{
		if (data[i] = element)
		{
			++q;
			return true;
		}
	}
	if (q == 0)
	{
		return false;
	}
}

int ArrayList::get(int index)
{
	if (index >= count || index < 0)
	{
		return -1;
	}
	return data[index];
}

int ArrayList::indexOf(int element)
{
	int q = 0;
	for (int i = 0; i < count; ++i)
	{
		if (data[i] = element)
		{
			++q;
			return i;
		}
	}
	if (q == 0)
	{
		return-1;
	}
}

bool ArrayList::isEmpty()
{
	return(count == 0);
}

void ArrayList::print()
{
	cout << "[" << count << "/" << capacity << "]";
	cout << "{";
	if (count == 0)
	{
		cout << "EMPTY";
	}
	else
	{
		for (int i = 0; i < count; ++i)
		{
			cout << data[i] << (i == count - 1 ? "" : ", ");
		}
	}
	cout << "}\n";
}

bool ArrayList::remove(int index)
{
	if (index >= count)
	{
		return false;
	}
	else
	{
		for (int i = index; i < count; ++i)
		{
			data[i] = data[i + 1];
		}
		--count;
	}
}

int ArrayList::swap(int index1, int index2)
{
	if (index1 >= count || index2 >= count || index1 < 0 || index2 < 0)
	{
		return false;
	}
	else
	{
		int q = 0;
		data[index1] = q;
		data[index1] = data[index2];
		q = data[index2];
		return true;
	}
}