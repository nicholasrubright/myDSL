# myDSL | My Data Structure Library
This program was created to practice data structures in C++.
Some of the data structures this header contains:
* Linked List (Double & Single)
* Trees, Tries and Graph
* Stack and Queue
* Heap
* Hash Table

## Single Linked List
![linked_list_image](single_list.png)


A linked list is a linear collection of data elements, called nodes, each pointing to the next node by means of a pointer.
It is one of the simplest and most common data structures.

The first node in a linked list is known as the head and the last is the tail. The tail points to nothing (NULL) representing the end of a list, depicted by a black dot.

```c++
class SingNode {    //Node class for single linked list
    private:
        int data;   //The data that the node holds
        SingNode* next;     //A pointer to the next node of the list
    public:
        SingNode(int d, SingNode* n = NULL) {   //default constructor
            data = d;
            next = n;
        }
    friend class SingList;  //Allows the SingList class to use SingNode
};
```

The `SingList` class creates the list, it uses the nodes to form the structure. It only uses two variables which are the `head` and `tail`. The other functions are various operations that can be preformed on the list.

```c++
class SingList {
    private:
        SingNode* head;
        SingNode* tail;
    public:
        .......
    bool IsEmpty() const;   //checks if the node is empty
    int getHead() const;    //returns the value at the head of the list
    int getTail() const;    //returns the value at the tail of the list
    void addEmpty(int v);   //adds a node to a empty list
    void addtoHead(int v);  //adds a node and turns it into new head
    void addtoTail(int v);  //adds a node and turns it into new tail
        .......
};
```

## Double Linked List

