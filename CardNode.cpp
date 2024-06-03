#include "CardNode.h"

#include <iostream>
using namespace std;

CardNode::CardNode() {
  head = nullptr;
  tail = nullptr; 
}

CardNode::~CardNode() {
  Card *nodePtr;
  Card *nextNode;

  nodePtr = head;

  while (nodePtr != nullptr) {
    nextNode = nodePtr->next;
    delete nodePtr;
    nodePtr = nextNode;
  }
}

void CardNode::insertNode (string vocab, string category, string definition) {
  Card *newNode;
  Card *nodePtr;
  Card *previousNode = nullptr;

  newNode = new Card;
  newNode->vocab = vocab;
  newNode->category = category;
  newNode->definition = definition;

  if (!head) {
    head = newNode;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    tail = newNode;
  } else {
    nodePtr = head;
    previousNode = nullptr;

    while (nodePtr != nullptr && nodePtr->vocab < vocab) {
      previousNode = nodePtr;
      nodePtr = nodePtr->next;
    }

    if (previousNode == nullptr) {
      head = newNode;
      newNode->next = nodePtr;
      newNode->prev = nullptr;
      nodePtr->prev = newNode;
    } else {
      previousNode->next = newNode;
      newNode->prev = previousNode;
      newNode->next = nodePtr;
      if (nodePtr != nullptr) {
        nodePtr->prev = newNode;
      } else {
        tail = newNode;
      }
    }
  }
}

void CardNode::displayList() const {
  Card *nodePtr;
  nodePtr = head;

  while (nodePtr) {
    cout << "Vocab: " << nodePtr->vocab << endl;
    cout << "Category: " << nodePtr->category << endl;
    cout << "Definition: " << nodePtr->definition << endl;
    cout << endl;
    nodePtr = nodePtr->next;
  }
}