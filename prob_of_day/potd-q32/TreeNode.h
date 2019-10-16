#ifndef TreeNode_H
#define TreeNode_H

#include <cstddef>

// Definition for a binary tree node.
struct TreeNode {
    int val_;
    int balance_;
    TreeNode *left_;
    TreeNode *right_;
    TreeNode(int x) {
      left_ = NULL;
      right_ = NULL;
      val_ = x;
      balance_ = 0;
    }
};

TreeNode* findLastUnbalanced(TreeNode* root);

int calculate_height(TreeNode* root);

bool isHeightBalanced(TreeNode* root);

void deleteTree(TreeNode* root);

#endif