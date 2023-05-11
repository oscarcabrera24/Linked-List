#ifndef LIST_H
#define LIST_H
#include <iostream>
using namespace std;

struct Node {
	string value;
	Node *next;
};

// Class header
class Linked_List{
private:
        Node *head;
        Node *tail;
        int count;

public:
        //Methods prototypes
        void del(string d);
        void addFront(string af);
        void addBack(string ab);
        void output();
        void del();

        Linked_List()  {head = nullptr; tail = nullptr; count = 0;} // returning values from the Linked list class
        
};

#endif
