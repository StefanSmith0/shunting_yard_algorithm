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

Node* Stack::pop() {
  if(head == NULL) {
    return NULL;
  }
  Node* returnNode = head;
  Node* afterHead = head->getLeft();
  head = afterHead;
  returnNode->setLeft(NULL);
  return returnNode;
  size--;
}

void Stack::push(Node* newNode) {
  Node* tempHead = head;
  head = newNode;
  newNode->setLeft(tempHead);
  size++;
}

Node* Stack::peek() {
  if(head == NULL) {
    return NULL;
  }
  return head;
}

int Stack::length() {
  return size;
}
