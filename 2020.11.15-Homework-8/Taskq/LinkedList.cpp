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
	if (head == nullptr)
	{
		return -1;
	}
	if (head == tail)
	{
		int oldHead = head->data;
		delete head;
		tail = head = nullptr;
		count = 0;
		return oldHead;
	}
	int oldHead = head->data;
	Node* node = head;
	head = head->next;
	delete node;
	--count;
	return oldHead;
}

int LinkedList::extractTail()
{
	if (tail == nullptr)
	{
		return -1;
	}
	if (head->next == nullptr)
	{
		return extractHead();
	}
	Node* node = head;
	while (node->next != nullptr && node->next->next != nullptr)
	{
		node = node->next;
	}
	int oldTail = node->data;
	delete node->next;
	node->next = nullptr;
	return oldTail;
}

int LinkedList::extract(int index)
{
	if (head == nullptr)
	{
		return -1;
	}
	if (count == 0)
	{
		head = tail = nullptr;
	}
	if (!indexValid(index))
	{
		return -1;
	}
	int oldElement;
	if (index == 0)
	{
		oldElement = head->data;
		extractHead();
	}
	else if (index == count - 1)
	{
		oldElement = tail->data;
		extractTail();
	}
	else
	{
		Node* node = head;
		for (int i = 0; i < index - 1; ++i)
		{
			node = node->next;
		}
		Node* temp = node->next;
		oldElement = node->data;
		node->next = node->next->next;
		delete temp;
	}
	return oldElement;
}

void LinkedList::operator-=(int index)
{
	extract(index);
}

int LinkedList::indexOf(int element)
{
	Node* temp = head;
	for (int i = 0; i < count; ++i)
	{
		if (temp->data == element)
		{
			return i;
		}
		temp = temp->next;
	}
	return -1;
}

LinkedList& LinkedList::operator=(const LinkedList list)
{
	for (Node* temp = list.head; temp != nullptr; temp = temp->next)
	{
		addToTail(temp->data);
	}
	return *this;

	while (count > 0)
	{
		extractHead();
	}
}

bool LinkedList::contains(int element)
{
	return(indexOf(element) < 0 ? false : true);
}





