// LC DCC 2023/09/08
// 118. Pascal's Triangle
// Easy

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> r(numRows);

        for(int i = 0; i < numRows; i++) {
            r[i].resize(i + 1);
            r[i][0] = r[i][i] = 1;
  
            for(int j = 1; j < i; j++)
                r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
        }
        
        return r;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int numRows;
        cin >> numRows;

        vector<vector<int>> ans = ob.generate(numRows);

        for(auto row: ans) {
            for(int i = numRows - row.size(); i > 0; i--)
                cout << ' ';
            for(int i: row)
                cout << i << ' ';
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}

/* Sample Input:
2
3
5

Sample Output:
  1 
 1 1 
1 2 1 

    1 
   1 1 
  1 2 1 
 1 3 3 1 
1 4 6 4 1 


*/