#ifndef FIBONACCIHEAP_H
#define FIBONACCIHEAP_H

#include <vector>
#include <iostream>
#include <list>
#include <memory>
#include "node.h"
using namespace std;

template <typename T>
class FibonacciHeap
{
public:
    typedef Node<T>* node_ptr;

    FibonacciHeap(): 
        root_list(nullptr), min(nullptr), num_nodes(0) {}

    ~FibonacciHeap()
    {
        node_ptr end = root_list->prev;
        int i = 1;
        while (true)
        {
            cout << i++ << endl;
            if (root_list == end) {
                delete root_list;
                break;
            }
            node_ptr tmp = root_list;
            root_list = root_list->next;
            delete tmp;
        }
    }

    void insert(int key, T val)
    {
        node_ptr n = new Node<T>(key, val);
        root_list = insert_node(n);
        if (min == nullptr)
            min = n;
        if (n->key < min->key) 
            min = n;
        num_nodes++;
    }

    T get_min()
    {
       return min->value;
    }

    T delete_min()
    {
        T retval = min->value;
        for (auto c: min->children)
            insert_node(c);
        min->children.erase(min->children.begin(), min->children.end());
        min->prev->next = min->next;
        min->next->prev = min->prev;
        delete min; 
        consolidate();

        min = root_list;
        node_ptr n = root_list;
        do {
            if (n->key < min->key)
                min = n;
            n = n->next;
        } while (n != root_list);

        num_nodes--;
        return retval;
    }

    void decrease_key(int x);

    void print()
    {
        node_ptr n = root_list;
        do {
            n->print_tree();
            cout << endl;
            n = n->next;
        } while (n != root_list);
        cout << endl;
    }

private:

    node_ptr insert_node(node_ptr n)
    {
        n->parent = nullptr;
        if (root_list == nullptr) {
            n->next = n;
            n->prev = n;
            return n;
        }
        root_list->prev->next = n;
        n->prev = root_list->prev;
        root_list->prev = n;
        n->next = root_list;
        return root_list;
    }
   
    node_ptr merge(node_ptr n1, node_ptr n2)
    {
        if (n1 == nullptr && n2 == nullptr)
            return nullptr;
        
        if (n1 == nullptr) {
            return n2;
        }
        else if (n2 == nullptr) {
            return n1;
        }
        
        if (n1->value < n2->value) { 
            n2->prev->next = n2->next;
            n2->next->prev = n2->prev;
            n1->make_child(n2);
            return n1;
        }
        else {
            n1->prev->next = n1->next;
            n1->next->prev = n1->prev;
            n2->make_child(n1);
            return n2;
        }
    }
public:
    /* BUG:
        ( 3 )
        ( 2 )
        ( 1 )
        
        becomes 
        ( 3 )
        ( 3 ( 2 ) )

        ... double free error
    */
    void consolidate()
    {
        vector<node_ptr> degree_ptrs(num_nodes, nullptr);
        node_ptr n = root_list;
        while (true)
        {
            if (degree_ptrs[n->degree] == nullptr)
                degree_ptrs[n->degree] = n;
            else {
                if (degree_ptrs[n->degree] == n) { // gone through whole list
                    break;
                }
                n = merge(n, degree_ptrs[n->degree]);
            }
            n = n->next;                
        }
    }

    Node<T>* min;
    Node<T>* root_list;
    int num_nodes;
};
   
#endif
