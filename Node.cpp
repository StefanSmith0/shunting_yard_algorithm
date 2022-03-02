#include <iostream>
#include "Node.h"

using namespace std;

Node::Node(char newValue) {
  value = newValue;
  left = NULL;
  right = NULL;
}

Node::~Node() {
}

char Node::getValue() {
  return value;
}

void Node::setValue(char newValue) {
  value = newValue;
}

Node* Node::getLeft() {
  return left;
}

void Node::setLeft(Node* newLeft) {
  left = newLeft;
}

Node* Node::getRight() {
  return right;
}

void Node::setRight(Node* newRight) {
  right = newRight;
}
