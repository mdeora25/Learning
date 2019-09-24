#include "potd.h"
#include <iostream>

void insertSorted(Node **head, Node *insert) {
  // your code here!
  if (*head == NULL) {
    *head = insert;
    return;
  }
  Node * curr;
  curr = *head;
  if (curr->data_ > insert->data_) {
		*head = insert;
		insert->next_ = curr;
		return;
	}
  while (curr->next_ != NULL) {
    if (curr->data_ <= insert->data_ && curr->next_->data_ >= insert->data_ ) {
      insert->next_ = curr ->next_;
      curr->next_ = insert;
       return;
    }
    curr = curr->next_;
  }
  (*head)->next_ = insert;
  return;
}
