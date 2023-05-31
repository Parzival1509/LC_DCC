// LC DCC 2023/01/20
// 491. Non-decreasing Subsequences
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    set<vector<int>> s;

    void solve(int ind, vector<int>& nums, vector<int>& ds, set<vector<int>>& s, int n) {
        // Base Condition
        if(ind == n) {
            if(ds.size() > 1) s.insert(ds);
            return;
        }

        if(ds.size()==0 || nums[ind] >= ds.back()) {
            // Pick the element
            ds.push_back(nums[ind]);
            solve(ind+1, nums, ds, s, n);
            // Don't Pick the element
            ds.pop_back();
        }
        solve(ind+1, nums, ds, s, n);
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> s;
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0, nums, ds, s, nums.size());
        for(auto el: s)
            ans.push_back(el);
        return ans;
    }
};

int main() {
    int T;
    cin>>T;
    Solution ob;
    while(T--) {
        int n;
        cin>>n;
        vector<int> nums(n);
        for(int i=0; i<n; i++)
            cin>>nums[i];
        vector<vector<int>> ans = ob.findSubsequences(nums);
        for(auto el: ans) {
            for(auto ell: el)
                cout<<ell<<' ';
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}

/* Sample Input
2
4
4 6 7 7
5
4 4 3 2 1

Sample Output
4 6 
4 6 7 
4 6 7 7 
4 7 
4 7 7 
6 7 
6 7 7 
7 7 

4 4 


*/