/* TASK AT HAND
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path 
 * such that adding up all the values along the path equals the given sum.
 */
  
  
  /*
   * Results
   * Runtime: 8 ms, faster than 96.67% of C++ online submissions for Path Sum.
   * Memory Usage: 19.8 MB, less than 93.75% of C++ online submissions for Path Sum
   */
#include <iostream>
#include <math.h>
#include <string.h>
#include <vector>
using namespace std;
// The code i wrote starts from here


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    bool findsum(TreeNode* root, int sum, int mainSum) {
        if (root == NULL) return false;
        sum += root->val;
        if (sum == mainSum && (!root->left && !root->right)) return true;
        
        return findsum(root->left,sum,mainSum) || findsum(root->right,sum,mainSum);
      
    }
    bool hasPathSum(TreeNode* root, int sum) {
        return findsum(root,0,sum);
    }
};
// I stopped writing code from here


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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        getline(cin, line);
        int sum = stringToInteger(line);
        
        bool ret = Solution().hasPathSum(root, sum);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}