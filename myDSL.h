//C++ Data Structure Library
//Contains Linked Lists, Trees, Tries, Graphs, Stack, Queue, Heap, and Hash Tables
#include <iostream>
#include <assert.h>
#include <queue>	//for breadthfirst
using namespace std;


//Single Linked List
class SingNode {	//Single linked list
private:
	int data;	//variable for storing the data
	SingNode* next;	//pointer to the next node in the list
public:
	SingNode(int d, SingNode* n = NULL)	//default argument	
	{
		data = d;
		next = n;
	}
	friend class SingList;
};

class SingList {
private:
	SingNode* h;
	SingNode* t;
public:
	SingList();				//default constructor for the linked list
	~SingList();			//deconstructor for linked list
	bool IsEmpty() const;	//checks if the node is empty
	int getHead() const;	//returns the value at the head of the list
	int getTail() const;	//returns the value at the tail of the list
	void addEmpty(int v);	//adds a node to a empty list
	void addtoHead(int v);	//adds a node and turns it into new head
	void addtoTail(int v);	//adds a node and turns it into new tail
	void addAfter(SingNode* q, int v);	//adds a node after a specified node in the list

	void delHead();	//deletes the head of the list (also can't be const,since it needs to be modifiable)
	void delTail();	//deltes the tail of the list
	void removeValue(int v);	//removes the node with a certain value
	void removeLast();	//removes the last node in the list

	bool hasLast() const;	//Checks if a list only has one element
	SingNode* searchPrev(SingNode* q) const;	//Search a node whose next is q

	//Additional operations
	void Clear();				//remove allnodes
	int removeAll(int v);		//remove all nodes whose value is v, and return the number of nodes removed
	SingNode* Search(int v) const;	//return Node* whose value is v, returns NULL if there is no such node
	int Length() const;			//return length of the list
	int countData(int v) const;	//return how manyv are in the list
};

SingList::SingList() {	//creates an empty list
	h = t = NULL;	//sets the head and tail to null
}

SingList::~SingList() {	//deletes a list
	
	while (IsEmpty() == false) {	//while the list is not empty
		delHead();	//deletes the head until the list is gone
	}

	/*	Without using the delHead() function
	while (h != NULL) {
		SingNode* r = h;
		h = h->next;
		delete r;
	}
	*/
}

bool SingList::IsEmpty() const {	//checks if the list is empty
	if (h && t == NULL)	//if both head and tail are null
		return true;	//then the list is empty
	return false;		//else it is not empty
}

int SingList::getHead() const {	//returns value of the head node
	assert(h != NULL);	//checks if h has a value
	return h->data;		//returns the value of h
	
	//return (*h).data;	//this is the same thing as h->data
}

int SingList::getTail() const {	//returns the value of the tail node
	assert(t != NULL);	//checks if t has a value
	return t->data;		//returns the value of t
}

void SingList::addEmpty(int v) {	//adds a new node to the list
	SingNode* r = new SingNode(v);	//creates new node with value given
	h = r;	//sets new node to head of list
	t = r;	//sets new node to tail of list
	r->next = NULL;	//sets the next pointer to null since nothing else in list
}

void SingList::addtoHead(int v) {	//adds new node to list and makes it new head
	if (IsEmpty() == true)	//checks if the list is empty
	{
		addEmpty(v);	//adds the value to empty if it is true
	}
	else
	{
		SingNode* r = new SingNode(v);	//creates new node with given value
		r->next = h;	//points the new node's next pointer to previous head
		h = r;	//h is now new node
	}
}

void SingList::addtoTail(int v) {	//adds new node to list and makes it new tail
	if (IsEmpty() == true)	//checks if the list is empty
	{
		addEmpty(v);	//adds the value to empty if it is true
	}
	else
	{
		SingNode* r = new SingNode(v);	//creates new node with given value
		r->next = NULL;	//points the next to null since it's at the end of the list
		t->next = r;	//previous tail pointer now points to new node
		t = r;	//sets the tail to new node
	}
}

void SingList::addAfter(SingNode* q, int v) {	//adds a new node to the list after a certain node in the list
	assert(IsEmpty() != true);	//checks if the list is empty
	SingNode* r = new SingNode(v);	//creates new node with given value
	r->next = q->next;	//new node points to what the given node was pointing at
	q->next = r;	//given node now points to new node
}

void SingList::delHead()  {
	//assert(IsEmpty() != true);	//not needed?
	SingNode* r = h;	//creates r pointer then points to head node
	h = h->next;	//new head is the next node in list
	delete r;	//deletes the old head from list

}

