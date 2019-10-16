#ifndef TREE_CPP
#define TREE_CPP

#include "tree.h"

template <class T>
Tree<T>::Iterator::Iterator(Tree::Node *root) : curr_(root) {
	// TODO: your code here
	helper_I(root);

}

template <class T>
typename Tree<T>::Iterator & Tree<T>::Iterator::operator++() {
	// TODO: your code here
	q.pop();
	curr_ = q.front();
	
	return *this;
}
template <class T>
void Tree<T>::Iterator::helper_I(Tree::Node *root) {
	if (root == NULL) {return;}
	helper_I(root->right_);

	//if (root->right_ != NULL) {q.push(root->right_);}
	if (root->data_ != NULL) {q.push(root);}
	

	helper_I(root->left_);
	//if (root->left_ != NULL) {q.push(root->left_);}
	
}
template <class T>
T Tree<T>::Iterator::operator*() const {
	// TODO: your code here
	if (q.empty()) {return NULL;}
	return q.front()->data_; // remove this line
}



/*******************
 ** PROVIDED CODE **
 *******************/
template <class T>
bool Tree<T>::Iterator::operator!=(const Tree<T>::Iterator &other) {
	return !(curr_ == other.curr_);
}

template <class T>
typename Tree<T>::Iterator Tree<T>::begin() {
	return Iterator(root_);
}

template <class T>
typename Tree<T>::Iterator Tree<T>::end() {
	return Iterator(NULL);
}

#endif