// LC DCC 2024/04/12
// 42. Trapping Rain Water
// Hard

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left[n], right[n];

        left[0] = height[0];
        for (int i = 1; i < n; i++)
            left[i] = max(left[i - 1], height[i]);

        right[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--)
            right[i] = max(right[i + 1], height[i]);

        int ans = 0;
        for (int i = 0; i < n; i++)
            ans += (min(left[i], right[i]) - height[i]);

        return ans;
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> height(n, 0);
        for(int &i: height)
            cin >> i;
        cout << ob.trap(height) << endl;
    }

    return 0;
}

/* Sample Input
2
6
4 2 0 3 2 5
12
0 1 0 2 1 0 1 3 2 1 2 1

Sample Output
9
6

*/