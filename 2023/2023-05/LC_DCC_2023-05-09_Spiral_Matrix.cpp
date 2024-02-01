// LC DCC 2023/05/09
// 54. Spiral Matrix
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int rowBegin = 0, rowEnd = matrix.size() - 1;
        int colBegin = 0, colEnd = matrix[0].size() - 1;
        
        while(rowBegin <= rowEnd && colBegin <= colEnd) {
            for(int j = colBegin; j <= colEnd; j++)
                res.push_back(matrix[rowBegin][j]);
            rowBegin++;

            for(int j = rowBegin; j <= rowEnd; j++)
                res.push_back(matrix[j][colEnd]);
            colEnd--;
            
            if(rowBegin <= rowEnd)
                for(int j = colEnd; j >= colBegin; j--)
                    res.push_back(matrix[rowEnd][j]);
            rowEnd--;
            
            if(colBegin <= colEnd)
                for(int j = rowEnd; j >= rowBegin; j--)
                    res.push_back(matrix[j][colBegin]);
            colBegin++;
        }

        return res;
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        int m, n;
        cin>>m>>n;
        vector<vector<int>> matrix(m, vector<int> (n, 0));
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                cin>>matrix[i][j];
        vector<int> ans = ob.spiralOrder(matrix);
        for(int i: ans)
            cout<<i<<' ';
        cout<<endl;
    }
    return 0;
}

/* Sample Input:
2
3 3
1 2 3
4 5 6
7 8 9
3 4
1 2 3 4
5 6 7 8
9 10 11 12

Sample Output:
1 2 3 6 9 8 7 4 5 
1 2 3 4 8 12 11 10 9 5 6 7 

*/