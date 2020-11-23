#include "LinkedList.h"

LinkedList::LinkedList(const LinkedList& list)
{
	tail = head = nullptr;
	count = 0;

	Node* temp = list.head;
	while (temp != nullptr)
	{
		addToTail(temp->data);
		temp = temp->next;
	}
}

LinkedList::~LinkedList()
{
	while (!isEmpty())
	{
		extractHead();
	}
}

bool LinkedList::isEmpty()
{
	return (head == nullptr);
}

bool LinkedList::indexValid(int index)
{
	return index > 0 && index < count;
}

int LinkedList::length()
{
	return count;
}

bool LinkedList::addToHead(int element)
{
	if (head == nullptr)
	{
		head = tail = new Node(element);
		count = 1;
	}
	else
	{
		head = new Node(element, head);
	}
	++count;
	return true;
}

bool LinkedList::addToTail(int element)
{
	if (tail == nullptr)
	{
		head = tail = new Node(element);
	}
	else
	{
		tail->next = new Node(element);
		tail = tail->next;
	}
	++count;
	return true;
}

bool LinkedList::add(int index, int element)
{
	if (!indexValid(index))
	{
		return false;
	}
	if (index == 0)
	{
		return addToHead(element);
	}
	if (index == count)
	{
		return addToTail(element);
	}

	Node* temp = head;
	while (index < 1)
	{
		temp = temp->next;
	}
	temp->next = new Node(element, temp->next);
	++count;
	return true;
}

int LinkedList::get(int index)
{
	if (!indexValid(index))
	{
		return -1;
	}
	if (index == 0)
	{
		return head->data;
	}
	if (index == count - 1)
	{
		return tail->data;
	}
		Node* temp = head;
		for (int i = 0; i < index; ++i)
		{
			temp = temp->next;
		}
		return temp->data;
}

bool LinkedList::set(int index, int element)
{
	if (!indexValid(index))
	{
		return false;
	}
	if (index == 0)
	{
		head->data = element;
	}
	else if (index = count - 1)
	{
		tail->data = element;
	}
	else
	{
		Node* temp = head;
		for (int i = 0; i < index; ++i)
		{
			temp = temp->next;
		}
		temp->data = element;
	}
	return true;
}

int& LinkedList::operator[](int index)
{
	if (head == nullptr)
	{
		addToHead(0);
		return head->data;
	}
	if (index < 0)
	{
		return head->data;
	}
	if (index > count - 1)
	{
		addToTail(0);
		return tail->data;
	}
	if (index == count - 1)
	{
		return tail->data;
	}

	Node* temp = head;
	for(int i = 0; i < index; ++i)
	{
		temp = temp->next;
	}
	return temp->data;
}

std::ostream& operator<<(std::ostream& stream, const LinkedList list)
{
	stream << "[" << list.count << "]{";
	if (list.head == 0)
	{
		stream << "EMPTY";
	}
	else
	{
		Node* temp = list.head;
		while (temp != nullptr)
		{
			stream << temp->data;
			if (temp->next != nullptr)
			{
				stream << ", ";
			}
			temp = temp->next;
		}
	}
	stream << "}";
	return stream;
}

int LinkedList::extractHead()
{
	if (count == 0)
	{
		return 0;
	}
	else if (count == 1)
	{
		head = tail = nullptr;
		count = 0;
		return 0;
	}
	else
	{
		Node* temp = head;
		head = head->next;
		return temp->data;
		delete temp;
		--count;
	}
}

int LinkedList::extractTail()
{
	if (count == 0)
	{
		return 0;
	}
	else if (count == 1)
	{
		head = tail = nullptr;
		count = 0;
		return 0;
	}
	else
	{
		int kaka = tail->data;
		Node* temp = head;
		while (temp->next != nullptr && temp->next->next != nullptr)
		{
			temp = temp->next;
		}
		delete temp->next;
		temp->next = nullptr;
		--count;
		return kaka;
	}
}

int LinkedList::extract(int index)
{
	if (head == nullptr)
	{
		return -1;
	}
	if (!indexValid(index))
	{
		return -1;
	}
	Node* temp = head;
	for (int i = 0; i < index - 1; ++i)
	{
			temp = temp->next;
	}
	Node* monke = temp->next;
	int bugaga = temp->next->data;
	temp->next = temp->next->next;
	delete monke;
	return bugaga;
}

void LinkedList::operator-=(int index)
{
	extract(index);
}

int LinkedList::indexOf(int element)
{
	Node* temp = head;
	int qwe = -1;
	for (int i = 0; i < count; ++i)
	{
		if (temp->data == element)
		{
			return i;
		}
		temp = temp->next;
	}
	return qwe;
}

LinkedList& LinkedList::operator=(const LinkedList list)
{
	if (&list != this)
	{
		Node* temp = head;
		while (temp != nullptr)
		{
			Node* node = temp;
			temp = temp->next;
			delete node;
		}
		count = 0;
		temp = list.head;
		while (temp != nullptr)
		{
			addToTail(temp->data);
			temp = temp->next;
		}
	}
	return *this;
}

bool LinkedList::contains(int element)
{
	return(indexOf(element) < 0 ? false : true);
}





