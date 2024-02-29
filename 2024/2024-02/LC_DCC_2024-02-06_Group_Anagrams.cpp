// LC DCC 2024/02/06
// 49. Group Anagrams
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> group_ind;
        vector<vector<string>> groups;
        int k = 0;

        for(int i = 0; i < strs.size(); i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            if(group_ind.find(temp) != group_ind.end())
                groups[group_ind[temp]].push_back(strs[i]);
            else {
                group_ind[temp] = k;
                groups.push_back({strs[i]});
                k++; 
            }
        }

        return groups;
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<string> strs(n, "");
        for(auto &i: strs)
            cin >> i;
        vector<vector<string>> ans = ob.groupAnagrams(strs);
        for(auto r: ans) {
            for(auto i: r)
                cout << i << ' ';
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}

/* Sample Input
2
6
eat tea tan ate nat bat
1
a

Sample Output
eat tea ate 
tan nat 
bat 

a 


*/