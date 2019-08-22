#include <iostream>
#include <math.h>
#include <string.h>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& speed) {
         map<int, double> m;
        for (int i = 0; i < pos.size(); i++) m[-pos[i]] = (double)(target - pos[i]) / speed[i];
        int res = 0; double cur = 0;
        for (auto it : m) if (it.second > cur) cur = it.second, res++;
        return res;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

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
        int target = stringToInteger(line);
        getline(cin, line);
        vector<int> position = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> speed = stringToIntegerVector(line);
        
        int ret = Solution().carFleet(target, position, speed);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}