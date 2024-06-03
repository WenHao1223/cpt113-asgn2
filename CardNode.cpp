#include "CardNode.h"

#include <iostream>
using namespace std;

CardNode::CardNode() {
  head = nullptr;
  tail = nullptr; 
}

void CardNode::editNode (string vocab, string category, string definition) {
  Card *nodePtr;
  nodePtr = head;

  while (nodePtr != nullptr && nodePtr->vocab != vocab) {
    nodePtr = nodePtr->next;
  }

  if (nodePtr) {
    nodePtr->category = category;
    nodePtr->definition = definition;
  } else {
    cout << "Vocab not found." << endl;
  }
}

void CardNode::searchNode (string vocab) const {
  Card *nodePtr;
  nodePtr = head;

  while (nodePtr != nullptr && nodePtr->vocab != vocab) {
    nodePtr = nodePtr->next;
  }

  if (nodePtr) {
    cout << "Vocab: " << nodePtr->vocab << endl;
    cout << nodePtr->leadingChar << static_cast<char>((nodePtr->leadingChar)+32) << endl;
    cout << "Category: " << nodePtr->category << endl;
    cout << "Definition: " << nodePtr->definition << endl;
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

  if (head->vocab == vocab) {
    nodePtr = head->next;
    delete head;
    head = nodePtr;
  } else {
    nodePtr = head;

    while (nodePtr != nullptr && nodePtr->vocab != vocab) {
      previousNode = nodePtr;
      nodePtr = nodePtr->next;
    }

    if (nodePtr) {
      previousNode->next = nodePtr->next;
      delete nodePtr;
    }
  }
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

  newNode->leadingChar = vocab.front();
  // change it to upper case
  if (newNode->leadingChar >= 'a' && newNode->leadingChar <= 'z') {
    newNode->leadingChar -= 32;
  }
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

void CardNode::displayNode(string vocab) const {
  Card *nodePtr;
  nodePtr = head;

  while (nodePtr != nullptr && nodePtr->vocab != vocab) {
    nodePtr = nodePtr->next;
  }

  if (nodePtr) {
    cout << "Vocab: " << nodePtr->vocab << endl;
    cout << nodePtr->leadingChar << static_cast<char>((nodePtr->leadingChar)+32) << endl;
    cout << "Category: " << nodePtr->category << endl;
    cout << "Definition: " << nodePtr->definition << endl;
  } else {
    cout << "Vocab not found." << endl;
  }
}

void CardNode::displayList() const {
  Card *nodePtr;
  nodePtr = head;

  while (nodePtr) {
    cout << "Vocab: " << nodePtr->vocab << endl;
    cout << nodePtr->leadingChar << static_cast<char>((nodePtr->leadingChar)+32) << endl;
    cout << "Category: " << nodePtr->category << endl;
    cout << "Definition: " << nodePtr->definition << endl;
    cout << endl;
    nodePtr = nodePtr->next;
  }
}