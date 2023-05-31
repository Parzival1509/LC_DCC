// LC DCC 2023/02/02
// 953. Verifying an Alien Dictionary
// Easy

#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    map<char, int> mp;
    bool compareWords(string a, string b) {
        int m = a.size(), n = b.size();
        for(int i=0; i<min(m, n); i++) {
            if(mp[a[i]] < mp[b[i]]) return true;
            else if(mp[a[i]] > mp[b[i]]) return false;
        }
        if(m <= n) return true;
        return false;
    }

    bool isAlienSorted(vector<string>& words, string order) {
        for(int i=0; i<26; i++)
            mp[order[i]] = i;

        int m = words.size();
        for(int i=0; i<m-1; i++)
            if(!compareWords(words[i], words[i+1])) return false;
        return true;
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
        string order;
        cin>>order;
        if(ob.isAlienSorted(words, order)) cout<<"true"<<endl;
        else cout<<"false"<<endl;
    }
    return 0;
}

/* Sample Input:
3
2
hello leetcode
hlabcdefgijkmnopqrstuvwxyz
3
word world row
worldabcefghijkmnpqstuvxyz
2
apple app
abcdefghijklmnopqrstuvwxyz

Sample Output:
true
false
false

*/