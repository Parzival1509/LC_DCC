// LC DCC 2023/02/04
// 567. Permutation in String
// Medium

#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    bool checkInclusion(string s, string t) {
        unordered_map<char, int> mp;
        for(auto el: s) mp[el]++;

        int ct = mp.size(), i = 0, j = 0, k = s.size();
        while(j < t.size()) {
            if(mp.find(t[j]) != mp.end()) {
                mp[t[j]]--;
                if(mp[t[j]] == 0) ct--;
            }

            if(j-i+1 < k) j++;
            else {
                if(ct == 0) return true;

                if(mp.find(t[i]) != mp.end()) {
                    mp[t[i]]++;
                    if(mp[t[i]] == 1) ct++;
                }
                i++;
                j++;
            }
        }
        return false;
    }
};

int main() {
    Solution ob;
    int t;
    cin>>t;
    while(t--) {
        string s, t;
        cin>>s>>t;
        cout<<ob.checkInclusion(s, t)<<endl;
    }
    return 0;
}

/* Sample Input:
2
ab eidbaooo
ab eidboaoo

Sample Output:
true
false

*/