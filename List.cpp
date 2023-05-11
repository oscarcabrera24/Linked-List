#include <iostream>
#include "List.h"
using namespace std;

// Delete function
void Linked_List::del(string d) {
    
    Node *current = head;          // *current will traverse the list for us
    Node *previous = nullptr;      // *prev will keep track of one step back
    if (head) {                    // if the list has at least one element
                                   // if the list is empty, do nothing
                                   // determine if the first node has the search term
        if (head->value == d) {
            count--;
            current = head->next;  // advance t
            delete head;           // deletes the note head is pointing to
            head = current;        // head points to the new head
        }
        else {                     // otherwise we traverse until we find it
            current = head;
            while (current and current->value != d) {
                previous = current;
                current = current->next;
            }
            // at this point, if current isn't at the end of the list,
            // link the previous node to the next node and 
            // delete the current node
            if (current) {
                count--;
                previous->next = current->next;
                delete current;
                cout << "Deleted term " << d << endl; // Delete the term I select
            }
        }
    }
}

// Add Front function
void Linked_List::addFront(string af) {
    Node *new_node = new Node;
    if (count == 0) { //if this is the first node, it's the new head
        cout << "Now adding " << af << " as the new head.\n";
        head = new_node;
        new_node->next = nullptr;
        new_node->value = af;
    }
    else {
        cout << "Now adding " << af << " to the head.\n";
        new_node->next = head;
        new_node->value = af;
        head = new_node;
    }
    count++;
}

// Add Back function
void Linked_List::addBack(string ab) {
    Node *new_node = new Node;   // create a new node
    Node *p = head;  // point to first element in myValues
    if (count == 0) { //if this is the first node, it's the new head
        cout << "Now adding " << ab << " as the new head.\n";
        head = new_node;
        new_node->next = nullptr;
        new_node->value = ab;
    }
    else {  // traverse to end
        while (p->next)
            p = p->next;
        cout << "Now pointing to last list element: " << p->value << endl;
        cout << "Now adding " << ab << " to the end.\n";
        new_node->value = ab;
        new_node->next = nullptr;
        p->next = new_node;
    }
    count++;
}

// Output Function
void Linked_List::output(){
    Node *q = head;
	cout << "\nOutputting dynamic array of names:\n\t";
	while (q) {    // this is equivalent to "while (q != nullptr)"
		cout << q->value << " ";
		q = q->next;
	}
	cout << "\n" << endl;
}

// Delete function for the name I want to delete
void Linked_List::del(){
    Node *p = head; // Looking at the first node
    
    for(int i = 0; i < count; i++){
        cout << "[" << i + 1 << "]" << p->value << endl;
        p = p->next; // Looking at p (first node) and then the next node
    }
    cout << "\nEnter number of name to be deleted: ";

    int userChoice;
    cin >> userChoice;
    // UserChoice between 1 to whatever the count allows
    while (cin.fail() || userChoice < 1 || userChoice > count) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
        }
        cout << "\nError:  1 to " << count << " only: ";
        cin >> userChoice;
    }
    
    Node *current = head;
    Node *previous = nullptr;

    if(head){
        if (userChoice == 1) {
            string d = current->value; // Value that will deleted
            count--;
            current = head->next;  // advance to the next node
            delete head;           // deletes the note head is pointing to
            head = current;        // head points to the new head

            cout << "Deleted term " << d << endl;
        }
        else {                     // otherwise we traverse until we find it
            current = head;
            for(int i = 0; i < userChoice - 1; i++){ // fewer times
                previous = current;
                current = current->next;
            }
            // at this point, if current isn't at the end of the list,
            // link the previous node to the next node and 
            // delete the current node
            if (current) {
                string d = current->value; // Value that will be deleted
                count--;
                previous->next = current->next;
                delete current;
                cout << "Deleted term " << d << endl; // Delete the term I select
            }
        }
    }
}
