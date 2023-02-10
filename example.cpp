#include <iostream>
#include "DLinkedList.h"
#include "barcode.h"
#include <vector>

using namespace std;

int main() {
  DLinkedList<bar> v;
  v.AddTail(bar("First", 1));
  v.AddTail(bar("Seventh", 7));
  v.AddTail(bar("Third", 3));
  v.AddTail(bar("Second", 2));
  v.AddTail(bar("Fifth", 5));
  v.AddTail(bar("Fourth", 4));
  v.AddTail(bar("Sixth", 6));
  cout << "Before sorting: " << endl;
  v.printForwards();
  cout << endl;
  cout << "After sorting: " << endl;
  v.RecurBubbleSort(v.getHead(), v.getHead());
  v.printForwards();
}
