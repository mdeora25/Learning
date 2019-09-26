#include "Node.h"

void mergeList(Node *first, Node *second) {
  // your code here!
  if (second == NULL) {return;}
  
  	while (first != NULL) {
        Node * temp2;
  		if (second != NULL){ 
  			if (first->next_ == NULL) {
  				first->next_ = second;
  				return;
  			}
  			temp2 = second->next_;
  			second->next_ = first->next_;
  			first->next_ = second;
  			second = temp2;
		}
  		first = first->next_->next_;
  	}
}

Node::Node() {
    numNodes++;
}

Node::Node(const Node &other) {
    this->data_ = other.data_;
    this->next_ = other.next_;
    numNodes++;
}

Node::~Node() {
    numNodes--;
}

int Node::numNodes = 0;
