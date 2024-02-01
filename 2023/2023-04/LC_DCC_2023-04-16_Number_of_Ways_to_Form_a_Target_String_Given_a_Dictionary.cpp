// LC DCC 2023/04/16
// 1639. Number of Ways to Form a Target String Given a Dictionary
// Hard

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int n = words[0].size(), m = target.size(), mod = 1000000007;
        vector<int> dp(m+1, 0);
        dp[0] = 1;
        
        vector<vector<int>> count(n, vector<int>(26, 0));
        for (const string& word: words)
            for (int i = 0; i < n; i++)
                count[i][word[i] - 'a']++;
        
        for (int i = 0; i < n; i++)
            for (int j = m-1; j >= 0; j--) {
                dp[j+1] += (int)((long)dp[j] * count[i][target[j] - 'a'] % mod);
                dp[j+1] %= mod;
            }
        
        return dp[m];
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        int n;
        string target;
        cin>>n>>target;
        vector<string> words(n);
        for(int i=0; i<n; i++)
            cin>>words[i];
        cout<<ob.numWays(words, target)<<endl;
    }
    return 0;
}

/* Sample Input:
2
3 aba
acca bbbb caca
2 bab
abba baab

Sample Output:
6
4

*/