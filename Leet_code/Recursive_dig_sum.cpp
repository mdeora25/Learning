//This question was done on hackerrank
/* TASK AT HAND
 * We define super digit of an integer  using the following rules:
 *Given an integer, we need to find the super digit of the integer.
 */
#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<string> split_string(string);

// Complete the superDigit function below.
int findsum(string n) {
    int sum = 0;
    for (int i = 0; i < n.length(); i++) {
        sum += (n[i] - '0');
    }
    if (sum/10 == 0) {
        return sum;
    } 
     return (findsum(to_string(sum)));
}
int superDigit(string n, int k) {
    string n1= n;
    for (int j = 0; j < k - 1; j++) {
        n+= n1;
    }
    return findsum(n);

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    string n = nk[0];

    int k = stoi(nk[1]);

    int result = superDigit(n, k);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