/***************************************************************************************************************************/

//Double Linked List
class Node {		//Node class I utilize from my CMPSC Course
private:			 
	int data;		//Data value of a node that will contain the actual value in the node
	Node* next;		//Next pointer of a node to move to the next node in the list
	Node* prev;		//Previous pointer of a node that will move to the previous node in the list
public:
	Node(int d, Node* n = NULL, Node* p = NULL)		//Nodes will have a data value, a next pointer and a previous pointer
	{
		data = d;			//assigns the values and pointers to it's respected assignment
		next = n;
		prev = p;
	}
	friend class List;
	friend class mQueue;
};

class List {			//List class utilized from CMPSC Course
private:
	Node* head;			//Pointers in the list to signify the beginning node
	Node* tail;			//Pointer in the list to signify the last node
public:
	List();		//Intitalizes a empty list
	~List();	//Destructor for list
	bool IsEmpty() const; //creates an empty list
	int getHead() const; //returns the head of the list
	int getTail() const; //returns the tail of the list
	void addEmpty(int v); //adds an element to an empty list
	void addToHead(int v); //adds an element to the front of the list
	void addToTail(int v); //adds an element to the back of the list
	void addAfter(Node* q, int v); //adds an element after a specified node
	int getHead();	//returns the value of the head node in the list
	int getTail();	//returns the value of the tail node in the list
	
	void delNode(Node* q);	//deletes a specified node from the list, Can't because a node is only defined by the value inside(del value?)
	void delHead();	//deletes the head node from the list
	void delTail();	//deletes the tail node from the list

	bool HasOne() const;	//Checks if a list has only one element
	void RemoveLast();		//Remove the last element (when the list only has one element)

	void Clear();	

	//Custom operations I designed using skills I learned from class

	int getLength() const;	//Returns the length of a Linear List by counting the individual nodes
	int getSum();		//Returns the sum of the node's values
	void condenseList(); //Combines two nodes into one by adding the values
	void changeValue(Node* q, int v);	//Changes the value of a node, again can't unless we know the individual nodes
	void deleteValue(int v);	//searches for value and deletes the node with the value
	int countValue(int v);	//counts the number of iterations a certain value appears in the list
	void displayValues();	//prints the values of the list

	friend class Queue;
	friend class Stack;
};

List::List() {
	head = tail = NULL;		//Creates an empty list
}

List::~List()	//Destructor for list
{
	while (IsEmpty() == false)
	{
		delHead();
	}
}

bool List::IsEmpty() const	//returns if a list is empty
{
	return (head == NULL);			//or return false since there is element(s) in the list
}

int List::getHead() const
{
	return head->data;	//return the value at the head of the list
}

int List::getTail() const
{
	return tail->data;	//returns the value of the tail of the list
}

void List::addEmpty(int v)	//Checks if the list is empty, then adds a new node
{
	//assert(IsEmpty() == true);	//Checks if the list is empty
	Node* r = new Node(v);	//Creates a new node
	r->next = NULL;	//r next pointer is set to NULL
	r->prev = NULL;	//r previous pointer is set to NULL
	head = tail = r;	//head and tail are set to r

}

void List::addToHead(int v)	//adds a value to the start of the list
{
	if (IsEmpty() == true) {
		addEmpty(v);
	}
	else {
		Node* r = new Node(v);	//creates new node
		//head->prev = r;	//the old head's prev pointer points to new node
		r->next = head;	//the new node next pointer points to the old head;
		head->prev = r;
		head = r;	//sets head to new node
	}
}

void List::addToTail(int v)	//adds a new node to the end of a list
{
	if (IsEmpty() == true)
	{
		addEmpty(v);
	}
	else {
		Node* r = new Node(v);	//created new node with value
		r->prev = tail;
		tail->next = r;
		tail = r;
	}
}

void List::addAfter(Node* q, int v)
{
	Node* r = new Node(v);	//creates a new node
	r->next = q->next;	//the next value of the new node points to the next value of the specified node
	q->next = r;	//next value of q is set to r
	r->prev = q;	//r previous pointer is set to q
}

void List::delHead()	//moves the head to the next node and deletes old head
{
	Node* r = head;		//creates a new node pointer to the head node
	head = head->next;	//moves the head of the list to the next node
	head->prev = NULL;	//makes the new head's prev pointer NULL
	delete r;			//deletes the old head node
}

void List::delTail()	//moves the tail to the previous node
{
	Node* r = tail;		//creates a new node pointer to the head node
	tail = tail->prev;	//moves the tail of the list to the next node
	tail->next = NULL;	//makes the new tail's next pointer NULL
	delete r;			//deletes the old tail node
}

