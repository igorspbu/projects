#include<iostream>

using namespace std;

struct BNode
{
	int data;
	BNode* left, * right;
	BNode(int d, BNode* l = nullptr, BNode* r = nullptr) :
		data(d), left(l), right(r) {};
};

void f_print(BNode* r, int indent = 0)
{
	if (r == nullptr) return;
	f_print(r->right, indent + 3);
	for (int i = 0; i < indent; ++i)
		cout << ' ';
	cout << r->data << endl;
	f_print(r->left, indent + 3);
}

struct BTree
{
	BNode* root;
	BTree(BNode* r) :root(r) {};

	void print()
	{
		f_print(root);
	}

	BNode* left()
	{
		BNode* x = root;
		while (x->left != nullptr)
		{
			x = x->left;
		}
		return x;
	}

	void del_left()
	{
		BNode* x = root;
		BNode* y = root;
		while (x->left != nullptr)
		{
			y = x;
			x = x->left;
		}
		y->left = x->right;
		delete x;
	}

	void insert_left(int d)
	{
		BNode* x = root;
		while (x->left != nullptr)
		{
			x = x->left;
		}
		x->left = new BNode(d);
	}

	BNode* left_list()
	{
		BNode* x = root;
		while (x->left != nullptr || x->right != nullptr)
		{
			if (x->left != nullptr)
			{
				x = x->left;
			}
			else if (x->right != nullptr)
			{
				x = x->right;
			}
		}
		return x;
	}

	void del_left_list()
	{
		BNode* x = root;
		BNode* y = root;
		while (x->left != nullptr || x->right != nullptr)
		{
			y = x;
			if (x->left != nullptr)
			{
				x = x->left;
			}
			else if (x->right != nullptr)
			{
				x = x->right;
			}
		}
		if (y->left == x)
		{
			y->left = nullptr;
		}
		else if (y->right == x)
		{
			y->right = nullptr;
		}
		delete x;
	}

	BNode* second_list()
	{
		BNode* x = root;
		BNode* y = root;
		while (x->left != nullptr || x->right != nullptr)
		{
			if (x->left != nullptr)
			{
				if (x->right != nullptr)
				{
					y = x->right;
				}
				x = x->left;
			}
			else if (x->right != nullptr)
			{
				x = x->right;
			}
		}
		while (y->left != nullptr || y->right != nullptr)
		{
			if (y->left != nullptr)
			{
				y = y->left;
			}
			if (y->right != nullptr)
			{
				y = y->right;
			}
		}
		return y;
	}
};



int main()
{
	BNode* p9=new BNode(7),
		* p8=new BNode(4),
		* p7 = new BNode(13),
		* p6 = new BNode(14, p7, nullptr),
		* p5 = new BNode(6, p8, p9),
		* p4 = new BNode(1),
		* p3 = new BNode(10, nullptr, p6),
		* p2 = new BNode(3, p4, p5),
		* p1 = new BNode(8, p2, p3);
	BTree t(p1);
	t.print();
	cout << "____________________________" << endl;

	cout << t.left() << endl;
	cout << "____________________________" << endl;

	t.del_left();
	t.print();
	cout << "____________________________" << endl;

	t.insert_left(28);
	t.print();
	cout << "____________________________" << endl;

	cout << t.left_list() << endl;
	cout << "____________________________" << endl;

	t.del_left_list();
	t.print();
	cout << "____________________________" << endl;

	cout << t.second_list() << endl;

	return EXIT_SUCCESS;
}