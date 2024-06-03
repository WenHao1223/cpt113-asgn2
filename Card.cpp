#include "Card.h"

#include <iostream>
using namespace std;

Card::Card() {
  leadingChar = 'A';
  vocab = "";
  category = "";
  next = nullptr;
  prev = nullptr;
}

Card::~Card() {
  cout << "Card " << vocab << " is deleted." << endl;
}

void Card::setVocab(string vocab) {
  this->vocab = vocab;
}

void Card::setLeadingChar(char leadingChar) {
  // change it to upper case
  if (this->leadingChar >= 'a' && this->leadingChar <= 'z') {
    this->leadingChar -= 32;
  }
}

void Card::setCategory(string category) {
  this->category = category;
}

void Card::setDefinition(string definition) {
  this->definition = definition;
}

void Card::setNext(Card *next) {
  this->next = next;
}

void Card::setPrev(Card *prev) {
  this->prev = prev;
}

char Card::getLeadingChar() const {
  return leadingChar;
}

string Card::getVocab() const {
  return vocab;
}

string Card::getCategory() const {
  return category;
}

string Card::getDefinition() const {
  return definition;
}

Card *Card::getNext() const {
  return next;
}

Card *Card::getPrev() const {
  return prev;
}