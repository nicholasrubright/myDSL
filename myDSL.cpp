//myDSL.cpp file that provides a test for the library
//

#include <iostream>
#include "myDSL.h"
using namespace std;

int main()
{
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

	Stack test;
	test.Push(3);
	test.Push(2);
	test.Push(1);
	if (test.IsEmpty() == false) {
		cout << "Not empty";
	}
	else {
		cout << "Empty";
	}

	/*
	List test;
	test.addEmpty(3);
	test.addToHead(2);
	test.addToHead(1);
	cout << test.getHead() << "\n";
	cout << test.getTail();
	*/

	return 0;
}

