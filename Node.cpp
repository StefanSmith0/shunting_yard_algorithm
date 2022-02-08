#include <iostream>
#include "Node.h"

using namespace std;

Node::Node(int newValue) {
  value = newValue;
  nextNode = NULL;
}

Node::~Node() {
  cout << "Node destroyed." << endl;
}

int Node::getValue() {
  return value;
}

void Node::setValue(int newValue) {
  value = newValue;
}

Node* Node::getNext() {
  return nextNode;
}

void Node::setNext(Node* newNext) {
  nextNode = newNext;
}
