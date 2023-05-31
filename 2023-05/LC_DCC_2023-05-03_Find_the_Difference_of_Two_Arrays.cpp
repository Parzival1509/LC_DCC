// LC DCC 2023/05/03
// 2215. Find the Difference of Two Arrays
// Easy

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1, s2;
        for(int num: nums1)
            s1.insert(num);
        for(int num: nums2)
            s2.insert(num);

        vector<vector<int>> ans(2);
        for(int i=0; i<nums1.size(); i++)
            if(s2.find(nums1[i]) == s2.end()) {
                ans[0].push_back(nums1[i]);
                s2.insert(nums1[i]);
            }
        for(int i=0; i<nums2.size(); i++)
            if(s1.find(nums2[i]) == s1.end()) {
                ans[1].push_back(nums2[i]);
                s1.insert(nums2[i]);
            }

        return ans;
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        int n, m;
        cin>>n>>m;
        vector<int> nums1(n, 0), nums2(m, 0);
        for(int &num: nums1)
            cin>>num;
        for(int &num: nums2)
            cin>>num;
        vector<vector<int>> ans = ob.findDifference(nums1, nums2);
        
        for(auto el: ans) {
            for(auto i: el)
                cout<<i<<' ';
            cout<<endl;
        }
    }
    return 0;
}

/* Sample Input:
2
3
1 2 3
2 4 6
4
1 2 3 3
1 1 2 2

Sample Output:
1 3 
4 6 
3 


*/