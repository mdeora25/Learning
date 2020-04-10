#include <bits/stdc++.h>
#include <queue>
#include <utility>

using namespace std;

vector<string> split_string(string);
;
// Complete the countLuck function below.
int check_0 (vector<string> matrix, int r, int c) {
     int row = matrix.size();
    int col = matrix[0].size();
    int count = 0;
    cout<<r<<","<<c<<endl;
    
    if (c + 1 < col) { //right
      //cout<<"col + 1 is "<<c+1<< ' '<<r<<endl;
      if(matrix[r][c+1] == '.' || matrix[r][c+1] == '*') {
          count++;
      }
      
    }
    if (c - 1 >= 0) { //left
      //cout<<"col - 1 is "<<c-1<< ' '<<r<<endl;
        if(matrix[r][c-1] == '.' || matrix[r][c-1] == '*') {
          count++;
      }
    }
    if (r + 1 < row) { //down
       //cout<<"row + 1 is "<<r+1<< ' '<<c<<endl;
        if(matrix[r+1][c] == '.' || matrix[r+1][c] == '*') {
          count++;
      }
      }
    if (r - 1 >= 0) {  //up
        //cout<<"row - 1 is "<<r-1<< ' '<<c<<endl;
        if(matrix[r-1][c] == '.' || matrix[r-1][c] == '*') {
          count++;
      }
      }
    cout<<"count - 1 is "<<count - 1<<endl;
    if (count - 1 >= 1) {return 1;}
   return 0;
}
int check (vector<string> matrix,map<pair<int,int>,int>&track, int r, int c) {
     int row = matrix.size();
    int col = matrix[0].size();
    int count = 0;
    cout<<r<<","<<c<<endl;
    pair<int,int> hold(r,c-1);
    if (c - 1 >= 0 && track.find(hold) == track.end()) { //left
      //cout<<"col - 1 is "<<c-1<< ' '<<r<<endl;
        if(matrix[r][c-1] == '.' || matrix[r][c-1] == '*') {
          count++;
      }
    }
    pair<int,int> hold1(r+1,c);
    if (r + 1 < row && track.find(hold1) == track.end()) { //down
       //cout<<"row + 1 is "<<r+1<< ' '<<c<<endl;
        if(matrix[r+1][c] == '.' || matrix[r+1][c] == '*') {
          count++;
      }
      }
    pair<int,int> hold2(r-1,c);
    if (r - 1 >= 0 && track.find(hold2) == track.end()) {  //up
        //cout<<"row - 1 is "<<r-1<< ' '<<c<<endl;
        if(matrix[r-1][c] == '.' || matrix[r-1][c] == '*') {
          count++;
      }
      }
    
    pair<int,int> hold3(r,c+1);
    if (c + 1 < col && track.find(hold3) == track.end()) { //right
      //cout<<"col + 1 is "<<c+1<< ' '<<r<<endl;
      if(matrix[r][c+1] == '.' || matrix[r][c+1] == '*') {
          count++;
      }
      
    }
    
   
    
    cout<<"count  is "<<count<<endl;
    if (count  > 1) {return 1;}
   return 0;
}
int search(vector<string> matrix,int r, int c,stack<string> &dir, stack<pair<int,int>> &list,map<pair<int,int>,int>&track) {
    pair<int,int> hold(r,c);
    if (track.find(hold) != track.end() || matrix[r][c] == 'X') {
        return 0;
    }
    cout<<"r and c is "<<r<<","<<c<<endl;
    if (matrix[r][c] == '*') {
      return 1;
    }
    
    
    track.insert(make_pair(hold,1));
    int row = matrix.size();
    int col = matrix[0].size();
    if (c + 1 < col) { //right
      //cout<<"col + 1 is "<<c+1<< ' '<<r<<endl;
      if (search(matrix,r,c+1,dir,list,track) == 1) {
          list.push(make_pair(r,c+1));
          //cout<<'h'<<endl;
          
             dir.push("right");
          
          return 1;
      }
    }
    if (c - 1 >= 0) { //left
      //cout<<"col - 1 is "<<c-1<< ' '<<r<<endl;
      if (search(matrix,r,c-1,dir,list,track) == 1) {
          list.push(make_pair(r,c-1));
          
           dir.push("left");
          
          //cout<<"hi"<<endl;
           //cout<<list.top().first<< ' '<<list.top().second<<endl;
          return 1;
      }
    }
    if (r + 1 < row) { //down
       //cout<<"row + 1 is "<<r+1<< ' '<<c<<endl;
       if (search(matrix,r+1,c,dir,list,track) == 1) {
           list.push(make_pair(r+1,c));
           
             dir.push("down");
          
           //cout<<list.top().first<< ' '<<list.top().second<<endl;
          return 1;
      }
    }
    if (r - 1 >= 0) {  //up
        //cout<<"row - 1 is "<<r-1<< ' '<<c<<endl;
        if (search(matrix,r-1,c,dir,list,track) == 1) {
          list.push(make_pair(r-1,c));
           
             dir.push("up");
          
           //cout<<list.top().first<< ' '<<list.top().second<<endl;
          return 1;
      }
    }
    return -1;
}

string countLuck(vector<string> matrix, int k) {
 int row = matrix.size();
 int col = matrix[0].size(); 
 int r,c,hold= 0;
 for (r = 0; r < row; r++) {
     for (c = 0; c < col; c++) {
         if (matrix[r][c] == 'M') {
          hold = 1;
          break;
          }
         
     }
     if (hold) {break;}
 }
 
 map<pair<int,int>,int> track;
 map<pair<int,int>,int> temp;
 stack<pair<int,int>> list;
 queue<pair<int,int>> hold_t;
 stack<string> dir;
 
 hold = -2;
 hold = search(matrix,r, c,dir,list,track);
 cout<<hold<<endl;
 cout<<"path val"<<endl;
 list.push(make_pair(r,c));
 int count = 0;
 while(!list.empty()) {
     //hold_t.push(list.top());
     temp.insert(make_pair(list.top(), 1));
     if(matrix[list.top().first][list.top().second] != '*') {
      count += check(matrix, temp, list.top().first, list.top().second);
     }
     list.pop();
 }
 cout<<"path val done"<<endl;

  //count += check_0( matrix, r,  c);
  cout<<"final count"<<count<<endl;
 
  string an = "Impressed";
  if(count != k) {an = "Oops!";}
  
 return an;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string nm_temp;
        getline(cin, nm_temp);

        vector<string> nm = split_string(nm_temp);

        int n = stoi(nm[0]);

        int m = stoi(nm[1]);

        vector<string> matrix(n);

        for (int i = 0; i < n; i++) {
            string matrix_item;
            getline(cin, matrix_item);

            matrix[i] = matrix_item;
        }

        int k;
        cin >> k;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string result = countLuck(matrix, k);

        fout << result << "\n";
    }

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
