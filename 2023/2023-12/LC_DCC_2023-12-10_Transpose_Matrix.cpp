// LC DCC 2023/12/10
// 867. Transpose Matrix
// Easy

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> trans(n, vector<int> (m, 0));

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                trans[j][i] = matrix[i][j];

        return trans;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int m, n;
        cin >> m >> n;
        vector<vector<int>> matrix(m, vector<int> (n, 0));
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                cin >> matrix[i][j];

        vector<vector<int>> trans = ob.transpose(matrix);
        for(auto i: trans) {
            for(int e: i)
                cout << e << ' ';
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}

/* Sample Input:
2
3 3
1 2 3
4 5 6
7 8 9
2 3
1 2 3
4 5 6

Sample Output:
1 4 7 
2 5 8 
3 6 9 

1 4 
2 5 
3 6 

*/