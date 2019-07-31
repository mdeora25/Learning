/* TASK AT HAND
 * Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai).
 * n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
 * Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 */
  
  
  /*
   * Results
   * Runtime: 20 ms, faster than 71.37% of C++ online submissions for Container With Most Water.
   * Memory Usage: 9.8 MB, less than 46.58% of C++ online submissions for Container With Most Water.  
   */
#include <iostream>
#include <math.h>
#include <string.h>
#include <vector>
using namespace std;
// the code i wrote is below
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxA = 0, l = 0, r = height.size() - 1;
        while ( l < r) {
            maxA = max(maxA,min(height[l],height[r]) * (r-l));
            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }
        return maxA;
    }
};
  

// system code is written below
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

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> height = stringToIntegerVector(line);
        
        int ret = Solution().maxArea(height);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}