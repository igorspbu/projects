#include<iostream>
#include "LinkedList.h"

using namespace std;

void printList(LinkedList list)
{
	cout << "PRINTED LIST : " << list << endl << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	/* (1) */
	LinkedList list0;
	cout << "Для списка без элементов" << endl;
	cout << list0.extractHead() << endl;
	cout << list0.extractTail() << endl;
	cout << list0.extract(1234) << endl;
	list0 -= 2;
	cout << list0 << endl;
	cout << list0.indexOf(12) << endl;
	cout << list0.contains(132) << endl;
	cout << endl << "Для списка с 1 элементом" << endl;

	/* (2) */
	LinkedList list1;
	list1.addToHead(5);
	cout << list1.extractHead() << endl;
	list1.addToHead(5);
	cout << list1.extractTail() << endl;
	cout << list1.extract(1234) << endl;
	list1 -= 2;
	cout << list1 << endl;
	cout << list1.indexOf(5) << endl;
	cout << list1.contains(132) << endl;
	cout << endl << "Для списка с некоторым количеством элементов элементом" << endl;

	/* (3) */
	LinkedList list2;
	list2.addToHead(47);
	list2.addToHead(128);
	list2.addToHead(5);
	list2.addToHead(4);
	list2.addToHead(3);
	list2.addToHead(2);
	list2.addToHead(1);
	cout << list2 << endl;
	cout << list2.extractHead() << endl;
	cout << list2 << endl;
	cout << list2.extractTail() << endl;
	cout << list2 << endl;
	cout << list2.extract(3) << endl;
	cout << list2 << endl;
	cout << list2.extract(-321) << endl;
	list2 -= 1;
	cout << list2 << endl;
	cout << list1.indexOf(128) << endl;
	cout << list1.contains(3) << endl;

	return 0;
}