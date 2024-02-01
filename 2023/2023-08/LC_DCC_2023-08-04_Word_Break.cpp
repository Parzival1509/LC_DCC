// LC DCC 2023/08/04
// 139. Word Break
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for(int i = 1; i <= n; i++)
            for(int j = 0; j < i; j++)
                if((dp[j]) && (find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end())) {
                    dp[i] = true;
                    break;
                }
        
        return dp[n];
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while(T--) {
        int n;
        string s;
        cin >> s >> n;
        vector<string> wordDict(n, "");
        for(auto &i: wordDict)
            cin >> i;
        
        if(ob.wordBreak(s, wordDict)) cout<<"true ";
        else cout<<"false ";
        cout<<endl;
    }
    
    return 0;
}

/* Sample Input:
3
leetcode 2
leet code
applepenapple 2
apple pen
catsandog 5
cats dog sand and cat

Sample Output:
true 
true 
false 

*/