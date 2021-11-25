#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>

using namespace std;

template <typename T>
void print(vector<T> v)
{
	for (auto x : v)
	{
		cout << x << ' ';
	}
	cout << endl;
}

template <typename T>
void enlarge(vector<T>& v)
{
	typename vector<T>::iterator i;
	for (i = v.begin() + 1; i != v.end(); ++i)
	{
		i = v.insert(i, (*i + *(i - 1)) / 2);
		++i;
	}
	
	//почему не работает
	/*vector<double> v_new;
	vector<double>::iterator i;
	for (i = v.begin(); i != v.end(); ++i)
	{
		if (i == v.begin())
		{
			v_new.push_back(*i);
		}
		v_new.push_back((*i + *(i - 1)) / 2);
		++i;
		v_new.push_back(*i);
		print(v_new);
	}
	v = v_new;*/
}

template <typename T>
void del(vector<T>& v)
{
	typename vector<T>::iterator i;
	for (i = v.begin(); i != v.end(); ++i)
	{
		if (i + 1 == v.end())
		{
			i = v.erase(i);
			break;
		}
		i = v.erase(i);
	}
}

template <typename T>
vector<T> contact(vector<T>& v, vector<T>& v1)
{
	vector<T> q(v.size() + v1.size());
	copy(v.begin(), v.end(), q.begin());
	copy(v1.begin(), v1.end(), v.size() + q.begin());
	return q;
}

template <typename T>
vector<T> repeat(vector<T>& v, int n)
{
	vector<T> v1(v.size());
	copy(v.begin(), v.end(), v1.begin());
	while (n > 0)
	{
		v = contact(v, v1);
		--n;
	}
	return v;
}

vector<double>::iterator second_occure(vector<double>& v, double n)
{
	/*vector<double>::iterator i;
	i = find(v.begin(), v.end(), n);
	return i = find(i + 1, v.end(), n);*/
	vector<double>::iterator i = find(++find(v.begin(), v.end(), n), v.end(), n);
	return i;
}

vector<double>::iterator last_occure(vector<double>& v, double n)
{
	vector<double>::iterator i = v.begin();
	vector<double>::iterator q = v.end();
	if (find(v.begin(), v.end(), n) == v.end())
	{
		return q;
	}
	while (i != v.end())
	{
		q = i;
		i = find(++i, v.end(), n);
	} 
	return q;
}

vector<int>::iterator f1(vector<int>& v, int n)
{
	vector<int>::iterator i = upper_bound(v.begin(), v.end(), n);
	return i - 1;
}

void f2(vector<double> v, int& i, int& j, double x)
{
	vector<double>::iterator it = lower_bound(v.begin(), v.end(), x);
	vector<double>::iterator it1 = upper_bound(v.begin(), v.end(), x);
	if (it != v.end() && *it == x)
	{
		i = it - v.begin();
		j = i;
	}
	else
	{
		i = it - v.begin() - 1;
		j = it1 - v.begin();
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	vector<double> v;
	double x;
	cout << "¬ведите числа" << endl;
	while (cin >> x)
	{
		v.push_back(x);
	}
	cin.clear();
	print(v);

	//enlarge(v);
	//print(v);

	del(v);	
	print(v);

	//int n = v.size();
	//double* ar = new double[n] {0};
	//copy(v.begin(), v.end(), ar);
	//for (int i = 0; i < v.size(); ++i)
	//{
	//	cout << ar[i] << ' ';
	//}
	//cout << endl;

	//vector<double> q;
	//double w;
	//cout << "¬ведите числа" << endl;
	//while (cin >> w)
	//{
	//	q.push_back(w);
	//}
	//v = contact(v, q);
	//print(v);

	//repeat(v, 3);
	//print(v);

	//double e = 0;
	//cout << "¬ведите число дл€ поиска" << endl;
	//cin >> e;
	//vector<double>::iterator i = second_occure(v, e);
	//v.erase(i);
	//print(v);

	//double r = 0;
	//cout << "¬ведите элемент" << endl;
	//cin >> r;
	//i = last_occure(v, r);
	//v.erase(i);
	//print(v);

	//vector<int> a;
	//int t;
	//cout << "¬ведите целые числа" << endl;
	//while (cin >> t)
	//{
	//	a.push_back(t);
	//}
	//cin.clear();
	//print(a);
	//sort(a.begin(), a.end());
	//print(a);
	//int element = 0;
	//cout << "¬ведите элемент" << endl;
	//cin >> element;
	//vector<int>::iterator p = f1(a, element);
	//a.erase(p);
	//print(a);

	//int i1 = 0;
	//int j1 = 0;
	//double el = 0;
	//sort(v.begin(), v.end());
	//print(v);
	//cout << "¬ведите искомый элемент" << endl;
	//cin >> el;
	//f2(v, i1, j1, el);
	//cout << "»ндекс i: " << i1 << ", индекс j: " << j1 << endl;



	return EXIT_SUCCESS;
}