// LC DCC 2024/04/13
// 85. Maximal Rectangle
// Hard

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;

        int rows = matrix.size(), cols = matrix[0].size();
        int maxArea = 0;
        vector<int> heights(cols + 1, 0);

        for (const auto& row : matrix) {
            for (int i = 0; i < cols; i++)
                heights[i] = (row[i] == '1') ? heights[i] + 1 : 0;

            stack<int> stk;
            for (int i = 0; i < heights.size(); i++) {
                while (!stk.empty() && heights[i] < heights[stk.top()]) {
                    int h = heights[stk.top()];
                    stk.pop();
                    int w = stk.empty() ? i : (i - stk.top() - 1);
                    maxArea = max(maxArea, h * w);
                }
                stk.push(i);
            }
        }

        return maxArea;
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        int m, n;
        cin >> m >> n;
        vector<vector<char>> matrix(m, vector<char> (n, '0'));
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                cin >> matrix[i][j];

        cout << ob.maximalRectangle(matrix) << endl;
    }

    return 0;
}

/* Sample Input
3
1 1
1
1 1
0
4 5
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Sample Output
1
0
6

*/