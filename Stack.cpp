#include <iostream>
#include "Stack.h"
#include "Node.h"

using namespace std;

Stack::Stack() {
  size = 0;
  head = NULL;
}

Stack::~Stack() {
  destroy(head);
}

void Stack::destroy(Node* current) {
  if(current == NULL) {
    return;
  }
  else if(current->getLeft() != NULL) {
    destroy(current->getLeft());
  }
  delete current;
  current = NULL;
}

char Stack::pop() {
  if(head == NULL) {
    return '~';
  }
  char returnChar = head->getValue();
  Node* afterHead = head->getLeft();
  delete head;
  head = afterHead;
  return returnChar;
  size--;
}

void Stack::push(char newValue) {
  Node* newNode = new Node(newValue);
  Node* tempHead = head;
  head = newNode;
  newNode->setLeft(tempHead);
  size++;
}


Node* Stack::popNode() {
  if(head == NULL) {
    return NULL;
  }
  Node* returnNode = head;
  head = head->getLeft();
  return returnNode;
  size--;
}

void Stack::pushNode(Node* newNode) {
  Node* tempHead = head;
  head = newNode;
  newNode->setLeft(tempHead);
  size++;
}

char Stack::peek() {
  if(head == NULL) {
    return '~';
  }
  return head->getValue();
}

int Stack::length() {
  return size;
}
