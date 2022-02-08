#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;

void push(Node* &head, int newValue);
void print(Node* current);
Node* pop();

int main() {
  Node* head = NULL;
  bool running = true;
  char input[20];
  while(running) {
    cout << "Enter command: ";
    cin.getline(input, 20);
    if(!strcmp(input, "quit")) {
      running = false;
    }
    else if(!strcmp(input, "print")) {
      print(head);
      cout << endl;
    }
    else if(!strcmp(input, "push")) {
      int intInput;
      cout << "Value to add to stack: ";
      cin >> intInput;
      push(head, intInput);
    }
  }
  return 0;
}

Node* pop(Node* &head) {
  Node* returnNode = head;
  head = head->getNext();
  return returnNode;
}

void push(Node* &head, int newValue) {
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
