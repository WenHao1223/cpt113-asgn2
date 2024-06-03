#include "CardNode.h"

#include <iostream>
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
      cout << endl << "Error: Question cannot be empty." << endl;
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
    cout << "Question not found." << endl;
  }
}

void CardNode::searchNode (string question) const {
  try {
    if (question == "") {
      cout << endl << "Error: Question cannot be empty." << endl;
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
    cout << "Question: " << nodePtr->getQuestion() << endl;
    cout << "Label: " << nodePtr->getLabel() << endl;
    cout << "Category: " << nodePtr->getCategory() << endl;
    cout << "Description: " << nodePtr->getDescription() << endl;
  } else {
    cout << "Question not found." << endl;
  }
}

void CardNode::deleteNode (string question) {
  try {
    if (question == "") {
      cout << endl << "Error: Question cannot be empty." << endl;
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
      cout << endl << "Error: Question cannot be empty." << endl;
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
      // then compare the question if same label
      while (nodePtr->getLabel() == label) {
        if (nodePtr->getQuestion() > question) {
          break;
        }
      } 
      nodePtr = nodePtr->getNext();
    }

    if (previousNode == nullptr) {
      head = newNode;
      newNode->setNext(nodePtr);
      newNode->setPrev(nullptr);
      newNode->setPrev(nodePtr);
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
  try {
    if (question == "") {
      cout << endl << "Error: Question cannot be empty." << endl;
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
    cout << "Question: " << nodePtr->getQuestion() << endl;
    cout << "Label: " << nodePtr->getLabel() << endl;
    cout << "Category: " << nodePtr->getCategory() << endl;
    cout << "Description: " << nodePtr->getDescription() << endl;
  } else {
    cout << "Question not found." << endl;
  }
}

void CardNode::displayList() const {
  Card *nodePtr;
  nodePtr = head;

  while (nodePtr) {
    cout << "Question: " << nodePtr->getQuestion() << endl;
    cout << "Label: " << nodePtr->getLabel() << endl;
    cout << "Category: " << nodePtr->getCategory() << endl;
    cout << "Description: " << nodePtr->getDescription() << endl;
    cout << endl;
    nodePtr = nodePtr->getNext();
  }
}