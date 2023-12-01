// LC DCC 2023/11/23
// 1630. Arithmetic Subarrays
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size(), m = l.size();
        vector<bool> ans(m);

        for(int i = 0; i < m; i++) {
            bool flag = true;
            vector<int> tmp;
            
            // Copy the vector from nums[l[i]] to nums[r[i]] in a temporary vector
            copy(nums.begin() + l[i], nums.begin() + r[i] + 1, back_inserter(tmp));

            sort(tmp.begin(), tmp.end());
            int t = r[i] - l[i] + 1;

            // for(int i: tmp)
            //     cout << i << ' ';
            // cout << endl;

            for(int j = 1; j < t - 1; j++)
                if(tmp[j + 1] - tmp[j] != tmp[1] - tmp[0]) {
                    flag = false;
                    break;
                }

            ans[i] = flag;
        }

        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n, m;
        cin >> n >> m;
        
        vector<int> nums(n, 0), l(m, 0), r(m, 0);
        for(int &i: nums)
            cin >> i;
        for(int &i: l)
            cin >> i;
        for(int &i: r)
            cin >> i;

        vector<bool> ans = ob.checkArithmeticSubarrays(nums, l, r);
        for(bool i: ans)
            if(i) cout << "true ";
            else cout << "false ";
        cout << endl;
    }

    return 0;
}

/* Sample Input:
2

6 3
4 6 5 9 3 7
0 0 2
2 3 5

11 6
-12 -9 -3 -12 -6 -15 20 -25 -20 -15 -10
0 1 6 4 8 7
4 4 9 7 9 10


Sample Output:
true false true 
false true false false true true 

*/