#include "Node.h"

void sortList(Node **head) {
  // your code here!

  /*
  Selection sort:
  Repeatedly moving the minimum node
  to the beginning
  */


  // Some variables you probably will need
  

  if (*head == NULL)
      return;

  	Node * prev = NULL;
	Node * min = (*head);
	Node * cur = (*head);
	while (cur->next_ != NULL) {
		if (min->data_ > cur->next_->data_) {
			min = cur->next_;
			prev = cur;
		}
		cur = cur->next_;
	}
	// put in front of first node
	if (min != *head) {
		prev->next_ = min->next_;
		min->next_ = *head;
		*head = min;
	}
  	sortList(&((*head)->next_));
  	return;
  // Recurse on the rest of the list
  sortList(& (*head)->next_);
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
