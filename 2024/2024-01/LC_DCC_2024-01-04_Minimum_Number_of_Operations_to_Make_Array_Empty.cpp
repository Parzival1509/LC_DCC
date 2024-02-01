// LC DCC 2024/01/04
// 2870. Minimum Number of Operations to Make Array Empty
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i: nums)
            mp[i]++;
        
        int ans = 0;
        for(auto i: mp) {
            if(i.second == 1) return -1;

            ans += ceil(1.0 * i.second / 3);
        }

        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n;
        cin >> n;
        vector<int> nums(n, 0);
        for(int &i: nums)
            cin >> i;
        cout << ob.minOperations(nums) << endl;
    }

    return 0;
}

/* Sample Input:
2
9
2 3 3 2 2 4 2 3 4
6
2 1 2 2 3 3

Sample Output:
4
-1

*/