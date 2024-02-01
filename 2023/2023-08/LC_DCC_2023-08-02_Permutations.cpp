// LC DCC 2023/08/02
// 46. Permutations
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    // Approach 1: Using Extra Space Complexity of O(n)
    // void findPermutations(int n, vector<int> &ds, vector<int> &f, vector<int> &a, vector<vector<int>> &ans) {
    //     if(ds.size() == n) {
    //         ans.push_back(ds);
    //         return;
    //     }
    //     for(int i = 0; i < n; i++) {
    //         if(!f[i]) {
    //             ds.push_back(a[i]);
    //             f[i] = 1;
    //             findPermutations(n, ds, f, a, ans);
    //             f[i] = 0;
    //             ds.pop_back();
    //         }
    //     }
    // }

    // vector<vector<int>> permute(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> ds, f(n, 0);
    //     vector<vector<int>> ans;
    //     findPermutations(n, ds, f, nums, ans);
    //     return ans;
    // }

    // Approach 2: No Extra Space Complexity
    void findPermutations(int ind, int n, vector<int> &a, vector<vector<int>> &ans){
        if(ind == n) {
            ans.push_back(a);
            return;
        }
        for(int i = ind; i < n; i++) {
            swap(a[ind], a[i]);
            findPermutations(ind + 1, n, a, ans);
            swap(a[ind], a[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        findPermutations(0, n, nums, ans);
        return ans;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while(T--) {
        int n;
        cin >> n;
        vector<int> nums(n, 0);
        for(int &i: nums)
            cin >> i;

        vector<vector<int>> ans = ob.permute(nums);
        for(auto v: ans) {
            for(int i: v)
                cout << i << ' ';
            cout << endl;
        }
        cout << endl;
    }
    
    return 0;
}

/* Sample Input:
3
1
1
2
0 1
3
1 2 3

Sample Output:
1 

0 1 
1 0 

1 2 3 
1 3 2 
2 1 3 
2 3 1 
3 2 1 
3 1 2 


*/