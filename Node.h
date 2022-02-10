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
  Node* getNext();
  void setNext(Node*);
private:
  char value;
  Node* nextNode;
};
#endif