int List::getHead()
{
	return head->data;	//returns the value of the head node
}

int List::getTail()
{
	return tail->data;	//returns the value of the tail node
}

bool List::HasOne() const	//Returns boolean whether it has only one element in list
{
	if (head == NULL)		//Checks if the head is set to null
		return false;		//returns false since means no elements in List
	if (head == tail)		//checks if the head and tail are the same node
		return true;		//which means that there is only one node in the list
	return false;			//returns false for any other condition
}

void List::RemoveLast()		//Removes the last element in the List (Should be only element)
{
	delete head;			//Deletes the head pointer
	head = tail = NULL;		//Resets the list to NULL
}


int List::getLength() const	//returns the number of nodes
{
	int counter = 1;	//counter for each node	
	Node* r = head;		//Create node that starts at the head

	if (IsEmpty() == true)	//determines if the list is empty
	{
		return counter - 1;	//set the counter to 1 less to show there is no list
	}
	else
	{
		while (r != NULL)	//while loop until the node next pointer is NULL
		{
			r = r->next;	//switches r to the next r next node
			counter++;		//increment counter by one
		}
	}
	return counter;		//returns the counter number
}

int List::getSum()		//Returns the sum of the List
{
	int sum = 0;		//intializes the sum to 0
	Node* r = head;		//Create a new node pointer and set it to point to the head node

	if (IsEmpty() == true)		//checks the the list is empty
	{
		return 0;				//returns 0 since the list doesn't have any elements
	}
	else
	{
		while (r != NULL)		//while loop to run until the last node
		{
			sum = sum + r->data;		//Take the sums and adds the node's value to it
			r = r->next;				//Moves the pointer to the next node
		}
	}
	return sum;			//returns the sum of the list
}

void List::displayValues()			//Prints out the contents of the nodes(Plan to update the way its printed to show the structure more)
{
	Node* r = head;			//Creates a new node and makes it point to the head node
	while (r != NULL)		//Loop to go through the list
	{
		cout << r->data << ", ";	//Prints out the value of node
		r = r->next;				//moves the pointer to the next node
	}
}

/*************************************************************************************************************/

//Stack
class Stack {
private:
	List list;	//Uses double linked list
public:
	Stack();	//Constructor for stack
	~Stack();	//Destructor for Stack (Utilizes the clear operator from the linked list)

	void Push(int el);	//Pushes element ontop of stack
	int Pop();	//takes the top element off and returns the value of it
	int Top() const;	//returns top element value
	bool IsEmpty() const;	//checks if the stack is empty
	void Clear();	//removes all the elements
};

Stack::Stack() {
	
}

Stack::~Stack() {
	Clear();
}

void Stack::Push(int el) {
	list.addToHead(el);
}

int Stack::Pop() {
	int t = Top();
	list.delHead();
	return t;
	/*
	return l.getHead();
	l.delHead;
	*/
}

int Stack::Top() const {
	return list.getHead();
}

bool Stack::IsEmpty() const {
	return list.IsEmpty();
}

void Stack::Clear() {
	while (IsEmpty() == false) {
		Pop();
	}
	//l.~List(); //This would delete the whole list and not just clear it out
}

/****************************************************************************************************/

//Queue
class Queue {
private:
	List l;
public:
	Queue() {};
	~Queue() { Clear(); };

	void Enqueue(int el);
	int Dequeue();
	bool IsEmpty() const;
	void Clear();
};

void Queue::Enqueue(int el) {
	l.addToTail(el);
}

int Queue::Dequeue() {
	int first = l.getHead();
	l.delHead();
	return first;
}

bool Queue::IsEmpty() const {
	return l.IsEmpty();
}

void Queue::Clear() {
	while (IsEmpty() == false)
		Dequeue();
}

/*************************************************************************************************/

//Binary Tree
class TreeNode {
private:
	int value;
	TreeNode* left;
	TreeNode* right;
public:
	TreeNode(int v) {
		value = v;
		left = right = NULL;
	}
	TreeNode(int v, TreeNode* l, TreeNode* r) {
		value = v;
		left = l;
		right = r;
	}
	friend class BTree;
};

class BTree {
private:
	TreeNode* root;
public:
	BTree(TreeNode* r) {
		root = r;
	}

	bool IsEmpty() const;
	void Clear(TreeNode* n);

	int getHeight() const;
	int countNodes() const;
	TreeNode* getParent(TreeNode* n) const;
	int countLeaves() const;
	int findMin() const;
	int findMax() const;


};
