#include <iostream>
#include <memory>
#include "node.h"
#include "string"
using namespace std;

int main()
{
   Node<int>* n1 = new Node<int>(2, 2);
   for (int i = 0; i < 5; i++) {
      n1->make_child(new Node<int>(i + 3, i + 3));
   }
   Node<int>* n3 = new Node<int>(2, 2);
   for (int i = 0; i < 5; i++) {
      n3->make_child(new Node<int>(i + 3, i + 3));
   }
   Node<int>* n2 = new Node<int>(1, 1);
   n2->make_child(n1);
   n2->make_child(n3);
   n2->print_tree();
   cout << endl;
   return 0;
}
