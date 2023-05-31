// LC DCC 2022/12/03
// 451. Sort Characters By Frequency
// Medium

#include<bits/stdc++.h>
using namespace std;

int start_up(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
int static r = start_up();

// Baijnath's Sol
class Solution {
public:
    static bool cmp(pair <int, char> a, pair <int, char> b){
      return a.first < b.first;
    }
    
    string frequencySort(string s) {
        vector<pair <int, char>> v;
        unordered_map<char, int> m;
        for(int i=0; i<s.size(); i++)
            m[s[i]]++;
        unordered_map<char, int> ::iterator i=m.begin();
        while(i != m.end()){
            v.push_back({i->second, i->first});
            i++;
        }
        sort(v.rbegin(), v.rend(), cmp);
        string ans = "";
        for(int i=0; i<v.size(); i++){
            int t=v[i].first;
            while(t--) ans += v[i].second;
        }
        return ans;
    }
};

// // From the lowest time taken
// class Solution {
// public:
//     string frequencySort(string s) {
//         vector<string> v(127);
//         for(auto i:s)
//             v[i]+=i;
//         sort(v.begin(), v.end(), [](const string& s1, const string& s2){
//             return  s1.size()>s2.size();});
//         string res;
//         for(auto i:v) res+=i;
//         return res;
//     }
// };

int main(){
    Solution ob;
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        cout<<ob.frequencySort(s)<<endl;
    }
    return 0;
}

/* Sample Input
3
tree
cccaaa
Aabb

Sample Output
eert
aaaccc
bbaA

*/