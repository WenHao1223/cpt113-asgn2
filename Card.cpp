#include "Card.h"

#include <iostream>
using namespace std;

Card::Card() {
  label = "";
  question = "";
  category = "";
  next = nullptr;
  prev = nullptr;
}

Card::~Card() {
  cout << "Card " << question << " is deleted." << endl;
}

void Card::setQuestion(string question) {
  this->question = question;
}

void Card::setLabel(string label) {
  this->label = label;
}

void Card::setCategory(string category) {
  this->category = category;
}

void Card::setDescription(string description) {
  this->description = description;
}

void Card::setNext(Card *next) {
  this->next = next;
}

void Card::setPrev(Card *prev) {
  this->prev = prev;
}

string Card::getLabel() const {
  return label;
}

string Card::getQuestion() const {
  return question;
}

string Card::getCategory() const {
  return category;
}

string Card::getDescription() const {
  return description;
}

Card *Card::getNext() const {
  return next;
}

Card *Card::getPrev() const {
  return prev;
}