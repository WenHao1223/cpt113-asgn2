#include <iostream>
#include <string>
using namespace std;

#include "CardNode.h"

template <class T1, class T2>
CardNode<T1, T2>::CardNode() {
  head = nullptr;
  tail = nullptr; 
}

template <class T1, class T2>
T1 CardNode<T1, T2>::getDefaultValueT1() {
    return T1();
}

template <class T1, class T2>
T2 CardNode<T1, T2>::getDefaultValueT2() {
    return T2();
}

template <>
string CardNode<string, string>::getDefaultValueT1() {
    return "Question / Vocabulary not found.";
}

template <>
int CardNode<int, string>::getDefaultValueT1() {
    return -1;
}

template <>
string CardNode<int, string>::getDefaultValueT2() {
    return "Question / Vocabulary not found.";
}

template <>
float CardNode<int, float>::getDefaultValueT2() {
    return -1.0;
}


template <class T1, class T2>
void CardNode<T1, T2>::editNode (T1 label, T2 question, string category, string description) {
  try {
    // if (label == "") {
    //   cout << endl << "Error: Label cannot be empty." << endl;
    //   return;
    // }

    // if (question == "") {
    //   cout << endl << "Error: Question / Vocabulary cannot be empty." << endl;
    //   return;
    // }

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

  while (nodePtr != nullptr && nodePtr->content.getQuestion() != question) {
    nodePtr = nodePtr->next;
  }

  if (nodePtr) {
    nodePtr->content.setCategory(category);
    nodePtr->content.setDescription(description);
  } else {
    cout << "Question / Vocabulary not found." << endl;
  }
}

template <class T1, class T2>
void CardNode<T1, T2>::searchNode (T2 question) const {
  try {
    // if (question == "") {
    //   cout << endl << "Error: Question / Vocabulary cannot be empty." << endl;
    //   return;
    // }
  } catch (string exceptionString) {
    cout << exceptionString;
    return;
  }

  
  Card *nodePtr;
  nodePtr = head;

  while (nodePtr != nullptr && nodePtr->content.getQuestion() != question) {
    nodePtr = nodePtr->next;
  }

  if (nodePtr) {
    string border = "+------------------------------------------------------------------------------------------------------+";

    cout << border << endl;
    cout << "| " << setw(100) << left << nodePtr->content.getLabel() << " |" << endl;
    cout << "| " << setw(100) << left << " " << " |" << endl;
    cout << "| " << setw(100) << left << nodePtr->content.getQuestion() << " |" << endl;
    cout << "| " << setw(100) << left << ("<" + nodePtr->content.getCategory() + ">") << " |" << endl;
    cout << "| " << setw(100) << left << " " << " |" << endl;
    cout << "| " << setw(100) << left << nodePtr->content.getDescription() << " |" << endl;
    cout << border << endl;
  } else {
    cout << "Question / Vocabulary not found." << endl;
  }
}

template <class T1, class T2>
void CardNode<T1, T2>::deleteNode (T2 question) {
  try {
    // if (question == "") {
    //   cout << endl << "Error: Question / Vocabulary cannot be empty." << endl;
    //   return;
    // }
  } catch (string exceptionString) {
    cout << exceptionString;
    return;
  }

  Card *nodePtr;
  Card *previousNode = nullptr;

  if (!head) {
    cout << "The list is empty." << endl;
    return;
  }

  if (head->content.getQuestion() == question) {
    nodePtr = head->next;
    if (nodePtr) {
      nodePtr->prev = nullptr;
    }
    delete head;
    head = nodePtr;
    if (head == nullptr) {
      tail = nullptr;
    }
  } else {
    nodePtr = head;

    while (nodePtr != nullptr && nodePtr->content.getQuestion() != question) {
      previousNode = nodePtr;
      nodePtr = nodePtr->next;
    }

    if (nodePtr) {
      if (nodePtr->next) {
        nodePtr->next->prev = previousNode; 
      } else {
        tail = previousNode;
      }
      if (previousNode) {
        previousNode->next = nodePtr->next;
      }
      delete nodePtr;

      cout << "Question / Vocabulary deleted." << endl;
    } else {
      cout << "Question / Vocabulary not found." << endl;
    }
  }
}

template <class T1, class T2>
CardNode<T1, T2>::~CardNode() {
  Card *nodePtr;
  Card *nextNode;

  nodePtr = head;

  while (nodePtr != nullptr) {
    nextNode = nodePtr->next;
    delete nodePtr;
    nodePtr = nextNode;
  }
}

template <class T1, class T2>
void CardNode<T1, T2>::insertNode (T1 label, T2 question, string category, string description) {
  try {
    // if (label == "") {
    //   cout << endl << "Error: Label cannot be empty." << endl;
    //   return;
    // }

    // if (question == "") {
    //   cout << endl << "Error: Question / Vocabulary cannot be empty." << endl;
    //   return;
    // }

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

  newNode->content.setLabel(label);
  newNode->content.setQuestion(question);
  newNode->content.setCategory(category);
  newNode->content.setDescription(description);

  if (!head) {
    head = newNode;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    tail = newNode;
  } else {
    nodePtr = head;
    previousNode = nullptr;

    while (nodePtr != nullptr && nodePtr->content.getLabel() < label) {
      previousNode = nodePtr;
      nodePtr = nodePtr->next;
    }

    // check if next node has the same label and order according to question
    while (nodePtr != nullptr && nodePtr->content.getLabel() == label && nodePtr->content.getQuestion() < question) {
      previousNode = nodePtr;
      nodePtr = nodePtr->next;
    }

    if (previousNode == nullptr) {
      head = newNode;
      newNode->next = nodePtr;
      newNode->prev = nullptr;
      if (nodePtr != nullptr) {
        nodePtr->prev = newNode;
      }
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

template <class T1, class T2>
void CardNode<T1, T2>::displayNode(T2 question) const {
  Card *nodePtr;
  nodePtr = head;

  while (nodePtr != nullptr && nodePtr->content.getQuestion() != question) {
    nodePtr = nodePtr->next;
  }

  if (nodePtr) {
    string border = "+------------------------------------------------------------------------------------------------------+";

    cout << border << endl;
    cout << "| " << setw(100) << left << nodePtr->content.getLabel() << " |" << endl;
    cout << "| " << setw(100) << left << " " << " |" << endl;
    cout << "| " << setw(100) << left << nodePtr->content.getQuestion() << " |" << endl;
    cout << "| " << setw(100) << left << ("<" + nodePtr->content.getCategory() + ">") << " |" << endl;
    cout << "| " << setw(100) << left << " " << " |" << endl;
    cout << "| " << setw(100) << left << nodePtr->content.getDescription() << " |" << endl;
    cout << border << endl;
  } else {
    cout << "Question / Vocabulary not found." << endl;
  }
}

template <class T1, class T2>
void CardNode<T1,T2>::displayListOneByOne() const {
  Card *nodePtr;
  nodePtr = head;

  static int counter = 1;

  cout << "Card " << counter << ":" << endl;

  displayNode(nodePtr->content.getQuestion());

  char choice;
  do {
    cout << "Click j to jump to the previous card." << endl;
    cout << "Click k to jump to the next card." << endl;
    cout << "Click q to quit." << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
      case 'j': {
        if (nodePtr->prev != nullptr) {
          nodePtr = nodePtr->prev;
          counter--;

          cout << "Card " << counter << ":" << endl;

          displayNode(nodePtr->content.getQuestion());
        } else {
          cout << "No more previous card." << endl;
        }
        break;
      }
      case 'k': {
        if (nodePtr->next != nullptr) {
          nodePtr = nodePtr->next;
          counter++;

          cout << "Card " << counter << ":" << endl;

          displayNode(nodePtr->content.getQuestion());
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

template <class T1, class T2>
void CardNode<T1,T2>::displayList() const {
  Card *nodePtr;
  nodePtr = head;

  while (nodePtr) {
    string border = "+------------------------------------------------------------------------------------------------------+";

    cout << border << endl;
    cout << "| " << setw(100) << left << nodePtr->content.getLabel() << " |" << endl;
    cout << "| " << setw(100) << left << " " << " |" << endl;
    cout << "| " << setw(100) << left << nodePtr->content.getQuestion() << " |" << endl;
    cout << "| " << setw(100) << left << ("<" + nodePtr->content.getCategory() + ">") << " |" << endl;
    cout << "| " << setw(100) << left << " " << " |" << endl;
    cout << "| " << setw(100) << left << nodePtr->content.getDescription() << " |" << endl;
    cout << border << endl;
    
    nodePtr = nodePtr->next;
  }
}

template <class T1, class T2>
T1 CardNode<T1, T2>::getCardLabel(T2 question) const {
  Card *nodePtr;
  nodePtr = head;

  while (nodePtr != nullptr && nodePtr->content.getQuestion() != question) {
    nodePtr = nodePtr->next;
  }

  if (nodePtr) {
    return nodePtr->content.getLabel();
  } else {
    return getDefaultValueT1();
  }
}

template <class T1, class T2>
T2 CardNode<T1, T2>::getCardQuestion(T2 question) const {
  Card *nodePtr;
  nodePtr = head;

  while (nodePtr != nullptr && nodePtr->content.getQuestion() != question) {
    nodePtr = nodePtr->next;
  }

  if (nodePtr) {
    return nodePtr->content.getQuestion();
  } else {
    return getDefaultValueT2();
  }
}

template <class T1, class T2>
string CardNode<T1, T2>::getCardCategory(T2 question) const {
  Card *nodePtr;
  nodePtr = head;

  while (nodePtr != nullptr && nodePtr->content.getQuestion() != question) {
    nodePtr = nodePtr->next;
  }

  if (nodePtr) {
    return nodePtr->content.getCategory();
  } else {
    return "Question / Vocabulary not found.";
  }
}

template <class T1, class T2>
string CardNode<T1, T2>::getCardDescription(T2 question) const {
  Card *nodePtr;
  nodePtr = head;

  while (nodePtr != nullptr && nodePtr->content.getQuestion() != question) {
    nodePtr = nodePtr->next;
  }

  if (nodePtr) {
    return nodePtr->content.getDescription();
  } else {
    return "Question / Vocabulary not found.";
  }
}