// LC DCC 2023/05/08
// 1572. Matrix Diagonal Sum
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int ans = 0, n = mat.size();
        for(int i = 0; i < n; i++) {
            ans += mat[i][i];
            if(i != n-1-i) ans += mat[i][n-1-i];
        }
        return ans;
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<int>> mat(n, vector<int> (n, 0));
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                cin>>mat[i][j];
        cout<<ob.diagonalSum(mat)<<endl;
    }
    return 0;
}

/* Sample Input:
2
3
1 2 3
4 5 6
7 8 9
4
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1

Sample Output:
25
8

*/