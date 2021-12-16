#include<iostream>
#include <cstdlib>
using namespace std;

struct DNode
{
	int data;
	DNode* next;
	DNode* perv;
	DNode(int d = 0, DNode* n = nullptr, DNode* p = nullptr) :data(d), next(n), perv(p) {};
};

struct DList
{
	DNode* head;
	DNode* tail;
	DList() { head = nullptr; tail = nullptr; }

	void add_first(int d)
	{
		DNode* t;
		t = new DNode(d, head, nullptr);
		if (head == nullptr)
		{
			head = t;
			tail = t;
		}
		else
		{
			head->perv = t;
			head = t;
		}
	}

	void print()
	{
		DNode* q = head;
		while (q != nullptr)
		{
			cout << q->data << "\t";
			q = q->next;
		}
		cout << endl;
	}

	void print_reserve()
	{
		DNode* q = tail;
		while (q != nullptr)
		{
			cout << q->data << "\t";
			q = q->perv;
		}
		cout << endl;
	}

	void Print()
	{
		print();
		print_reserve();
		cout << endl;
	}

	void add_last(int d)
	{
		DNode* q = new DNode(d, nullptr, tail);
		if (tail == nullptr)
		{
			head = q;
			tail = q;
		}
		else
		{
			tail->next = q;
			tail = q;
		}
	}

	void add_after_first(int d)
	{
		if (head == nullptr)
		{
			add_first(d);
		}
		DNode* q = new DNode(d, head->next, head);
		if (head->next == nullptr)
		{
			head->next = q;
			tail = q;
		}
		else
		{
			head->next->perv = q;
			head->next = q;
		}
		
	}

	void del_last()
	{
		if (head == nullptr)
		{
			cout << "Empty" << endl;
			return;
		}
		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
			tail = nullptr;
			return;
		}
		DNode* q = tail;
		tail = tail->perv;
		tail->next = nullptr;
		delete q;
	}

	void del_second()
	{
		if (head == nullptr || head->next == nullptr)
		{
			cout << "Can't delete" << endl;
			return;
		}
		else
		{
			DNode* q = head->next;
			head->next = head->next->next;
			head->next->perv = head;
			delete q;
		}
	}

	void insertp(int p, int d)
	{
		if (p < 0)
		{
			return;
		}
		int q = 0;
		DNode* w = head;
		while (w->next != nullptr)
		{
			++q;
			w = w->next;
		}
		if (p > q)
		{
			return;
		}
		if (p == 0)
		{
			add_first(d);
		}
		if (p == q)
		{
			add_last(d);
		}
		else
		{
			w = head;
			for (int i = 0; i < p-1; ++i)
			{
				w = w->next;
			}
			DNode* e = new DNode(d, w->next, w);
			w->next = e;
			w->next->next->perv = e;

		}
	}

	void delp(int p)
	{
		if (p < 0)
		{
			return;
		}
		int q = 0;
		DNode* w = head;
		while (w->next != nullptr)
		{
			++q;
			w = w->next;
		}
		if (p > q)
		{
			return;
		}
		if (p == 0)
		{
			DNode* a = head;
			head = head->next;
			head->perv = nullptr;
			delete a;
		}
		if (p == q)
		{
			del_last();
		}
		else
		{
			w = head;
			for (int i = 0; i < p - 1; ++i)
			{
				w = w->next;
			}
			DNode* e = w->next;
			w->next = w->next->next;
			w->next->perv = w;
			delete e;
		}
	}

	//void reverse()
	//{
	//	if (head == nullptr)
	//	{
	//		return;
	//	}
	//	if (head->next == nullptr)
	//	{
	//		cout << "Done" << endl;
	//		return;
	//	}
	//	else
	//	{
	//		DNode* q = head;
	//		DNode* w = tail;
	//		for(int i=0;i<)
	//	}
	//}

	void remove_if(bool function(int q))
	{
		DNode* w = head;
		while (w != nullptr)
		{
			if (function(w->data) == true)
			{
				if (w->next == nullptr)
				{
					del_last();
					w = nullptr;
				}
				else if (w == head)
				{
					head = head->next;
					head->perv = nullptr;
					w = w->next;
				}
				else
				{		
					DNode* q = w;
					w->perv->next = w->next;
					w->next->perv = w->perv;
					w = w->next;
					delete q;
					
				}
			}
			else
			{
				//cout << w->data << "\t";
				w = w->next;
			}
		}
	}

	void del_first()
	{
		if (head == nullptr)
		{
			return;
		}
		if (head->next == nullptr)
		{
			del_last();
		}
		else
		{
			DNode* q = head;
			head = head->next;
			head->perv = nullptr;
			delete q;
		}
	}

	void del()
	{
		if (head == nullptr)
		{
			return;
		}
		if (head->next == nullptr)
		{
			del_first();
		}
		else
		{
			while (head->next != nullptr)
			{
				del_first();
			}
			del_first();
		}
	}

	~DList()
	{
		del();
	}

	DNode* copy(DNode* x)
	{
		DList* l = new DList();
		if (x == nullptr)
		{
			return nullptr;
		}
		if (x->next == nullptr)
		{
			l->add_first(x->data);
		}
		else
		{
			while (x != nullptr)
			{
				l->add_last(x->data);
				x = x->next;
			}
		}
		return l->head;
	}

	DList(const DList& l)
	{
		head = copy(l.head);
		DNode* q = head;
		while (q->next != nullptr)
		{
			q = q->next;
		}
		tail = q;
	}

	DList& operator =(const DList& l)
	{
		del();
		for (DNode* temp = l.head; temp != nullptr; temp = temp->next)
		{
			add_last(temp->data);
		}
		return *this;
	}
};

bool parity(int q)
{
	if (q % 2 == 0)
	{
		return true;
	}
	return false;
}

int main()
{
	DList l;
	for (int i = 0; i < 8; ++i)
	{
		l.add_first(rand() % 20 + 1);
	}
	l.Print();

	/*l.add_after_first(10);
	l.Print();

	l.del_last();
	l.Print();

	l.del_second();
	l.Print();

	l.insertp(5, 47);
	l.Print();

	l.delp(6);
	l.Print();

	l.del();
	l.Print();

	cout << "Reload l" << endl;

	for (int i = 0; i < 8; ++i)
	{
		l.add_first(rand() % 20 + 1);
	}
	l.Print();

	DList w = DList(l);
	w.Print();*/

	cout << "Remove_if" << endl;
	l.remove_if(parity);
	l.Print();

	DList d;
	d.add_first(0);
	d.add_first(1);
	d.add_first(2);
	d.add_first(3);
	d.add_first(4);

	d.remove_if(parity);
	d.Print();
	return EXIT_SUCCESS;
}