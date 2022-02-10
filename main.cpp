#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;

void push(Node* &head, char newValue);
void print(Node* current);
char pop(Node* &head);
void quit(Node* current);

int main() {
  Node* head = NULL;
  bool running = true;
  char input[20];
  while(running) {
    cout << "Enter command: ";
    cin.getline(input, 20);
    if(!strcmp(input, "quit")) {
      quit(head);
      running = false;
    }
    else if(!strcmp(input, "print")) {
      print(head);
      cout << endl;
    }
    else if(!strcmp(input, "push")) {
      char charInput;
      cout << "Value to add to stack: ";
      cin >> charInput;
      push(head, charInput);
      cin.ignore(10000,'\n');
    }
    else if(!strcmp(input, "pop")) {
      char popValue = pop(head);
      cout << "Value popped from stack: " << popValue << endl;
    }
  }
  return 0;
}

void quit(Node* current) {
  if(current == NULL) {
    return;
  }
  else if(current->getNext() != NULL) {
    quit(current->getNext());
  }
  delete current;
  current = NULL;
}

char pop(Node* &head) {
  char returnChar = head->getValue();
  Node* afterHead = head->getNext();
  delete head;
  head = afterHead;
  return returnChar;
}

void push(Node* &head, char newValue) {
  Node* newNode = new Node(newValue);
  Node* tempHead = head;
  head = newNode;
  newNode->setNext(tempHead);
}

void print(Node* current) {
  if(current == NULL) {
    return;
  }
  cout << current->getValue() << " ";
  if(current->getNext() != NULL) {
    print(current->getNext());
  }
}
