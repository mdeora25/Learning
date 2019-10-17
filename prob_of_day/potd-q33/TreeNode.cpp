#include "TreeNode.h"
#include <algorithm>
void rightRotate(TreeNode* root) {


 // Your code here
    TreeNode* head, *temp;
    head = root->left_;
    temp = head->right_;
    root->left_ = temp;
    temp->parent_ = root;
    head->right_ = root;
    root->parent_ = head;
    head->parent_ = NULL;
}


void leftRotate(TreeNode* root) {

    // your code here
    TreeNode* head, *temp;
    head = root->right_;
    temp = head->left_;
    root->right_ = temp;
    temp->parent_ = root;
    head->left_ = root;
    root->parent_ = head;
    head->parent_ = NULL;
}


void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}

