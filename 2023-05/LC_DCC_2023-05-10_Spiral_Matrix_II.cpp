// LC DCC 2023/05/10
// 59. Spiral Matrix II
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int> (n, 0));
        int rowBegin = 0, rowEnd = n - 1;
        int colBegin = 0, colEnd = n - 1;
        int i = 1;

        while(rowBegin <= rowEnd && colBegin <= colEnd) {
            for(int j = colBegin; j <= colEnd; j++)
                matrix[rowBegin][j] = i++;
            rowBegin++;

            for(int j = rowBegin; j <= rowEnd; j++)
                matrix[j][colEnd] = i++;
            colEnd--;
            
            if(rowBegin <= rowEnd)
                for(int j = colEnd; j >= colBegin; j--)
                    matrix[rowEnd][j] = i++;
            rowEnd--;
            
            if(colBegin <= colEnd)
                for(int j = rowEnd; j >= rowBegin; j--)
                    matrix[j][colBegin] = i++;
            colBegin++;
        }

        return matrix;
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<int>> matrix = ob.generateMatrix(n);
        for(auto row: matrix) {
            for(int ele: row)
                cout<<ele<<"\t";
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}

/* Sample Input:
2
3
4

Sample Output:
1   2   3   
8   9   4   
7   6   5   

1   2   3   4   
12  13  14  5   
11  16  15  6   
10  9   8   7   


*/