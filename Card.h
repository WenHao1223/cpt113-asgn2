#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

using namespace std;

class Card {
  private:
    char label;
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
    void setLabel(char label);
    void setCategory(string category);
    void setDescription(string description);
    void setNext(Card *next);
    void setPrev(Card *prev);

    // accessor
    char getLabel() const;
    string getQuestion() const;
    string getCategory() const;
    string getDescription() const;

    Card *getNext() const;
    Card *getPrev() const;
};

#endif