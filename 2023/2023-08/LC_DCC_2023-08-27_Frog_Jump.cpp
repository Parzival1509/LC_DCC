// LC DCC 2023/08/27
// 403. Frog Jump
// Hard

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    bool find(vector<int> &stones, int i, int k, vector<vector<int>> &dp) {
        if(i == stones.size() - 1) return true;
        if(i >= stones.size()) return false;

        if(dp[i][k] != -1) return dp[i][k]; 

        bool res = false;
        for(int j = -1; j <= 1; j++) {
            int next_jump = k + j;

            if(next_jump > 0) {
                int in = lower_bound(stones.begin(), stones.end(), stones[i] + next_jump) - stones.begin();
                if(in == stones.size() || (stones[in] != stones[i] + next_jump))
                    continue;

                res = res || find(stones, in, next_jump, dp);
            }
        }

        return dp[i][k] = res;
    }
  
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        return find(stones, 0, 0, dp);
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n;
        cin >> n;
        vector<int> stones(n, 0);
        for(int &i: stones)
            cin >> i;
        if(ob.canCross(stones)) cout<<"true ";
        else cout<<"false ";
        cout<<endl;
    }

    return 0;
}

/* Sample Input:
2
8
0 1 3 5 6 8 12 17
8
0 1 2 3 4 8 9 11

Sample Output:
true 
false 

*/