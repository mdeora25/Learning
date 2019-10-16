#include "TreeNode.h"
bool isHeightBalanced(TreeNode* root) {
  // your code here
  return (calculate_height(root->left_) - calculate_height(root->right_) == 1 ||
          calculate_height(root->left_) - calculate_height(root->right_) == -1||
          calculate_height(root->left_) - calculate_height(root->right_) == 0);
}

void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}

//helper function
int calculate_height(TreeNode* root){
  if(root == NULL){return -1;}
  if(root->left_ == NULL && root->right_ == NULL){
    return 0;
  }
  int leftheight = 0;
  int rightheight = 0;
  if(root->left_ != NULL){
    leftheight = calculate_height(root->left_);
  }
  if(root->right_ != NULL){
    rightheight = calculate_height(root->right_);
  }
  if(rightheight >= leftheight){
    return rightheight + 1;
  }
  else{
    return leftheight + 1;
  }
}
