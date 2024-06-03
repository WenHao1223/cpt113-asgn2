#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

using namespace std;

class Card {
  private:
    string label;
    string question;
    string category;
    string description;

    Card *next;
    Card *prev;

  public:
    // constructor
    Card();
    // destructor
    ~Card();

    // mutator
    void setQuestion(string question);
    void setLabel(string label);
    void setCategory(string category);
    void setDescription(string description);
    void setNext(Card *next);
    void setPrev(Card *prev);

    // accessor
    string getLabel() const;
    string getQuestion() const;
    string getCategory() const;
    string getDescription() const;

    Card *getNext() const;
    Card *getPrev() const;
};

#endif