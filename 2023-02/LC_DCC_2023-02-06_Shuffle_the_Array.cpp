// LC DCC 2023/02/06
// 1470. Shuffle the Array
// Easy

#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        int i = 0, j = n, k = 0;
        while(k < n) {
            ans.push_back(nums[i++]);
            ans.push_back(nums[j++]);
            k++;
        }
        return ans;
    }
};

int main() {
    Solution ob;
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> nums(2*n);
        for(int i=0; i<2*n; i++)
            cin>>nums[i];
        vector<int> ans = ob.shuffle(nums, n);
        for(auto el: ans)
            cout<<el<<' ';
        cout<<endl;
    }
    return 0;
}

/* Sample Input:
3
2
1 1 2 2
3
2 5 1 3 4 7
4
1 2 3 4 4 3 2 1

Sample Output:
1 2 1 2 
2 3 5 4 1 7 
1 4 2 3 3 2 4 1 

*/