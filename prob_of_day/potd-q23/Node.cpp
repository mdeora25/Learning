#include "Node.h"

using namespace std;

Node *listSymmetricDifference(Node *first, Node *second) {
  // your code here
  Node * result = NULL;
  Node * resulttemp;
  Node * firsttemp = first;
  Node * secondtemp = second;
  Node * resulttemp2;
  bool flag;
  while (firsttemp != NULL) {
      secondtemp = second;
      flag = true;
      resulttemp2 = result;
      while (resulttemp2 != NULL) {
          if (firsttemp->data_ == resulttemp2->data_) {flag = false;}
          resulttemp2 = resulttemp2->next_;
      }
      while (secondtemp != NULL) {
          if (firsttemp->data_ == secondtemp->data_) {
              flag = false;
              break;
          }
          secondtemp = secondtemp->next_;
      }
      if (flag) {
          resulttemp = new Node();
          resulttemp->data_ = firsttemp->data_;
          resulttemp->next_ = result;
          result = resulttemp;
      }
      firsttemp = firsttemp->next_;
  }
  secondtemp = second;
  while (secondtemp != NULL) {
      firsttemp = first;
      flag = true;
      resulttemp2 = result;
      while (resulttemp2 != NULL) {
          if (secondtemp->data_ == resulttemp2->data_) {flag = false;}
          resulttemp2 = resulttemp2->next_;
      }
      while (firsttemp != NULL) {
          if (firsttemp->data_ == secondtemp->data_) {
              flag = false;
              break;
          }
          firsttemp = firsttemp->next_;
      }
      if (flag) {
          resulttemp = new Node();
          resulttemp->data_ = secondtemp->data_;
          resulttemp->next_ = result;
          result = resulttemp;
      }
      secondtemp = secondtemp->next_;
  }
  return result;
}

Node::Node() {
    numNodes++;
}

Node::Node(Node &other) {
    this->data_ = other.data_;
    this->next_ = other.next_;
    numNodes++;
}

Node::~Node() {
    numNodes--;
}

int Node::numNodes = 0;
