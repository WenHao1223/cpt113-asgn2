#include "CardContent.h"

#include <iostream>
using namespace std;

CardContent::CardContent() {
  label = "";
  question = "";
  category = "";
  description = "";
}

CardContent::~CardContent() {}

void CardContent::setQuestion(string question) {
  this->question = question;
}

void CardContent::setLabel(string label) {
  this->label = label;
}

void CardContent::setCategory(string category) {
  this->category = category;
}

void CardContent::setDescription(string description) {
  this->description = description;
}

string CardContent::getLabel() const {
  return label;
}

string CardContent::getQuestion() const {
  return question;
}

string CardContent::getCategory() const {
  return category;
}

string CardContent::getDescription() const {
  return description;
}