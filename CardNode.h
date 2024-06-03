#include <iostream>
using namespace std;

class CardNode {
  private:
    struct Card {
      char leadingChar;
      string vocab;
      string category;
      string definition;

      Card *next;
      Card *prev;
    };

    Card *head;
    Card *tail;

  public:
    // Initializing the list
    CardNode();

    // Editing the content of the list node
    void editNode(string vocab, string category, string definition);

    // Searching the list
    void searchNode(string vocab) const;

    // Deleting the node
    void deleteNode(string vocab);

    // Destruct the whole list
    ~CardNode();

    // Inserting the node
    void insertNode(string vocab, string category, string definition);

    // Display each node's content
    void displayNode(string vocab) const;
    
    // Display the whole list
    void displayList() const;

};