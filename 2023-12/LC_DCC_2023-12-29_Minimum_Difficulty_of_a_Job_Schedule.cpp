// LC DCC 2023/12/29
// 1335. Minimum Difficulty of a Job Schedule
// Hard

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int minDifficultyOptimized(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();

        if(n < d) return -1;
        
        if(n == d) {
            int totalDifficulty = 0;
            for(int difficulty: jobDifficulty)
                totalDifficulty += difficulty;
            
            return totalDifficulty;
        }

        vector<int> dp(n), dpPrev(n), stkIdx;
        dp[0] = jobDifficulty[0];
        for(int i = 1; i < n; ++i)
            dp[i] = max(jobDifficulty[i], dp[i - 1]);

        stkIdx.reserve(n);
        int lastIdx;

        // Dynamic Programming to find the minimum difficulty (Optimized with a decreasing stack).
        for(int i = 1; i < d; ++i) {
            dp.swap(dpPrev);
            stkIdx.clear();

            for(int j = i; j < n; ++j) {
                dp[j] = jobDifficulty[j] + dpPrev[j - 1];

                while(!stkIdx.empty() && jobDifficulty[stkIdx.back()] <= jobDifficulty[j]) {
                    lastIdx = stkIdx.back();
                    stkIdx.pop_back();
                    dp[j] = min(dp[j], dp[lastIdx] + jobDifficulty[j] - jobDifficulty[lastIdx]);
                }

                if(!stkIdx.empty()) {
                    lastIdx = stkIdx.back();
                    dp[j] = min(dp[j], dp[lastIdx]);
                }

                stkIdx.emplace_back(j);
            }
        }

        return dp.back();
    }
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        return minDifficultyOptimized(jobDifficulty, d);
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n, d;
        cin >> n >> d;
        vector<int> jobDifficulty(n, 0);
        for(int &i: jobDifficulty)
            cin >> i;
        cout << ob.minDifficulty(jobDifficulty, d) << endl;
    }

    return 0;
}

/* Sample Input:
3
6 2
6 5 4 3 2 1
3 4
9 9 9
3 3
1 1 1

Sample Output:
7
-1
3

*/