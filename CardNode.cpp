#include "CardNode.h"

#include <iostream>
#include <iomanip>
using namespace std;

CardNode::CardNode() {
  head = nullptr;
  tail = nullptr; 
}

void CardNode::editNode (string label, string question, string category, string description) {
  try {
    if (label == "") {
      cout << endl << "Error: Label cannot be empty." << endl;
      return;
    }

    if (question == "") {
      cout << endl << "Error: Question / Vocabulary cannot be empty." << endl;
      return;
    }

    if (category == "") {
      cout << endl << "Error: Category cannot be empty." << endl;
      return;
    }

    if (description == "") {
      cout << endl << "Error: Description cannot be empty." << endl;
      return;
    }
  } catch (string exceptionString) {
    cout << exceptionString;
    return;
  };

  Card *nodePtr;
  nodePtr = head;

  while (nodePtr != nullptr && nodePtr->getQuestion() != question) {
    nodePtr = nodePtr->getNext();
  }

  if (nodePtr) {
    nodePtr->setCategory(category);
    nodePtr->setDescription(description);
  } else {
    cout << "Question / Vocabulary not found." << endl;
  }
}

void CardNode::searchNode (string question) const {
  try {
    if (question == "") {
      cout << endl << "Error: Question / Vocabulary cannot be empty." << endl;
      return;
    }
  } catch (string exceptionString) {
    cout << exceptionString;
    return;
  }

  
  Card *nodePtr;
  nodePtr = head;

  while (nodePtr != nullptr && nodePtr->getQuestion() != question) {
    nodePtr = nodePtr->getNext();
  }

  if (nodePtr) {
    string border = "+------------------------------------------------------------------------------------------------------+";

    cout << border << endl;
    cout << "| " << setw(100) << left << nodePtr->getLabel() << " |" << endl;
    cout << "| " << setw(100) << left << " " << " |" << endl;
    cout << "| " << setw(100) << left << nodePtr->getQuestion() << " |" << endl;
    cout << "| " << setw(100) << left << ("<" + nodePtr->getCategory() + ">") << " |" << endl;
    cout << "| " << setw(100) << left << " " << " |" << endl;
    cout << "| " << setw(100) << left << nodePtr->getDescription() << " |" << endl;
    cout << border << endl;
  } else {
    cout << "Question not found." << endl;
  }
}

void CardNode::deleteNode (string question) {
  try {
    if (question == "") {
      cout << endl << "Error: Question / Vocabulary cannot be empty." << endl;
      return;
    }
  } catch (string exceptionString) {
    cout << exceptionString;
    return;
  }

  Card *nodePtr;
  Card *previousNode;

  if (!head) {
    return;
  }

  if (head->getQuestion() == question) {
    nodePtr = head->getNext();
    delete head;
    head = nodePtr;
  } else {
    nodePtr = head;

    while (nodePtr != nullptr && nodePtr->getQuestion() != question) {
      previousNode = nodePtr;
      nodePtr = nodePtr->getNext();
    }

    if (nodePtr) {
      previousNode->setNext(nodePtr->getNext());
      delete nodePtr;
    }
  }
}

CardNode::~CardNode() {
  Card *nodePtr;
  Card *nextNode;

  nodePtr = head;

  while (nodePtr != nullptr) {
    nextNode = nodePtr->getNext();
    delete nodePtr;
    nodePtr = nextNode;
  }
}

void CardNode::insertNode (string label, string question, string category, string description) {
  try {
    if (label == "") {
      cout << endl << "Error: Label cannot be empty." << endl;
      return;
    }

    if (question == "") {
      cout << endl << "Error: Question / Vocabulary cannot be empty." << endl;
      return;
    }

    if (category == "") {
      cout << endl << "Error: Category cannot be empty." << endl;
      return;
    }

    if (description == "") {
      cout << endl << "Error: Description cannot be empty." << endl;
      return;
    }
  } catch (string exceptionString) {
    cout << exceptionString;
    return;
  }

  Card *newNode;
  Card *nodePtr;
  Card *previousNode = nullptr;

  newNode = new Card;

  newNode->setLabel(label);
  newNode->setQuestion(question);
  newNode->setCategory(category);
  newNode->setDescription(description);

  if (!head) {
    head = newNode;
    newNode->setNext(nullptr);
    newNode->setPrev(nullptr);
    tail = newNode;
  } else {
    nodePtr = head;
    previousNode = nullptr;

    while (nodePtr != nullptr && nodePtr->getLabel() < label) {
      previousNode = nodePtr;
      nodePtr = nodePtr->getNext();
    }

    // check if next node has the same label and order according to question
    while (nodePtr != nullptr && nodePtr->getLabel() == label && nodePtr->getQuestion() < question) {
      previousNode = nodePtr;
      nodePtr = nodePtr->getNext();
    }

    if (previousNode == nullptr) {
      head = newNode;
      newNode->setNext(nodePtr);
      newNode->setPrev(nullptr);
      if (nodePtr != nullptr) {
        nodePtr->setPrev(newNode);
      }
    } else {
      previousNode->setNext(newNode);
      newNode->setPrev(previousNode);
      newNode->setNext(nodePtr);

      if (nodePtr != nullptr) {
        nodePtr->setPrev(newNode);
      } else {
        tail = newNode;
      }
    }
  }
}

