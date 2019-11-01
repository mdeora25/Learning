#include <vector>
#include "BTreeNode.h"
std::vector<int> traverse(BTreeNode* root) {
    // your code here
    std::vector<int> v;
    if(root->is_leaf_ == false){
      for(unsigned long i = 0; i < root->children_.size(); i++){
        std::vector<int> temp;
        temp = traverse(root->children_[i]);
        for(unsigned long k = 0; k < temp.size(); k++){
          v.push_back(temp[k]);
        }
      }

      for(unsigned long j = 0; j < root->elements_.size(); j++){
        v.push_back(root->elements_[j]);
      }
      sort(v.begin(), v.end());
    }
    else{
      for(unsigned long j = 0; j < root->elements_.size(); j++){
        v.push_back(root->elements_[j]);
      }
    }

    return v;
}