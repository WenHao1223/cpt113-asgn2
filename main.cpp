// Run the following command to compile the program:
// g++ *.cpp -o main && ./main

#include <iostream>
using namespace std;

#include "CardNode.h"

int main () {
    CardNode cardNode;

    cardNode.insertNode("apple", "fruit", "a fruit");
    cardNode.insertNode("banana", "fruit", "a fruit");
    cardNode.insertNode("carrot", "vegetable", "a vegetable");

    cardNode.displayList();

    return 0;
}