void CardNode::displayNode(string question) const {
  Card *nodePtr;
  nodePtr = head;

  while (nodePtr != nullptr && nodePtr->getQuestion() != question) {
    nodePtr = nodePtr->getNext();
  }

  if (nodePtr) {
    string border = "+------------------------------------------------------------------------------------------------------+";

    cout << border << endl;
    cout << "| " << setw(100) << left << nodePtr->getLabel() << " |" << endl;
    cout << "| " << setw(100) << left << " " << " |" << endl;
    cout << "| " << setw(100) << left << nodePtr->getQuestion() << " |" << endl;
    cout << "| " << setw(100) << left << ("<" + nodePtr->getCategory() + ">") << " |" << endl;
    cout << "| " << setw(100) << left << " " << " |" << endl;
    cout << "| " << setw(100) << left << nodePtr->getDescription() << " |" << endl;
    cout << border << endl;
  } else {
    cout << "Question / Vocabulary not found." << endl;
  }
}

void CardNode::displayListOneByOne() const {
  Card *nodePtr;
  nodePtr = head;

  static int counter = 1;

  cout << "Card " << counter << ":" << endl;

  displayNode(nodePtr->getQuestion());

  char choice;
  do {
    cout << "Click j to jump to the previous card." << endl;
    cout << "Click k to jump to the next card." << endl;
    cout << "Click q to quit." << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
      case 'j': {
        if (nodePtr->getPrev() != nullptr) {
          nodePtr = nodePtr->getPrev();
          counter--;

          cout << "Card " << counter << ":" << endl;

          displayNode(nodePtr->getQuestion());
        } else {
          cout << "No more previous card." << endl;
        }
        break;
      }
      case 'k': {
        if (nodePtr->getNext() != nullptr) {
          nodePtr = nodePtr->getNext();
          counter++;

          cout << "Card " << counter << ":" << endl;

          displayNode(nodePtr->getQuestion());
        } else {
          cout << "No more next card." << endl;
        }
        break;
      }
      case 'q': {
        break;
      }
    }
  } while (choice != 'q');
}

void CardNode::displayList() const {
  Card *nodePtr;
  nodePtr = head;

  while (nodePtr) {
    string border = "+------------------------------------------------------------------------------------------------------+";

    cout << border << endl;
    cout << "| " << setw(100) << left << nodePtr->getLabel() << " |" << endl;
    cout << "| " << setw(100) << left << " " << " |" << endl;
    cout << "| " << setw(100) << left << nodePtr->getQuestion() << " |" << endl;
    cout << "| " << setw(100) << left << ("<" + nodePtr->getCategory() + ">") << " |" << endl;
    cout << "| " << setw(100) << left << " " << " |" << endl;
    cout << "| " << setw(100) << left << nodePtr->getDescription() << " |" << endl;
    cout << border << endl;
    
    nodePtr = nodePtr->getNext();
  }
}

string CardNode::getCardLabel(string question) const {
  Card *nodePtr;
  nodePtr = head;

  while (nodePtr != nullptr && nodePtr->getQuestion() != question) {
    nodePtr = nodePtr->getNext();
  }

  if (nodePtr) {
    return nodePtr->getLabel();
  } else {
    return "Question / Vocabulary not found.";
  }
}

string CardNode::getCardQuestion(string question) const {
  Card *nodePtr;
  nodePtr = head;

  while (nodePtr != nullptr && nodePtr->getQuestion() != question) {
    nodePtr = nodePtr->getNext();
  }

  if (nodePtr) {
    return nodePtr->getQuestion();
  } else {
    return "Question / Vocabulary not found.";
  }
}

string CardNode::getCardCategory(string question) const {
  Card *nodePtr;
  nodePtr = head;

  while (nodePtr != nullptr && nodePtr->getQuestion() != question) {
    nodePtr = nodePtr->getNext();
  }

  if (nodePtr) {
    return nodePtr->getCategory();
  } else {
    return "Question / Vocabulary not found.";
  }
}

string CardNode::getCardDescription(string question) const {
  Card *nodePtr;
  nodePtr = head;

  while (nodePtr != nullptr && nodePtr->getQuestion() != question) {
    nodePtr = nodePtr->getNext();
  }

  if (nodePtr) {
    return nodePtr->getDescription();
  } else {
    return "Question / Vocabulary not found.";
  }
}