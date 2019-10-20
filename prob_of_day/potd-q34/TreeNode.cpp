#include "TreeNode.h"

TreeNode::RotationType balanceTree(TreeNode*& subroot) {
	// Your code here
  if(getHeight(subroot->right_) - getHeight(subroot->left_) == 2){
    if(rightHeavy(subroot->right_)){
      return TreeNode::left;
    }
    else if(leftHeavy(subroot->right_)){
      return TreeNode::rightLeft;
    }
  }
  if(getHeight(subroot->right_) - getHeight(subroot->left_) == -2){
    if(rightHeavy(subroot->left_)){
      return TreeNode::leftRight;
    }
    else if(leftHeavy(subroot->left_)){
      return TreeNode::right;
    }
  }
  return TreeNode::right;
}
