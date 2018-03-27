#ifndef FIBHEAP_H
#define FIBHEAP_H

#include <vector>
#include <list>
#include <memory>
using namespace std;


template <typename T>
class FibHeap
{
  public:

   FibHeap()
   {
      min = nullptr;
   }

   void insert(int key, T val)
   {
      shared_ptr<Node> n = shared_ptr<Node>(new Node(key, val));
      root_list.insert(root_list.begin(), n);
      if (min == nullptr)
	 min = n;
      if (min->key > key)
	 min = n;
   }

   T get_min()
   {
      return min->value;
   }

   T delete_min()
   {
      
   }

   void decrease_key(int x);

   //private:
   
   class Node
   {
     public:      
     Node(int k, T v): key(k), value(v), parent(nullptr), degree(0), marked(false)
      {}
      bool marked;
      int key;
      T value;
      int degree;
      Node* parent;
      vector<shared_ptr<Node>> children;

      void make_child(shared_ptr<Node> n)
      {
	 n->parent = this;
	 children.push_back(n);
	 if (n->degree >= degree)
	    degree = 1 + n->degree;
      }
   };

   void consolidate()
   {
      
   }

   typedef typename list<shared_ptr<Node>>::iterator list_iterator;
   typedef shared_ptr<Node> node_ptr;
   
   void merge(list_iterator pnt_it, list_iterator child_it)
   {
      node_ptr pptr = *pnt_it;
      node_ptr cptr = *child_it;
      pptr->make_child(cptr);
      root_list.erase(child_it);
   }

   node_ptr min;
   list<node_ptr> root_list;
   
};
   
#endif
