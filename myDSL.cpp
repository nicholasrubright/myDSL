//myDSL.cpp file that provides a test for the library
//

#include <iostream>
#include <ctime>
#include "myDSL.h"
using namespace std;

int main() {

	TreeNode* c = new TreeNode(9);
	TreeNode* e = new TreeNode(8);
	TreeNode* d = new TreeNode(5, c, e);
	TreeNode* a = new TreeNode(4);
	TreeNode* b = new TreeNode(2, a, d);
	TreeNode* h = new TreeNode(7);
	TreeNode* i = new TreeNode(6, h, NULL);
	TreeNode* g = new TreeNode(3, NULL, i);
	TreeNode* f = new TreeNode(1, b, g);
	BTree tree(f);

	tree.BreadthFirst();
	

	/*
	List test;
	for (int i = 0; i < 10; i++) {
		test.addToHead(i);
	}
	test.displayValues();

	//	*<-[9]<->[8]<->[7]...
	/*
	clock_t time_req1;

	//time_req1 = clock();
	SingList test1;
	time_req1 = clock();
	for (int i = 0; i < 10000000; i++)
	{
		test1.addtoHead(i);
	}
	test1.delTail();
	time_req1 = clock() - time_req1;

	clock_t time_req2;

	//time_req2 = clock();
	List test2;
	time_req2 = clock();
	for (int i = 0; i < 10000000; i++)
	{
		test2.addToHead(i);
	}
	test2.delTail();
	time_req2 = clock() - time_req2;

	cout << "Single Linked List Test: " << (float)time_req1 / CLOCKS_PER_SEC << " seconds" << endl;
	cout << "Double Linked List Test: " << (float)time_req2 / CLOCKS_PER_SEC << " seconds" << endl;

	/*
	SingList test;

	test.addEmpty(1);
	test.addtoTail(2);
	test.addtoTail(3);
	
	//cout << test.getHead() << "\n";
	//cout << "Now calling destructor\n";
	//test.~SingList();	//calling a destructor explicitly
	

	/*
	List test;


	test.addEmpty(1);
	test.addToTail(2);
	test.addToTail(3);
	test.addToTail(4);
	test.addToTail(5);
	test.delHead();
	int h = test.getHead();

	int length = test.getLength();
	cout << length;
	cout << endl;
	cout << h << endl;
	cout << test.getSum() << endl; // should be 14
	test.displayValues();
	*/
	/*
	clock_t time_req;

	time_req = clock();
	Stack test;
	test.Push(3);
	test.Push(2);
	test.Push(1);
	int a = test.Pop();
	cout << a << endl;
	time_req = clock() - time_req;
	cout << "Time: " << (float)time_req / CLOCKS_PER_SEC << " seconds" << endl;

	/*
	List test;
	test.addEmpty(3);
	test.addToHead(2);
	test.addToHead(1);
	cout << test.getHead() << "\n";
	cout << test.getTail();
	*/
	/*
	Queue test;
	test.Enqueue(1);
	test.Enqueue(2);
	test.Enqueue(3);
	int a = test.Dequeue();
	cout << a << "\n";
	int b = test.Dequeue();
	cout << b;
	*/

	return 0;
}

