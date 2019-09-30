#include <string>
#include <stack>

using namespace std;

bool isValid(string input) {
    stack<char> st;
    for (unsigned i = 0; i < input.length(); i++) {
        if (input[i] == '{' || input[i] == '[' || input[i] == '(') {
            st.push(input[i]);
        
        } else if (!st.empty()) { 
    		if (st.top() == '[' && input[i] == ']') st.pop();
    		else if (st.top() == '(' && input[i] == ')') st.pop();
    		else if (st.top() == '{' && input[i] == '}') st.pop();
    		else if (input[i] == ']' || input[i] == ')' || input[i] == '}') st.push(input[i]);
    	}
         else if (input[i] == '}' || input[i] == ']' || input[i] == ')') {
            if (st.empty()) return false;
            st.pop();
        }
    }
    if (!st.empty()) return false;
    return true;    // modify this!
}