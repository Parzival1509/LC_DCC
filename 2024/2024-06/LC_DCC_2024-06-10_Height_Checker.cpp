// LC DCC 2024/06/10
// 1051. Height Checker
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<char> sorted(heights.begin(), heights.end());
        sort(heights.begin(), heights.end());
        
        int n = heights.size(), ans = 0;
        for (int i = 0; i < n; i++)
            ans += (heights[i] != sorted[i]);
        
        return ans;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while (T--) {
        int n;
        cin >> n;
        vector<int> heights(n, 0);
        for(int &i: heights)
            cin >> i;
        cout << ob.heightChecker(heights) << endl;
    }

    return 0;
}

/* Sample Input
3
6
1 1 4 2 1 3
5
5 1 2 3 4
5
1 2 3 4 5

Sample Output
3
5
0

*/