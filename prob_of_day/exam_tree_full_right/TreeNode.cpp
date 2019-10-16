#include "TreeNode.h"

// Your function here

TreeNode *makeFullRight(int n) {
    int i = 1;
    TreeNode *ptr = new TreeNode(i,NULL,NULL);
    TreeNode *temp = ptr;
    while ( i < n) {
        temp->left_ = new TreeNode(i + 1, NULL, NULL);
        if (i == n || i + 2 > n) {return ptr;}
        temp->right_ = new TreeNode(i + 2, NULL, NULL);
        if (i + 2  ==  n ) return ptr;
        i += 2;
        temp = temp->right_;
    }
    return ptr;
}

// Methods and functions we provide following.
// You should not need to edit this code.

TreeNode::TreeNode(int data, TreeNode *left, TreeNode *right) :
    data_(data), left_(left), right_(right) {}

TreeNode::~TreeNode() {
    if (left_ != NULL)
        delete left_;
    if (right_ != NULL)
        delete right_;
}

bool equal(TreeNode *n1, TreeNode *n2) {
    if (n1 == NULL)
        return n2 == NULL;

    if (n2==NULL)
        return false;

    return (n1->getData() == n2->getData() &&
            equal(n1->getLeft(),n2->getLeft()) &&
            equal(n1->getRight(),n2->getRight()));
}

int TreeNode::getData() const {
    return data_;
}

TreeNode *TreeNode::getLeft() const {
    return left_;
}

TreeNode *TreeNode::getRight() const {
    return right_;
}

