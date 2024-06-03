#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

using namespace std;

class Card {
  private:
    char leadingChar;
    string vocab;
    string category;
    string definition;

    Card *next;
    Card *prev;

  public:
    // constructor
    Card();
    // destructor
    ~Card();

    // mutator
    void setVocab(string vocab);
    void setLeadingChar(char leadingChar);
    void setCategory(string category);
    void setDefinition(string definition);
    void setNext(Card *next);
    void setPrev(Card *prev);

    // accessor
    char getLeadingChar() const;
    string getVocab() const;
    string getCategory() const;
    string getDefinition() const;

    Card *getNext() const;
    Card *getPrev() const;
};

#endif