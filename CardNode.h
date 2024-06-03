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
    CardNode();
    ~CardNode();

    void insertNode(string vocab, string category, string definition);
    void deleteNode(string vocab);

    void searchNode(string vocab) const;
    void editNode(string vocab, string category, string definition);

    void displayList() const;
    void displayNode(string vocab) const;

};