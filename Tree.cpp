#include <iostream>
#include "Tree.h"
#include "Stack.h"
#include <cstring>

using namespace std;

Tree::Tree() {
  size = 0;
  head = NULL;
  root = NULL;
}

Tree::~Tree() {
  destroy(head);
}

void Tree::push(Node* newNode) {
  if(head = NULL) {
    head = newNode;
  }
  else {
    Node* tempHead = head;
    head = newNode;
    size++;
  }
}

void Tree::pushLeft(Node* newNode) {
  if(head = NULL) {
    return;
  }
  head->setLeft(newNode);
  size++;
}

void Tree::pushRight(Node* newNode) {
  if(head = NULL) {
    return;
  }
  head->setRight(newNode);
  size++;
}

void Tree::destroy(Node* current) {
  if(current == NULL) {
    return;
  }
  else if(current->getLeft() != NULL) {
    destroy(current->getLeft());
  }
  else if(current->getRight() != NULL) {
    destroy(current->getRight());
  }
  delete current;
  current = NULL;
}

void Tree::print(int level) {
  cout << "Print not developed yet" << endl;
}
