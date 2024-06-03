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
    void editNode(string label, string question, string category, string description);

    // Searching the list
    void searchNode(string question) const;

    // Deleting the node
    void deleteNode(string question);

    // Destruct the whole list
    ~CardNode();

    // Inserting the node
    void insertNode(string label, string question, string category, string description);

    // Display each node's content
    void displayNode(string question) const;
    void displayListOneByOne() const;

    // Display the whole list
    void displayList() const;

    string getCardLabel(string question) const;
    string getCardQuestion(string question) const;
    string getCardCategory(string question) const;
    string getCardDescription(string question) const;
};