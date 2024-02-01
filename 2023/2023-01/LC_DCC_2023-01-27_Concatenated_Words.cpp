// LC DCC 2023/01/27
// 472. Concatenated Words
// Hard

#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_map<string,int> words_map;
        for(string word: words)
            words_map[word]++;
        vector<string> res;
        for(string word: words) {
            int n = word.size();
            vector<int> dp(n+1, 0);
            dp[0] = 1;
            for(int i=0; i<n; i++) {
                if(!dp[i]) continue;
                for(int j=i+1; j<=n; j++)
                    if(j-i<n && words_map[(word.substr(i, j-i))]>0)
                        dp[j] = 1;
                if(dp[n]) {                  
                    res.push_back(word);
                    break;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution ob;
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<string> words(n);
        for(int i=0; i<n; i++)
            cin>>words[i];

        for(auto word: ob.findAllConcatenatedWordsInADict(words))
            cout<<word<<endl;
        cout<<endl;
    }
    return 0;
}

/* Sample Input:
2
3
cat dog catdog
8
cat cats catsdogcats dog dogcatsdog hippopotamuses rat ratcatdogcat

Sample Output:
catdog

catsdogcats
dogcatsdog
ratcatdogcat


*/