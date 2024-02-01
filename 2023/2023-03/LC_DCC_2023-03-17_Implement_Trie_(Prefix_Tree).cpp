// LC DCC 2023/03/17
// 208. Implement Trie (Prefix Tree)
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Trie {
public:
    unordered_map<string, int> mpp, mp;
        Trie() {}
        
        void insert(string word) {
            mpp[word]++;
            string s;
            for(auto it: word) {
                s.push_back(it);
                if(mp[s] == 0) mp[s]++;
            }
        }
        
        bool search(string word) {
            if(mpp[word]) return true;
            return false;
        }
        
        bool startsWith(string prefix) {
            if(mp[prefix]) return true;
            return false;
        }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */


int main() {
    Solution ob;
    int T = 1;
    cin>>T;
    while(T--) {
        
    }
    return 0;
}

/* Sample Input:
2
1 2 3
4 9 0 5 1

Sample Output:
25
1026

*/