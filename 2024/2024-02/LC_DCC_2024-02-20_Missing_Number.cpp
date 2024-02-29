// LC DCC 2024/02/20
// 268. Missing Number
// Easy

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        return (n * (n + 1) / 2) - sum;
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> nums(n, 0);
        for(int &i: nums)
            cin >> i;
        cout << ob.missingNumber(nums) << endl;
    }

    return 0;
}

/* Sample Input
3
3
1 0 3
2
0 1
9
9 6 4 2 3 5 7 0 1

Sample Output
2
2
8

*/