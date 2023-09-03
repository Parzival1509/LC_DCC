// LC DCC 2023/07/28
// 486. Predict the Winner
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int score(vector<int>& nums, vector<vector<int>> &dp, int l, int r) {
        if (dp[l][r] != -1) return dp[l][r];
        if (l == r) return nums[l];
        
        int left = nums[l] - score(nums, dp, l + 1, r);
        int right = nums[r] - score(nums, dp, l, r - 1);
        dp[l][r] = max(left, right);
        
        return dp[l][r];
    }
    
    int dfs1(int i , int j ,vector<int>& nums , int turn){
        if(i == nums.size() || j == -1) return 0;
        if(i > j) return 0;
        if(turn == 0){
            return max(nums[i] + dfs1(i + 1 , j , nums , 1), 
                       nums[j] + dfs1(i , j - 1 , nums , 1));
        }
        else{
            return min(-nums[i] + dfs1(i + 1 , j , nums , 0),
                       -nums[j] + dfs1(i , j - 1 , nums , 0));
        }
    }

    int dfs2(int i , int j ,vector<int>& nums , int turn, vector<vector<vector<long>>> &dp) {
        if(i == nums.size() || j == -1 || i > j) return 0;

        if(dp[i][j][turn] != -1e10) return dp[i][j][turn];

        if(turn == 0)
            return dp[i][j][turn] = max(nums[i] + dfs2(i + 1 , j , nums , 1, dp), 
                nums[j] + dfs2(i , j - 1 , nums , 1, dp));
        else return dp[i][j][turn] = min(-nums[i] + dfs2(i + 1 , j , nums , 0, dp),
                - nums[j] + dfs2(i , j - 1 , nums , 0, dp));
    }

    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        
        // Approach 1:
        vector<vector<int>> dp = vector<vector<int>> (n, vector<int> (n, -1));
        return score(nums, dp, 0, n - 1) >= 0;

        // // Approach 2: Recursion
        // return dfs1(0 , n - 1 , nums , 0) >= 0;

        // // Approach 3: Memoized Code
        // vector<vector<vector<long>>> dp(n, vector<vector<long>> (n, vector<long> (2, -1e10)));
        // return dfs2(0, n - 1, nums, 0, dp) >= 0;
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
        if(ob.PredictTheWinner(nums)) cout<<"true ";
        else cout<<"false ";
        cout<<endl;
    }
    
    return 0;
}

/* Sample Input:
2
3
1 5 2
4
1 5 233 7

Sample Output:
false 
true 

*/