// LC DCC 2023/08/21
// 459. Repeated Substring Pattern
// Easy

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
     bool repeatedSubstringPattern(string s) {
        // // Approach 1: DP
        // int i = 1, j = 0, n = s.size();
        // vector<int> dp(n + 1, 0);

        // while(i < n) {
        //     if(s[i] == s[j])
        //         dp[++i] = ++j;
        //     else if(j == 0) i++;
        //     else j = dp[j];
        // }

        // return dp[n] && (dp[n] % (n - dp[n]) == 0);

        // Approach 2: String Manipulation
        string doubled = s + s;
        string sub = doubled.substr(1, doubled.size() - 2);
        return sub.find(s) != string::npos;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        string s;
        cin >> s;
        if(ob.repeatedSubstringPattern(s)) cout<<"true ";
        else cout<<"false ";
        cout<<endl;
    }

    return 0;
}

/* Sample Input:
3
abab
aba
abcabcabcabc

Sample Output:
true 
false 
true 

*/