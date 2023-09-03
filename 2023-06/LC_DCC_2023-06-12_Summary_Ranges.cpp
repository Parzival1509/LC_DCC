// LC DCC 2023/06/12
// 228. Summary Ranges
// Easy

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size() == 0) return {};
        
        vector<string> ans;
        int a = nums[0], ct = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i - 1] + 1)
                ct++;
            else if(ct == 1) {
                ans.push_back(to_string(a));
                a = nums[i];
                ct = 1;
            }
            else {
                ans.push_back(to_string(a) + "->" + to_string(nums[i-1]));
                a = nums[i];
                ct = 1;
            }
        }

        if(ct == 1) ans.push_back(to_string(a));
        else ans.push_back(to_string(a) + "->" + to_string(nums[nums.size()-1]));

        return ans;
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        int n;
        cin >> n;
        vector<int> nums(n, 0);
        for(int &i: nums)
            cin >> i;
        vector<string> ans = ob.summaryRanges(nums);
        for(auto i: ans)
            cout << i << endl;
        cout << endl;
    }
    return 0;
}

/* Sample Input:
2
6
0 1 2 4 5 7
7
0 2 3 4 6 8 9

Sample Output:
0->2
4->5
7

0
2->4
6
8->9


*/