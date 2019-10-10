#include "TreeNode.h"

#include <cstddef>
#include <iostream>
using namespace std;

TreeNode::TreeNode() : left_(NULL), right_(NULL) { }

int TreeNode::getHeight() {
  int left, right;
  left = 0;
  right = 0;
  if(left_ == NULL && right_ == NULL){
    return 0;
  }
  if(left_ != NULL){left = left_->getHeight();}
  if(right_ != NULL){right = right_->getHeight();}
  return 1 + max(left,right);
}
