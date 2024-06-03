#include <iostream>
#include <string>
using namespace std;

#include "CardContent.h"

template <class T1, class T2>
class CardNode {
  private:
    struct Card {
      CardContent <T1, T2> content;
      Card *next;
      Card *prev;
    };
    Card *head;
    Card *tail;

  public:
    // Initializing the list
    CardNode();

    // Editing the content of the list node
    void editNode(T1 label, T2 question, string category, string description);

    // Searching the list
    void searchNode(T2 question) const;

    // Deleting the node
    void deleteNode(T2 question);

    // Destruct the whole list
    ~CardNode();

    // Inserting the node
    void insertNode(T1 label, T2 question, string category, string description);

    // Display each node's content
    void displayNode(T2 question) const;
    void displayListOneByOne() const;

    // Display the whole list
    void displayList() const;

    T1 getCardLabel(T2 question) const;
    T2 getCardQuestion(T2 question) const;
    string getCardCategory(T2 question) const;
    string getCardDescription(T2 question) const;
};