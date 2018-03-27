#include <iostream>
#include "fibheap.h"
#include "string"
using namespace std;

int main()
{
   FibHeap<int> fh;

   fh.insert(1, 2);
   fh.insert(3, 8);
   cout << fh.root_list.size() << endl;
   auto it = fh.root_list.begin()++;
   fh.merge(fh.root_list.begin(), it);
   cout << fh.root_list.size() << endl;
   return 0;
}
