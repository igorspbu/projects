#include<iostream>
#include<cstdlib>
using namespace std;

struct Node
{
	int data;
	Node* next;
	Node(int d = 0, Node* n = nullptr) :data(d), next(n) {};
};

struct List
{
	Node* head;
	Node* tail;

	List()
	{
		head = tail = nullptr;
	}

	~List()
	{
		del();
	}

	List(const List& l)
	{
		tail = head = nullptr;

		Node* temp = l.head;
		while (temp != nullptr)
		{
			add_last(temp->data);
			temp = temp->next;
		}
	}

	List& operator=(const List& l)
	{
		for (Node* temp = l.head; temp != nullptr; temp = temp->next)
		{
			add_last(temp->data);
		}
		return *this;

		while (head != nullptr)
		{
			del_last();
		}
	}

	void add_first(int d)
	{
		Node* temp;
		temp = new Node(d, head);
		head = temp;
	}

	void print()
	{
		Node* p = head;
		while (p != nullptr)
		{
			cout << p->data << '\t';
			p = p->next;
		}
		cout << endl;
	}

	Node* last()
	{
		Node* temp = head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		return temp;
	}

	Node* prelast()
	{
		Node* p = head;
		while (p->next->next != nullptr)
		{
			p = p->next;
		}
		return p;
	}

	Node* get_ptr(int n)
	{
		Node* p = head;
		for (int i = 0; i < n; ++i)
		{
			p = p->next;
		}
		return p;
	}
	
	void add_after_first(int d)
	{
		if (head == nullptr)
		{
			add_first(d);
		}
		else if (head->next == nullptr)
		{
			tail = head->next = new Node(d, head->next);
		}
		else
		{
			head->next = new Node(d, head->next);
		}
	}
	
	void add_last(int d)
	{
		last()->next = new Node(d, nullptr);
	}

	void del_last()
	{
		if (head == nullptr)
		{
			cout << "Empty" << endl;
			return;
		}
		else if (head->next == nullptr)
		{
			Node* temp=head;
			delete temp;
			head = tail = nullptr;
		}
		else
		{
			Node* p = prelast()->next;
			Node* q = prelast();
			q->next = nullptr;
			delete p;
		}
	}

	void insertp(int index, int d)
	{
		if (index == 0)
		{
			add_first(d);
		}
		Node* p = head;
		for (int i = 0; i < index; i++)
		{
			p = p->next;
		}
		p->next = new Node(d, p->next);
	}

	void delp(int index)
	{
		if (head == tail)
		{
			delete head;
			head = tail = nullptr;
		}
		else
		{
			Node* node = head;
			for (int i = 0; i < index - 1; ++i)
			{
				node = node->next;
			}
			Node* temp = node->next;
			node->next = node->next->next;
			delete temp;
		}
	}

	void del()
	{
		if (head == nullptr)
		{
			cout << "Empty" << endl;
			return;
		}
		else if (head->next == nullptr)
		{
			Node* temp = head;
			delete temp;
			head = tail = nullptr;
		}
		while (head->next != nullptr)
		{
			Node* p = prelast()->next;
			Node* q = prelast();
			q->next = nullptr;
			delete p;
		}
		delete head;
		head = tail = nullptr;
	}

	Node* copy(Node* x)
	{
		List* y = new List();
		if (x != nullptr)
		{
			while (x != nullptr)
			{
				y->add_last(x->data);
				x = x->next;
			}
		}
		if (x == nullptr)
		{
			cout << "Nothing to copy" << endl;
		}
	}
};

int main()
{
	List l;
	for (int i = 0; i < 7; ++i)
	{
		l.add_first(rand() % 10 + 1);
		l.print();
	}
	l.print();
	cout << l.last() << endl;
	cout << l.prelast() << endl;
	l.add_after_first(47);
	l.print();
	l.add_last(15);	
	l.print();
	cout << endl << endl;
	l.insertp(4, 47);
	l.print();
	cout << endl;
	l.delp(4);
	l.print();
	cout << endl;
	l.del_last();
	l.print();
	l.del();
	l.print();

	return EXIT_SUCCESS;
}