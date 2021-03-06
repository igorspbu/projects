#include"ArrayList.h"

ArrayList::~ArrayList()
{
	if (data != nullptr)
	{
		delete[] data;
	}
	if (str != nullptr)
	{
		delete[] str;
	}
}

ArrayList::ArrayList(const ArrayList& list)
{
	capacity = list.capacity;
	count = list.count;
	data = new int[capacity];
	for (int i = 0; i < count; ++i)
	{
		data[i] = list.data[i];
	}
	str = nullptr;
}

int ArrayList::numLength(int number)
{
	int result = 1;
	if (number < 0)
	{
		number *= -1;
		++result;
	}
	if (number > 9)
	{
		number /= 10;
		++result;
	}
	return result;
}

void ArrayList::addSymbolToStr(int& index, char symbol)
{
	str[index] = symbol;
	++index;
}

void ArrayList::addNumberToStr(int& index, int number)
{
	int length = numLength(number);
	if (number < 0)
	{
		number *= -1;
		str[index] = '-';
		index++;
		--length;
	}
	for (int i = 0; i < length; ++i)
	{
		int digit = number % 10;
		str[index + length - 1 - i] = '0' + digit;
		number /= 10;
	}
	index += length;
}

void ArrayList::expand()
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

bool ArrayList::add(int element)
{
	if (count == capacity)
	{
		expand();
	}
	data[count] = element;
	count++;
	return true;
}

bool ArrayList::add(int index, int element)
{
	if (index < 0 || index > count)
	{
		return false;
	}
	if (count == capacity)
	{
		expand();
	}
	for (int i = count; i > index; --i)
	{
		data[i] = data[i - 1];
	}
	data[index] = element;
	count++;
	return true;
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
		{
			expand();
		}
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
				expand();
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
	for (int i = 0; i < count; ++i)
	{
		if (data[i] == element)
		{
			return true;
			break;
		}
	}
	return false;
}

int ArrayList::get(int index)
{
	if (index > count - 1 || index < 0)
	{
		return -1;
	}
	return data[index];
}

bool ArrayList::set(int index, int element)
{
	if (index<0 || index>count - 1)
	{
		return false;
	}
	else
	{
		data[index] = element;
		return true;
	}
}

int ArrayList::indexOf(int element)
{
	for (int i = 0; i < count; ++i)
	{
		if (data[i] == element)
		{
			return i;
			break;
		}
	}
	return-1;
}

bool ArrayList::isEmpty()
{
	return(count == 0);
}

char* ArrayList::toString()
{
	if (str != nullptr)
	{
		delete[] str;
		str = nullptr;
	}
	int length = 7 + numLength(count) + numLength(capacity);
	for (int i = 0; i < count; ++i)
	{
		length += numLength(data[i]);
	}
	length += 2 * (count - 1);
	str = new char[length];
	int index = 0;
	addSymbolToStr(index, '[');
	addNumberToStr(index, count);
	addSymbolToStr(index, '/');
	addNumberToStr(index, capacity);
	addSymbolToStr(index, ']');
	addSymbolToStr(index, ' ');
	addSymbolToStr(index, '{');

	for (int i = 0; i < count - 1; ++i)
	{
		addNumberToStr(index, data[i]);
		addSymbolToStr(index, ',');
		addSymbolToStr(index, ' ');
	}

	addNumberToStr(index, data[count - 1]);
	addSymbolToStr(index, '}');
	addSymbolToStr(index, '\0');

	return str;
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
		return true;
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
		int x = data[index1];
		data[index1] = data[index2];
		data[index2] = x;
		return true;
	}
}

int ArrayList::length()
{
	return count;
}

void ArrayList::operator+= (int item)
{
	add(item);
}

void ArrayList::operator-= (int item)
{
	remove(indexOf(item));
}

ArrayList& ArrayList:: operator= (const ArrayList& list)
{
	if (&list != this)
	{
		capacity = list.capacity;
		count = list.count;
		data = new int[capacity];
		for (int i = 0; i < count; ++i)
		{
			data[i] = list.data[i];
		}
		str = nullptr;
	}
	return *this;
}

ArrayList operator+ (const ArrayList& list, int item)
{
	ArrayList sub(list);
	sub += item;
	return sub;
}

ArrayList operator+ (int item, const ArrayList& list)
{
	ArrayList sub(list);
	sub.add(0, item);
	return sub;
}

ArrayList operator+ (const ArrayList& list1, const ArrayList& list2)
{
	ArrayList sub(list2);
	for (int i = 0; i < list1.count; ++i)
	{
		sub += list1.data[i];
	}
	return sub;
}

ArrayList operator- (const ArrayList& list, int item)
{
	ArrayList sub(list);
	sub -= item;
	return sub;
}

ArrayList operator- (int item, const ArrayList& list)
{
	ArrayList sub(list);
	for (int i = 0; i < sub.count; ++i)
	{
		if (sub.data[i] == item)
		{
			sub.remove(i);
			return sub;
		}
	}
	return sub;
}

std::ostream& operator<<(std::ostream& stream, const ArrayList& list)
{
	stream << "{";
	for (int i = 0; i < (list.count)-1; ++i)
	{
		stream << list.data[i] << ", ";
	}
	for (int i = (list.count) - 1; i < list.count; ++i)
	{
		stream << list.data[i];
	}
	stream << "}";
	return stream;
}