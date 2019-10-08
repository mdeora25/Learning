#include "Stack.h"
#include <vector>
// `int size()` - returns the number of elements in the stack (0 if empty)
int Stack::size() const {
  return arr.size();
}

// `bool isEmpty()` - returns if the list has no elements, else false
bool Stack::isEmpty() const {
  if (arr.size() == 0) {return true;}
  return false;
}

// `void push(int val)` - pushes an item to the stack in O(1) time
void Stack::push(int value) {
  arr.push_back(value);
}

// `int pop()` - removes an item off the stack and returns the value in O(1) time
int Stack::pop() {
  int temp = arr.back();
  arr.pop_back();
  return temp;
}
