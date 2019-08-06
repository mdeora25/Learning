

#include <iostream>
#include <string>
#include <math.h>
#include <chrono>
using namespace std;
int main() {
    string line;
    getline(cin,line);
    if (line[0] == '1' && line.size() == 1) {
        cout<<line<<endl;
    } else {
        while (1) {
            int num,sum = 0;
            for (int i = 0; i < line.size(); i++) {
                sum += pow((int(line[i]) - 48),2);
            }
            line = to_string(sum);
            if (sum == 1) {
                cout<<sum<<endl;
                break;
            } else if (sum == 4) {
                cout<<0<<endl;
                break;
            }
        }
    }
        
    
    return 0;
}