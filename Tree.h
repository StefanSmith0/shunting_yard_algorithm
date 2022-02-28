#ifndef TREE_H
#define TREE_H
#include <iostream>
#include "Node.h"

using namespace std;

class Tree {
public:
  Tree();
  ~Tree();
  void push(char input[]);
  void clear();
private:
  void destroy(Node* current);
  void print(Node* head);
  int size;
  Node* head;
  Node* root;
};

#endif
