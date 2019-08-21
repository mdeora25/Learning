#include <iostream>
#include <string>
#include <math.h>
#include <chrono>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> ans(2);
        int min_diff = INT_MAX;
        long int j;
        for (long int i = 1; i <= area; i++) {
            for (j = 1; j * i <= area; j++) {
                if (i < j) break;
                if (j * i == area && min_diff > (i - j) ) { 
                    min_diff = i - j;
                    ans[0] = i;
                    ans[1] = j;
                    break;
                }
            }
        }
        return ans;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        int area = stringToInteger(line);
        
        vector<int> ret = Solution().constructRectangle(area);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}