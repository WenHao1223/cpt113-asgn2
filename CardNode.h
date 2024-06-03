#include <iostream>
using namespace std;

#include "Card.h"

class CardNode {
  private:
    Card card;

    Card *head;
    Card *tail;

  public:
    // Initializing the list
    CardNode();

    // Editing the content of the list node
    void editNode(string question, string category, string description);

    // Searching the list
    void searchNode(string question) const;

    // Deleting the node
    void deleteNode(string question);

    // Destruct the whole list
    ~CardNode();

    // Inserting the node
    void insertNode(string question, string category, string description);

    // Display each node's content
    void displayNode(string question) const;

    // Display the whole list
    void displayList() const;

};