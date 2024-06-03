// Run the following command to compile the program:
// g++ *.cpp -o main && ./main

#include <iostream>
using namespace std;

#include "Card.h"
#include "CardNode.h"

int main () {
    CardNode cardNode;

    cout << "Inserting items into the list:" << endl;
    cardNode.insertNode("Apple", "fruit", "a fruit");
    cardNode.insertNode("Carrot", "vegetable", "a vegetable");
    cardNode.insertNode("Banana", "fruit", "a fruit");

    cout << "Delete carrot:" << endl;
    cardNode.deleteNode("Carrot");

    cout << "Item left in the list:" << endl;
    cardNode.displayList();

    cout << "Searching for apple:" << endl;
    cardNode.searchNode("Apple");
    cout << endl;

    cout << "Editing banana:" << endl;
    cardNode.editNode("Banana", "fruit", "a fruit that is yellow");

    cout << "Displaying banana:" << endl;
    cardNode.displayNode("Banana");

    return 0;
}