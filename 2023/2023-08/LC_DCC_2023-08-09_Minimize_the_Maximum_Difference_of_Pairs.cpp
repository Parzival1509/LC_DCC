// LC DCC 2023/08/09
// 2616. Minimize the Maximum Difference of Pairs
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        if(p == 0 || n == 0) return 0;
        
        sort(nums.begin(), nums.end());
        int lo = 0, hi = nums[n - 1] - nums[0];
        while(lo < hi) {
            int mid = (lo + hi) / 2, k = 0;
            for(int i = 1; i < n && k < p; i++)
                if(nums[i] - nums[i - 1] <= mid) {
                    k++;
                    i++;
                }

            if(k < p) lo = mid + 1;
            else hi = mid;
        }

        return lo;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while(T--) {
        int n, p;
        cin >> n >> p;
        vector<int> nums(n, 0);
        for(int &i: nums)
            cin >> i;
        cout << ob.minimizeMax(nums, p) << endl;
    }
    
    return 0;
}

/* Sample Input:
2
6 2
10 1 2 7 1 3
4 1
4 2 1 2

Sample Output:
1
0

*/