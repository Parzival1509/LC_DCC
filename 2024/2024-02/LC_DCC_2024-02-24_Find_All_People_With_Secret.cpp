// LC DCC 2024/02/24
// 2092. Find All People With Secret
// Hard

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<bool> can(n);
        can[0] = can[firstPerson] = true;
        
        map<int, vector<pair<int, int>>> mp;
        for (auto& meeting : meetings) 
            mp[meeting[2]].emplace_back(meeting[0], meeting[1]); 

        for (auto& i : mp) {
            unordered_map<int, vector<int>> graph;
            unordered_set<int> st;

            int k = i.first;
            auto v = i.second;
            for (auto& j : v) {
                int x = j.first;
                int y = j.second;
                graph[x].push_back(y); 
                graph[y].push_back(x); 
                if (can[x]) st.insert(x); 
                if (can[y]) st.insert(y); 
            }

            queue<int> q; 
            for (auto& x : st)
                q.push(x); 
            
            while (q.size()) {
                auto x = q.front(); q.pop(); 
                for (auto& y : graph[x]) 
                    if (!can[y]) {
                        can[y] = true; 
                        q.push(y); 
                    }
            }
        }
        
        vector<int> ans; 
        for (int i = 0; i < n; ++i) 
            if (can[i]) ans.push_back(i); 

        return ans;
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        int n, m, firstPerson;
        cin >> n >> m >> firstPerson;
        vector<vector<int>> meetings(m, {0, 0, 0});
        for(int i = 0; i < m; i++)
            cin >> meetings[i][0] >> meetings[i][1] >> meetings[i][2];
        vector<int> ans = ob.findAllPeople(n, meetings, firstPerson);
        for(int i: ans)
            cout << i << ' ';
        cout << endl;
    }

    return 0;
}

/* Sample Input
3

6 3 1
1 2 5
2 3 8
1 5 10

4 3 3
3 1 3
1 2 2
0 3 3

5 3 1
3 4 2
1 2 1
2 3 1
    
Sample Output
0 1 2 3 5 
0 1 3 
0 1 2 3 4 

*/