//Name: Oscar Cabrera
//Date; 04/25/2023
// Linked List Adaptation

#include <iostream>
#include "List.h"
#include <fstream>
using namespace std;

int main() {
    srand(time(0));

    ifstream fin("namesXS.txt");
    string name;

    //Linked List of names
    Linked_List namesList = Linked_List();

    int randNum = rand() % (15 - 5 + 1) + 5;

    // The size of the linked list between 5-15
    for(int i = 0; i < randNum; i++){
        fin >> name;
        namesList.addFront(name); // It will add it to the front
     }

    fin >> name; // Getting the name form the file

    // For loop the All Caps names for the Add Back 
    for(int i = 0; i < name.length(); i++){
        name[i] = toupper(name[i]);
    }
     namesList.addBack(name); // Output the Add Back Function

    fin >> name;

    // For loop the All Caps names for the Add Front 
    for(int i = 0; i < name.length(); i++){
        name[i] = toupper(name[i]);
    }
    namesList.addFront(name); // Output the Add Front Function

    //Output the list
    namesList.output(); // Output function

    // Delete current name
    namesList.del();
    namesList.output();
    

    return 0;

}
