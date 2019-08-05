/* TASK AT HAND
 * Given the root node of a binary search tree
 * return the sum of values of all nodes with value between L and R (inclusive).
 */
  
  
  /*
   * Results
   * Runtime: 140 ms, faster than 92.97% of C++ online submissions for Range Sum of BST.
   * Memory Usage: 41.3 MB, less than 75.25% of C++ online submissions for Range Sum of BST.
   */
#include <iostream>
#include <math.h>
#include <string.h>
#include <vector>
using namespace std;

class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        if (root == NULL) {
            return NULL;
        } else if(root->val >= L && root->val <= R) {
            return root->val + rangeSumBST(root->left,L,R) + rangeSumBST(root->right,L,R);
            
        } else if (root->val < L) {
            return  rangeSumBST(root->right,L,R);
        } else {
           return rangeSumBST(root->left,L,R);
        }
        
    }
};