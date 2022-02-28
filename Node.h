#ifndef NODE_H
#define NODE_H
#include <iostream>

using namespace std;

class Node {
public:
  Node(char);
  ~Node();
  char getValue();
  void setValue(char);
  Node* getLeft();
  void setLeft(Node*);
  Node* getRight();
  void setRight(Node*);
private:
  char value;
  Node* left;
  Node* right;
};
#endif
