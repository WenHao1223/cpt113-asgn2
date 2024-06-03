#include "CardNode.h"

#include <iostream>
using namespace std;

CardNode::CardNode() {
  head = nullptr;
  tail = nullptr; 
}

void CardNode::editNode (string vocab, string category, string definition) {
  cout << "hi";
  try {
    if (vocab == "") {
      cout << endl << "Error: Vocab cannot be empty." << endl;
      return;
    }

    if (category == "") {
      cout << endl << "Error: Category cannot be empty." << endl;
      return;
    }

    if (definition == "") {
      cout << endl << "Error: Definition cannot be empty." << endl;
      return;
    }
  } catch (string exceptionString) {
    cout << exceptionString;
    return;
  };

  Card *nodePtr;
  nodePtr = head;

  while (nodePtr != nullptr && nodePtr->getVocab() != vocab) {
    nodePtr = nodePtr->getNext();
  }

  if (nodePtr) {
    nodePtr->setCategory(category);
    nodePtr->setDefinition(definition);
  } else {
    cout << "Vocab not found." << endl;
  }
}

void CardNode::searchNode (string vocab) const {
  Card *nodePtr;
  nodePtr = head;

  while (nodePtr != nullptr && nodePtr->getVocab() != vocab) {
    nodePtr = nodePtr->getNext();
  }

  if (nodePtr) {
    cout << "Vocab: " << nodePtr->getVocab() << endl;
    cout << nodePtr->getLeadingChar() << static_cast<char>((nodePtr->getLeadingChar())+32) << endl;
    cout << "Category: " << nodePtr->getCategory() << endl;
    cout << "Definition: " << nodePtr->getDefinition() << endl;
  } else {
    cout << "Vocab not found." << endl;
  }
}

void CardNode::deleteNode (string vocab) {
  Card *nodePtr;
  Card *previousNode;

  if (!head) {
    return;
  }

  if (head->getVocab() == vocab) {
    nodePtr = head->getNext();
    delete head;
    head = nodePtr;
  } else {
    nodePtr = head;

    while (nodePtr != nullptr && nodePtr->getVocab() != vocab) {
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

void CardNode::insertNode (string vocab, string category, string definition) {
  Card *newNode;
  Card *nodePtr;
  Card *previousNode = nullptr;

  newNode = new Card;

  newNode->setLeadingChar(vocab.front());
  newNode->setVocab(vocab);
  newNode->setCategory(category);
  newNode->setDefinition(definition);

  if (!head) {
    head = newNode;
    newNode->setNext(nullptr);
    newNode->setPrev(nullptr);
    tail = newNode;
  } else {
    nodePtr = head;
    previousNode = nullptr;

    while (nodePtr != nullptr && nodePtr->getVocab() < vocab) {
      previousNode = nodePtr;
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

void CardNode::displayNode(string vocab) const {
  Card *nodePtr;
  nodePtr = head;

  while (nodePtr != nullptr && nodePtr->getVocab() != vocab) {
    nodePtr = nodePtr->getNext();
  }

  if (nodePtr) {
    cout << "Vocab: " << nodePtr->getVocab() << endl;
    cout << nodePtr->getLeadingChar() << static_cast<char>((nodePtr->getLeadingChar())+32) << endl;
    cout << "Category: " << nodePtr->getCategory() << endl;
    cout << "Definition: " << nodePtr->getDefinition() << endl;
  } else {
    cout << "Vocab not found." << endl;
  }
}

void CardNode::displayList() const {
  Card *nodePtr;
  nodePtr = head;

  while (nodePtr) {
    cout << "Vocab: " << nodePtr->getVocab() << endl;
    cout << nodePtr->getLeadingChar() << static_cast<char>((nodePtr->getLeadingChar())+32) << endl;
    cout << "Category: " << nodePtr->getCategory() << endl;
    cout << "Definition: " << nodePtr->getDefinition() << endl;
    cout << endl;
    nodePtr = nodePtr->getNext();
  }
}