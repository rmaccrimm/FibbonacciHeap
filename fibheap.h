#ifndef FIBONACCIHEAP_H
#define FIBONACCIHEAP_H

#include <vector>
#include <list>
#include <memory>
#include "node.h"
using namespace std;


template <typename T>
class FibonacciHeap
{
public:
   typedef Node<T>* node_ptr;

   FibbonacciHeap(): min(nullptr) {}

   void insert(int key, T val)
   {
      node_ptr* n = new node_ptr(key, val);
      root_list = merge(n, root_list);
      if (n->key < min->key) {
	 min = n;
      }
   }

   T get_min()
   {
      return min->value;
   }

   T delete_min()
   {
      
   }

   void decrease_key(int x);

private:
   
   Node<T>* merge(node_ptr n1, node_ptr n2)
   {
      if (n1 == nullptr && n2 == nullptr)
	 return nullptr;
      
      if (n1 == nulltpr) {
	 n2->next = n2;
	 n2->prev = n2;
	 return n2;
      }
      else if (n2 == nullptr) {
	 n1->next = n1;
	 n1->prev = n2;
	 return n1;
      }
      
      if (n1->value < n2->value) { 
	 n1->make_child(n2);
	 return n1;
      }
      else {
	 n2->prev = n1->prev;
	 n2->next = n1->next;
	 n2->make_child(n1);
	 return n2;
      }
   }

   Node<T>* min;
   Node<T>* root_list;
   
};
   
#endif
