#include "potd.h"
#include <iostream>

using namespace std;

string stringList(Node *head) {
    // your code here!
    string ans;
    int count = 0;
    if (head == NULL) return "Empty list";
    while (head != NULL) {
        ans += "Node " + to_string(count) +": " + to_string(head->data_);
        head = head->next_;
        count++;
        if (head != NULL) ans += " -> ";
    }
    
    return ans;
}
