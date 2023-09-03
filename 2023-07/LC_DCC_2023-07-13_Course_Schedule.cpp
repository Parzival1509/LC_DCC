// LC DCC 2023/07/13
// 207. Course Schedule
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans, adj[numCourses], indegree(numCourses, 0);

        for(auto x: prerequisites) {
            adj[x[0]].push_back(x[1]);
            indegree[x[1]]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++)
            if(indegree[i] == 0)
                q.push(i);

        while(!q.empty()) {
            auto t = q.front();
            ans.push_back(t);
            q.pop();

            for(auto x: adj[t]) {
                indegree[x]--;
                if(indegree[x] == 0)
                    q.push(x);
            }
        }
        
        return ans.size() == numCourses;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while(T--) {
        int numCourses, p = 0;
        cin >> numCourses >> p;
        vector<vector<int>> prerequisites(p, vector<int> (2, 0));
        for(int i = 0; i < p; i++)
            cin >> prerequisites[i][0] >> prerequisites[i][1];

        if(ob.canFinish(numCourses, prerequisites)) cout<<"true ";
        else cout<<"false ";
        cout<<endl;
        
    }
    
    return 0;
}

/* Sample Input:
2

2 1
1 0

2 2
1 0
0 1

Sample Output:
true 
false 

*/