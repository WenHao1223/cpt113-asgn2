#ifndef CARDCONTENT_H
#define CARDCONTENT_H

#include <iostream>
#include <string>

using namespace std;

class CardContent {
  private:
    string label;
    string question;
    string category;
    string description;

  public:
    // constructor
    CardContent();
    // destructor
    ~CardContent();

    // mutator
    void setQuestion(string question);
    void setLabel(string label);
    void setCategory(string category);
    void setDescription(string description);

    // accessor
    string getLabel() const;
    string getQuestion() const;
    string getCategory() const;
    string getDescription() const;
};

#endif