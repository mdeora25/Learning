/* TASK AT HAND
 * Every email consists of a local name and a domain name, separated by the @ sign.
 * If you add periods ('.') between some characters in the local name part of an email address, mail sent there will be forwarded to the same address without dots in the local name.
 * f you add a plus ('+') in the local name, everything after the first plus sign will be ignored. 
 */
  
  
  /*
   * Results
   * Runtime: 44 ms, faster than 19.13% of C++ online submissions for Unique Email Addresses.
   * Memory Usage: 12.3 MB, less than 85.71% of C++ online submissions for Unique Email Addresses.
   */
#include <iostream>
#include <math.h>
#include <string.h>
#include <vector>
using namespace std;

class Solution {
public:
    
    int numUniqueEmails(vector<string>& emails) {
        set<string> ans;
        string temp = "";
        for (int i = 0; i < emails.size();i++) {
            temp = "";
            int size = emails[i].find('@');
            for (int j = 0 ; j < size; j++) {
                if (emails[i][j] == '+') break;
                if (emails[i][j] == '.')  continue;
                else temp += emails[i][j];
                temp+=emails[i].substr(size,emails[i].size()-size-1);
                }
           
            ans.insert(temp);
        }
        return ans.size();
    }
};