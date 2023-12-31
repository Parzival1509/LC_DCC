// LC DCC 2023/12/12
// 1464. Maximum Product of Two Elements in an Array
// Easy

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        return (nums[n - 1] - 1) * (nums[n - 2] - 1);
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n;
        cin >> n;
        vector<int> arr(n, 0);
        for(int &i: arr)
            cin >> i;
        cout << ob.maxProduct(arr) << endl;
    }

    return 0;
}

/* Sample Input:
3
4
3 4 5 2
4
1 5 4 5
2
3 7

Sample Output:
12
16
12

*/