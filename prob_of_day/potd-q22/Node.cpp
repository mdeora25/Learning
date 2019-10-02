#include "Node.h"

using namespace std;

Node *listIntersection(Node *first, Node *second) {
  // your code here
    Node * result = NULL;
	Node * resulttemp;
	Node * firsttemp = first;
	Node * secondtemp = second;
	while (firsttemp != NULL) {
		secondtemp = second;
		while (secondtemp != NULL) {
			if (firsttemp->data_ == secondtemp->data_) {
				resulttemp = new Node();
				resulttemp->data_ = firsttemp->data_;
				resulttemp->next_ = result;
				result = resulttemp;
				break;
			}
			secondtemp = secondtemp->next_; 
		}
		firsttemp = firsttemp->next_;
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
