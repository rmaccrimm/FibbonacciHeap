#include <iostream>
#include <memory>
#include "fibheap.h"
#include "string"
using namespace std;

int main()
{
    FibonacciHeap<int> fh;
    
    for (int i = 3; i > 0; i--) {
        fh.insert(i, i);
    }
    fh.print();
    //cout << "min: " << fh.delete_min() << endl;
    fh.consolidate();
    fh.print();
}
