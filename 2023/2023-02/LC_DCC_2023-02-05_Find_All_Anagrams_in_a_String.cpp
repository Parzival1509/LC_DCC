// LC DCC 2023/02/05
// 438. Find All Anagrams in a String
// Medium

#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size() > s.size()) return {};

        unordered_map<char, int> pat, sthsh;
        vector<int> ans;

        for(int i=0; i<p.size(); i++)
            pat[p[i]]++;
    
        for(int i=0; i<s.size(); i++) {
            if(i>=p.size())
                sthsh[s[i-p.size()]]--;
            sthsh[s[i]]++;
            int f=1;
            if(i+1 >= pat.size()) {
                for(auto el: pat) {
                    if(sthsh[el.first]!=el.second) {
                        f=0;
                        break;
                    }
                }
                if(f)
                    ans.push_back(i+1-p.size());
            }
        }
        return ans;
    }
};

int main() {
    Solution ob;
    int t;
    cin>>t;
    while(t--) {
        string s, p;
        cin>>s>>p;
        for(auto ana: ob.findAnagrams(s, p))
            cout<<ana<<' ';
        cout<<endl;
    }
    return 0;
}

/* Sample Input:
2
cbaebabacd abc
abab ab

Sample Output:
0 6 
0 1 2 

*/