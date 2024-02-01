// LC DCC 2023/10/16
// 119. Pascal's Triangle II
// Easy

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> triangle(rowIndex + 1);

        for(int i = 0; i <= rowIndex; i++) {
            triangle[i].resize(i + 1);
            triangle[i][0] = triangle[i][i] = 1;

            for(int j = 1; j < i; j++)
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }

        return triangle[rowIndex];
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int rowIndex;
        cin >> rowIndex;
        vector<int> ans = ob.getRow(rowIndex);
        for(int i: ans)
            cout << i << ' ';
        cout << endl;
    }

    return 0;
}

/* Sample Input:
3
3 0 1

Sample Output:
1 3 3 1 
1 
1 1 

*/