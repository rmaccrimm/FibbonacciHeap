#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <memory>
#include <vector>
using namespace std;

template <typename T>
class Node
{
      
public:      
   Node(int k, T v):
      key(k), value(v), parent(nullptr), next(this), prev(this),
      degree(0), marked(false) {}

   ~Node() { for (auto c: children) delete c; }

public:
   void make_child(Node* n)
   {
      n->parent = this;
      if (children.size() > 0) {
	 Node<T>* last = *children.rbegin();
	 Node<T>* first = *children.begin();
	 last->next = n;
	 first->prev = n;
	 n->prev = last;
	 children.push_back(n);
	 n->next = first;
      }
      else {
	 children.push_back(n);
	 n->prev = n;
	 n->next = n;
      }

      if (n->degree >= degree)
	 degree = 1 + n->degree;
   }

   void print_tree()
   {
      cout << "( " << value << " ";
      for (auto c: children)
	    c->print_tree();
      cout << ")";
   }

private:
   int key;
   T value;
   
   int degree;
   bool marked;
   
   Node<T>* parent;
   Node<T>* next;
   Node<T>* prev;
   
   vector<Node*> children;
};

#endif
