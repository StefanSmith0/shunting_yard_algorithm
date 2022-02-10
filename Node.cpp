#include <iostream>
#include "Node.h"

using namespace std;

Node::Node(char newValue) {
  value = newValue;
  nextNode = NULL;
}

Node::~Node() {
  cout << "Node destroyed." << endl;
}

char Node::getValue() {
  return value;
}

void Node::setValue(char newValue) {
  value = newValue;
}

Node* Node::getNext() {
  return nextNode;
}

void Node::setNext(Node* newNext) {
  nextNode = newNext;
}
