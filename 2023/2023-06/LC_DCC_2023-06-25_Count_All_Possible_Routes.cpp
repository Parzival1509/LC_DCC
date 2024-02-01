// LC DCC 2023/06/25
// 1575. Count All Possible Routes
// Hard

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    const int MOD = 1000000007;

    // // Approach 1: Memoization
    // int helper(vector<int>& locations, int city, int finish, int remainFuel, vector<vector<int>>& memo) {
    //     if(remainFuel < 0) return 0;
        
    //     if(memo[city][remainFuel] != -1)
    //         return memo[city][remainFuel];
        
    //     int total = (city == finish)? 1: 0;
    //     for(int nextCity = 0; nextCity < locations.size(); nextCity++)
    //         if(nextCity != city && remainFuel >= abs(locations[nextCity] - locations[city]))
    //             total = (total + helper(locations, nextCity, finish, remainFuel - abs(locations[nextCity] - locations[city]), memo)) % MOD;
        
    //     return memo[city][remainFuel] = total;
    // }

    // int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
    //     int n = locations.size();
    //     vector<vector<int>> memo(n, vector<int> (fuel + 1, -1));
    //     return helper(locations, start, finish, fuel, memo);
    // }

    // // Approach 2: Tabulation
    // int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
    //     int n = locations.size();
    //     vector<vector<int>> dp(n, vector<int> (fuel + 1, 0));
    //     for(int f = 0; f <= fuel; f++)
    //         dp[finish][f] = 1;
        
    //     // for each fuel, we calculate all cross between cities
    //     for(int f = 0; f <= fuel; f++)
    //         for(int city = 0; city < n; city++)       
    //             for(int nextCity = 0; nextCity < n; nextCity++)
    //                 if(nextCity != city && f >= abs(locations[nextCity] - locations[city]))
    //                     dp[city][f] = (dp[city][f] + dp[nextCity][f - abs(locations[nextCity] - locations[city])]) % MOD;
        
    //     return dp[start][fuel];
    // }

    // Approach 3:
    int countRoutes(vector<int>& A, int start, int finish, int fuel) {
        int mod = 1e9+7, s = A[start], f = A[finish];
        sort(begin(A), end(A));
        start = lower_bound(begin(A), end(A), s) - begin(A);
        finish = lower_bound(begin(A), end(A), f) - begin(A);
        
        vector<vector<int>> left(A.size(), vector<int>(fuel + 1));
        vector<vector<int>> right(A.size(), vector<int>(fuel + 1));

        for (int f = 1; f <= fuel; ++f) {
            for (int j = 0; j < A.size() - 1; ++j) {
                int d = A[j + 1] - A[j];
                if (f > d)
                    left[j][f] = (right[j + 1][f - d] + 2 * left[j + 1][f - d] % mod) % mod;
                else if (f == d) left[j][f] = j + 1 == start;
            }

            for (int j = 1; j < A.size(); ++j) {
                int d = A[j] - A[j - 1];
                if (f > d)
                    right[j][f] = (left[j - 1][f - d] + 2 * right[j - 1][f - d] % mod) % mod;
                else if (f == d) right[j][f] = j - 1 == start;
            }
        }

        int ans = start == finish;
        for (int f = 1; f <= fuel; ++f)
            ans = ((ans + left[finish][f]) % mod + right[finish][f]) % mod;
        
        return ans;
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        int n, start, finish, fuel;
        cin >> n >> start >> finish >> fuel;
        vector<int> locations(n, 0);
        for(int &i: locations)
            cin >> i;
        cout << ob.countRoutes(locations, start, finish, fuel) << endl;
    }
    return 0;
}

/* Sample Input:
3
5 1 3 5
2 3 6 8 4
3 1 0 6
4 3 1
3 0 2 3
5 2 1

Sample Output:
4
5
0

*/