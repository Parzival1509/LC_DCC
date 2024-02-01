// LC DCC 2022/12/25
// 2389. Longest Subsequence With Limited Sum
// Easy

#include <bits/stdc++.h>
using namespace std;

// Baijnath's Sol
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();
        sort(nums.begin(), nums.end());
        vector<int> prefix(n);

        int temp=0;
        for(int i=0; i<n; i++) {
           temp += nums[i];
           prefix[i] = temp;
        }
        vector<int> ans;
        for(int i=0; i<m; i++) {
            int query = queries[i];
            ans.push_back(upper_bound(prefix.begin(), prefix.end(), query) - prefix.begin());        
        }
        return ans;
    }
};

int main() {
    int T;
    cin>>T;
    Solution ob;
    while(T--) {
        int n, m;
        cin>>n>>m;
        vector<int> nums(n), queries(m);
        for(int i=0; i<n; i++)
            cin>>nums[i];
        for(int i=0; i<m; i++)
            cin>>queries[i];
        vector<int> ans = ob.answerQueries(nums, queries);
        for(int i=0; i<m; i++)
            cout<<ans[i]<<' ';
        cout<<endl;
    }
}

/* Sample Input
1
4 3
4 5 2 1
3 10 21

Sample Output
2 3 4

*/