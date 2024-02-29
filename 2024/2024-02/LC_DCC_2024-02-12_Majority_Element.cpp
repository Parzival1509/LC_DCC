// LC DCC 2024/02/12
// 169. Majority Element
// Easy

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // // Approach 1: Using Hashmap
        // // S.C. = O(N), T.C. = O(N)
        // int n = nums.size();
        // unordered_map<int, int> hsh;
        // for(int i: nums)
        //     hsh[i]++;
        // for(auto e: hsh)
        //     if(e.second > n / 2)
        //         return e.first;

        // return -1;

        // Approach 2: Moore's Voting Algorithm
        // S.C. = O(1), T.C. = O(N)
        int ct = 0, e = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (ct == 0) {
                e = nums[i];
                ct = 1;
            } else if (e == nums[i])
                ct++;
            else ct--;
        }

        return e;
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
        cout << ob.majorityElement(nums) << endl;
    }

    return 0;
}

/* Sample Input
2
3
3 2 3
7
2 2 1 1 1 2 2

Sample Output
3
2

*/