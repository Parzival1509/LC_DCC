// LC DCC 2024/02/14
// 2149. Rearrange Array Elements by Sign
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int pos = 0, neg = 1, n = nums.size();
        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                ans[pos] = nums[i];
                pos += 2;
            } else {
                ans[neg] = nums[i];
                neg += 2;
            }
        }

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
        vector<int> nums(n, 0);
        for(int &i: nums)
            cin >> i;
        vector<int> ans = ob.rearrangeArray(nums);
        for(int i: ans)
            cout << i << ' ';
        cout << endl;
    }

    return 0;
}

/* Sample Input
2
2
-1 1
6
3 1 -2 -5 2 -4

Sample Output
1 -1 
3 -2 1 -5 2 -4 

*/