#include <iostream>
#include <string>
using namespace std;

#include "CardContent.h"

template <class T1, class T2>
CardContent<T1,T2>::CardContent() {
  category = "";
  description = "";
}

template <class T1, class T2>
CardContent<T1,T2>::~CardContent() {}

template <class T1, class T2>
void CardContent<T1,T2>::setLabel(T1 label) {
  this->label = label;
}

template <class T1, class T2>
void CardContent<T1,T2>::setQuestion(T2 question) {
  this->question = question;
}

template <class T1, class T2>
void CardContent<T1,T2>::setCategory(string category) {
  this->category = category;
}

template <class T1, class T2>
void CardContent<T1,T2>::setDescription(string description) {
  this->description = description;
}

template <class T1, class T2>
T1 CardContent<T1,T2>::getLabel() const {
  return label;
}

template <class T1, class T2>
T2 CardContent<T1,T2>::getQuestion() const {
  return question;
}

template <class T1, class T2>
string CardContent<T1,T2>::getCategory() const {
  return category;
}

template <class T1, class T2>
string CardContent<T1,T2>::getDescription() const {
  return description;
}