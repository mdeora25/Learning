/* TASK AT HAND
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * if you were only permitted to complete at most one transaction 
 * (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.
 */
  
  
  /*
   * Results
   * Runtime: 8 ms, faster than 70.12% of C++ online submissions for Best Time to Buy and Sell Stock.
   * Memory Usage: 9.6 MB, less than 79.49% of C++ online submissions for Best Time to Buy and Sell Stock.
   */
#include <iostream>
#include <math.h>
#include <string.h>
#include <vector>
using namespace std;
// the code i wrote starts here
class Solution {
public:
    int min_price= INT_MAX, max_pro = 0;
    int maxProfit(vector<int>& p) {
        for (int i = 0; i < p.size(); i++) {
           min_price = min(min_price,p[i]);
           max_pro = max(max_pro, p[i] - min_price);
         }
        return max_pro;
    }
};
// i stopped writing code from this line
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
        vector<int> prices = stringToIntegerVector(line);
        
        int ret = Solution().maxProfit(prices);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}