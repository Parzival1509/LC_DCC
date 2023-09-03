// LC DCC 2023/07/16
// 1125. Smallest Sufficient Team
// Hard

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n = req_skills.size();
        map<string, int> m;
        for(int i = 0; i < n; i++)
            m[req_skills[i]] = i;
        
        vector<vector<int>> v;
        for(int i = 0; i < people.size(); i++) {
            vector<int> t;
            for(int j = 0; j < people[i].size(); j++)
                t.push_back(m[people[i][j]]);
            v.push_back(t);
        }
        
        unordered_map<int, vector<int>> dp;
        dp.reserve(1 << n);
        dp[0] = {};
        
        for(int i = 0; i < v.size(); i++) {
            int cur_skill = 0;
            for(int j = 0; j < v[i].size(); j++)
                cur_skill = (cur_skill)|(1<<v[i][j]);

            for(auto it = dp.begin(); it != dp.end(); it++) {
                int comb = cur_skill | it->first;
                if(dp.find(comb) == dp.end() || dp[comb].size() > 1 + dp[it->first].size()) {
                    dp[comb] = it->second;
                    dp[comb].push_back(i);
                }
            }
        } 
        
        return dp[(1 << n) - 1];
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while(T--) {
        int s, p;
        cin >> s >> p;
        vector<string> req_skills(s, "");
        for(string &i: req_skills)
            cin >> i;

        vector<vector<string>> people;
        for(int i = 0; i < p; i++) {
            int n;
            cin >> n;
            vector<string> tmp(n, "");
            for(string &i: tmp)
                cin >> i;
            people.push_back(tmp);
        }

        vector<int> ans = ob.smallestSufficientTeam(req_skills, people);

        for(int i: ans)
            cout << i << ' ';
        cout << endl;
    }
    
    return 0;
}

/* Sample Input:
2

3 3
java nodejs reactjs
1 java
1 nodejs
2 nodejs reactjs

6 6
algorithms math java reactjs csharp aws
3 algorithms math java
3 algorithms math reactjs
3 java csharp aws
2 reactjs csharp
2 csharp math
2 aws java


Sample Output:
0 2
1 2

*/