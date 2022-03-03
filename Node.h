#ifndef NODE_H
#define NODE_H
#include <iostream>

using namespace std;

class Node {
public:
  Node(char); //Constructor
  ~Node(); //Destructor
  char getValue(); //Sets and gets
  void setValue(char newValue);
  Node* getNext();
  void setNext(Node* newNext);
  Node* getLeft();
  void setLeft(Node* newLeft);
  Node* getRight();
  void setRight(Node* newRight);
private:
  char value;
  Node* next;
  Node* left;
  Node* right;
};
#endif
