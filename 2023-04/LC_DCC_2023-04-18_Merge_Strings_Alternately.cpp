// LC DCC 2023/04/18
// 1768. Merge Strings Alternately
// Easy

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int i = 0, m = word1.size(), n = word2.size();
        while(i < m && i < n) {
            ans += word1[i];
            ans += word2[i];
            i++;
        }
        if(i < m) ans += word1.substr(i, m - i);
        if(i < n) ans += word2.substr(i, n - i);
        return ans;
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        string word1, word2;
        cin>>word1>>word2;
        cout<<ob.mergeAlternately(word1, word2)<<endl;
    }
    return 0;
}

/* Sample Input:
3
abc pqr
ab pqrs
abcd pq

Sample Output:
apbqcr
apbqrs
apbqcd

*/