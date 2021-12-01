#include <iostream>

using namespace std;

struct BNode
{
	int data;
	BNode* left, * right;
	BNode(int d, BNode* l = nullptr, BNode* r = nullptr) :
		data(d), left(l), right(r) {} 
};

void f_print(BNode* r, int d = 0);
int f_count(BNode* p);
void f_scale(BNode* p);
int f_sum(BNode* p);
int f_count_neg(BNode* p);
int f_height(BNode* p);
void f_reflect(BNode* p);
int f_mult(BNode* p);
int f_eval(BNode* p);
int min(BNode* p);

struct BTree
{
	BNode* root;
	BTree(BNode* p) : root(p) {}

	void print()
	{
		f_print(root);
		cout << "_______________________________" << endl << endl;
	}

	int count() 
	{
		return f_count(root);
	}
};

void f_print(BNode* r, int indent)
{
	if (r == nullptr) return;

	f_print(r->right, indent + 3);
	for (int i = 0; i < indent; ++i)
		cout << ' ';
	cout << r->data << endl;
	f_print(r->left, indent + 3);
}

int f_count(BNode* p)
{
	if (p == nullptr)
		return 0;
	return 1 + f_count(p->left) + f_count(p->right);
}

void f_scale(BNode* p)
{
	if (p != nullptr)
	{
		p->data = p->data * 3;
		f_scale(p->left);
		f_scale(p->right);
	}
}

int f_sum(BNode* p)
{
	if (p == nullptr)
	{
		return 0;
	}
	return p->data + f_sum(p->left) + f_sum(p->right);
}

int f_count_neg(BNode* p)
{
	if (p == nullptr)
	{
		return 0;
	}
	if (p->data < 0)
	{
		return 1 + f_count_neg(p->left) + f_count_neg(p->right);
	}
	if (p->data >= 0)
	{
		return f_count_neg(p->left) + f_count_neg(p->right);
	}
}

int f_height(BNode* p)
{
	if (p == nullptr)
	{
		return 0;
	}
	return 1 + max(f_height(p->left), f_height(p->right));
}

void f_reflect(BNode* p)
{
	if (p != nullptr)
	{
		swap(p->left, p->right);
		f_reflect(p->left);
		f_reflect(p->right);
	}
}

int f_mult(BNode* p)
{
	if (p != nullptr)
	{
		if (p->left != nullptr && p->right != nullptr)
		{
			return p->data * f_mult(p->left) * f_mult(p->right);
		}
		if (p->left == nullptr || p->right == nullptr)
		{
			return 1;
		}
	}
}

int f_eval(BNode* p)
{
	if (p->left == nullptr && p->right == nullptr)
	{
		return p->data;
	}
	if (p->left != nullptr && p->right != nullptr && p->data == 1)
	{
		return f_eval(p->left) + f_eval(p->right);
	}
	if (p->left != nullptr && p->right != nullptr && p->data == 2)
	{
		return f_eval(p->left) - f_eval(p->right);
	}
	if (p->left != nullptr && p->right != nullptr && p->data == 3)
	{
		return f_eval(p->left) * f_eval(p->right);
	}
	if (p->left != nullptr && p->right != nullptr && p->data == 4)
	{
		return f_eval(p->left) / f_eval(p->right);
	}
}

int min(BNode* p)
{
	if (p != nullptr)
	{

	}
}

template <class T>
BNode* f_find(T d, BNode* p)
{
	if (p != nullptr)
	{
		if (d == p->data)
		{
			return p;
		}
		f_find(d, p->left);
		f_find(d, p->right);
		return nullptr;
	}
}



int main()
{
	BNode* p6 = new BNode(6),
		* p5 = new BNode(5),
		* p4 = new BNode(4),
		* p3 = new BNode(3, p6),
		* p2 = new BNode(2, p4, p5),
		* p1 = new BNode(1, p2, p3);

	BTree t(p1);
	t.print();

	cout << "The number of nodes is " << t.count() << endl;

	cout << "________________________________" << endl;
	f_scale(p1);
	t.print();

	cout << "________________________________" << endl;
	cout << f_sum(p1) << endl;

	cout << "________________________________" << endl;
	cout << f_count_neg(p1) << endl;

	cout << "________________________________" << endl;
	cout << f_height(p1) << endl;

	cout << "________________________________" << endl;
	f_reflect(p1);
	t.print();

	cout << "________________________________" << endl;
	cout << f_mult(p1) << endl;


	BNode* q6 = new BNode(9),
		* q7 = new BNode(7),
		* q8 = new BNode(10),
		* q9 = new BNode(5),
		* q10 = new BNode(6),
		* q11 = new BNode(7),
		* q4 = new BNode(4, q8, q9),
		* q5 = new BNode(1, q10, q11),
		* q2 = new BNode(2, q4, q5),
		* q3 = new BNode(3, q6, q7),
		* q1 = new BNode(1, q2, q3);
	BTree q(q1);
	cout << "________________________________" << endl;
	q.print();
	cout << "________________________________" << endl;
	cout << f_eval(q1) << endl;
		
	cout << "________________________________" << endl;
	q.print();
	cout << f_find(7, q1) << endl;



	return EXIT_SUCCESS;
}