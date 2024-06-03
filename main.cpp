// Run the following command to compile the program:
// g++ *.cpp -o main && ./main

#include <iostream>
#include <fstream>
using namespace std;

#include "Card.h"
#include "CardNode.h"

int main () {
  CardNode cardNode;

  // cout << "Inserting items into the list:" << endl;
  // cardNode.insertNode("Aa", "Apple", "fruit", "a fruit");
  // cardNode.insertNode("Cc", "Carrot", "vegetable", "a vegetable");
  // cardNode.insertNode("Bb", "Bear", "animal", "an animal");
  // cardNode.insertNode("Bb", "Banana", "fruit", "a fruit");

  // cout << "Delete carrot:" << endl;
  // cardNode.deleteNode("Carrot");

  // cout << "Item left in the list:" << endl;
  // cardNode.displayList();

  // cout << "Searching for apple:" << endl;
  // cardNode.searchNode("Apple");
  // cout << endl;

  // cout << "Editing banana:" << endl;
  // cardNode.editNode("Bb", "Banana", "fruit", "a fruit that is yellow");

  // cout << "Displaying banana:" << endl;
  // cardNode.displayNode("Banana");

  bool terminate = false;
  do {
    char choice;
    do {
      cout << "1. Load flashcard" << endl;
      cout << "2. Terminate program" << endl;
      cout << "Enter your choice: ";
      cin >> choice;
    } while (choice != '1' && choice != '2');

    switch (choice) {
      case '1': {
        CardNode cardNode;

        ifstream file;
        string fileName;

        do {
          cout << "Enter the file name: ";
          cin >> fileName;

          file.open("flashCard/"+fileName);

          if(!file) {
            cout << "Error: File not found." << endl;
          }
        } while (!file);

        string label, question, category, description;
        while (file >> label) {
          file.ignore();
          getline(file, question, '\t');
          getline(file, category, '\t');
          getline(file, description);

          cardNode.insertNode(label, question, category, description);
        }
        file.close();

        bool exit = false;
        do {
          char menuChoice;
          do {
            cout << "1. Display all flashcards" << endl;
            cout << "2. Search for a flashcard" << endl;
            cout << "3. Edit a flashcard" << endl;
            cout << "4. Delete a flashcard" << endl;
            cout << "5. Exit / Load from different flash card file" << endl;
            cout << "Enter your choice: ";
            cin >> menuChoice;
          } while (menuChoice != '1' && menuChoice != '2' && menuChoice != '3' && menuChoice != '4' && menuChoice != '5');

          switch (menuChoice) {
            case '1': {
              cardNode.displayList();
              break;
            }
            case '2': {
              string search;
              cout << "Enter the question to search: ";
              cin.ignore();
              getline(cin, search);
              cardNode.searchNode(search);
              break;
            }
            case '3': {
              string edit;
              cout << "Enter the question to edit: ";
              cin.ignore();
              getline(cin, edit);

              // show thee card details
              cardNode.displayNode(edit);

              // set the old card details
              string label, question, category, description;
              label = cardNode.getCardLabel(edit);
              question = cardNode.getCardQuestion(edit);
              category = cardNode.getCardCategory(edit);
              description = cardNode.getCardDescription(edit);

              char fieldChoice;
              do {
                cout << "Which field to edit: " << endl;
                cout << "1. Label" << endl;
                cout << "2. Question" << endl;
                cout << "3. Category" << endl;
                cout << "4. Description" << endl;
                cout << "Enter your choice: ";
                cin >> fieldChoice;
              } while (fieldChoice != '1' && fieldChoice != '2' && fieldChoice != '3' && fieldChoice != '4');

              switch (fieldChoice) {
                case '1': {
                  cout << "Enter the new label: ";
                  cin.ignore();
                  getline(cin, label);
                  break;
                }
                case '2': {
                  cout << "Enter the new question: ";
                  cin.ignore();
                  getline(cin, question);
                  break;
                }
                case '3': {
                  cout << "Enter the new category: ";
                  cin.ignore();
                  getline(cin, category);
                  break;
                }
                case '4': {
                  cout << "Enter the new description: ";
                  cin.ignore();
                  getline(cin, description);
                  break;
                }
              }

              cardNode.editNode(label, question, category, description);

              break;
            }
            case '4': {
              string del;
              cout << "Enter the question to delete: ";
              cin.ignore();
              getline(cin, del);
              cardNode.deleteNode(del);
              break;
            }
            case '5': {
              exit = true;
            }
          }
        } while (!exit);
        cout << "terminate: " << terminate << endl;
        break;
      }
      case '2': {
        cout << "Terminating program..." << endl;
        terminate = true;
        cout << "Program terminated." << endl;
        break;
      }
    }
    cout << "hi";
    cout << "Terminate: " << terminate << endl;
  } while (!terminate);
  return 0;
}