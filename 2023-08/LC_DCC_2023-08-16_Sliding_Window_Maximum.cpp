// LC DCC 2023/08/16
// 239. Sliding Window Maximum
// Hard

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        
        for (int i = 0; i < nums.size(); i++) {
            if (!dq.empty() && dq.front() == i - k)
                dq.pop_front();

            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            dq.push_back(i);

            if (i >= k - 1)
                ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n, 0);
        for(int &i: nums)
            cin >> i;

        vector<int> ans = ob.maxSlidingWindow(nums, k);
        for(int i: ans)
            cout << i << ' ';
        cout << endl;
    }

    return 0;
}

/* Sample Input:
3
1 1
1
8 3
1 3 -1 -3 5 3 6 7
2 1
1 -1

Sample Output:
1 
3 3 5 5 6 7 
1 -1 

*/