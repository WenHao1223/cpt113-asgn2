#ifndef CARDCONTENT_H
#define CARDCONTENT_H

#include <iostream>
#include <string>

using namespace std;

template <class T1, class T2>
class CardContent {
  private:
    T1 label;
    T2 question;
    string category;
    string description;

  public:
    // constructor
    CardContent();
    // destructor
    ~CardContent();

    // mutator
    void setLabel(T1 label);
    void setQuestion(T2 question);
    void setCategory(string category);
    void setDescription(string description);

    // accessor
    T1 getLabel() const;
    T2 getQuestion() const;
    string getCategory() const;
    string getDescription() const;
};

template class CardContent <string, string>;
template class CardContent <int, string>;
template class CardContent <int, float>;

#endif