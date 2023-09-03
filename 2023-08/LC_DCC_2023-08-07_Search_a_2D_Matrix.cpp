// LC DCC 2023/08/07
// 74. Search a 2D Matrix
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        if(target < matrix[0][0] || target > matrix[m - 1][n - 1])
            return false;

        // Finding out the row
        int row = -1;
        for(int i = 0; i < m; i++) {
            if(target >= matrix[i][0] && target <= matrix[i][n - 1]) {
                row = i;
                break;
            }
        }
        if(row == -1) return false;

        // Finding out the column
        int lo = 0, hi = n - 1, col;
        while(lo < hi) {
            col = (lo + hi) / 2;
            int x = matrix[row][col];

            if(x == target) return true;
            
            if(x < target) lo = col + 1;
            else hi = col - 1;
        }

        if(matrix[row][lo] == target)
            return true;
        return false;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while(T--) {
        int m, n, target;
        cin >> m >> n >> target;
        vector<vector<int>> matrix(m, vector<int> (n, 0));
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                cin >> matrix[i][j];

        if(ob.searchMatrix(matrix, target)) cout<<"true ";
        else cout<<"false ";
        cout<<endl;
    }
    
    return 0;
}

/* Sample Input:
4

3 4 3
1 3 5 7
10 11 16 20
23 30 34 60

3 4 13
1 3 5 7
10 11 16 20
23 30 34 60

1 1 1
1

2 1 2
1 3

Sample Output:
true 
false 
true 
false 

*/