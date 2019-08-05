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
// i started writing code here
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
//stopped writing code
void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        getline(cin, line);
        int L = stringToInteger(line);
        getline(cin, line);
        int R = stringToInteger(line);
        
        int ret = Solution().rangeSumBST(root, L, R);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}