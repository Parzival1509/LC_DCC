// LC DCC 2023/10/18
// 2050. Parallel Courses III
// Hard

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int calculateTime(int course, vector<int>& dp, vector<vector<int>>& graph, vector<int>& time) {
        if(dp[course] != -1)
            return dp[course];

        if(graph[course].empty()) {
            dp[course] = time[course];
            return dp[course];
        }

        int maxPrerequisiteTime = 0;
        for(int prereq: graph[course])
            maxPrerequisiteTime = max(maxPrerequisiteTime, calculateTime(prereq, dp, graph, time));
        dp[course] = maxPrerequisiteTime + time[course];

        return dp[course];
    }

    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        // // Approach 1: DFS + Memoization
        // vector<vector<int>> graph(n);
        // for(auto& relation: relations) {
        //     int prev = relation[0] - 1;
        //     int next = relation[1] - 1;
        //     graph[prev].push_back(next);
        // }

        // vector<int> dp(n, -1);

        // int overallMinTime = 0;
        // for(int course = 0; course < n; course++)
        //     overallMinTime = max(overallMinTime, calculateTime(course, dp, graph, time));

        // return overallMinTime;

        // Approach 2: BFS in Directed Acyclic Graph
        unordered_map<int, vector<int>> graph;
        vector<int> in_degree(n + 1, 0);
        for(auto& relation: relations) {
            graph[relation[0]].push_back(relation[1]);
            in_degree[relation[1]]++;
        }

        vector<int> dist = time;
        dist.insert(dist.begin(), 0);
        queue<int> q;
        for(int i = 1; i <= n; i++)
            if(in_degree[i] == 0)
                q.push(i);

        while(!q.empty()) {
            int course = q.front(); q.pop();
            for(int next_course: graph[course]) {
                dist[next_course] = max(dist[next_course], dist[course] + time[next_course - 1]);
                in_degree[next_course]--;
                if(in_degree[next_course] == 0)
                    q.push(next_course);
            }
        }

        return *max_element(dist.begin(), dist.end());
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n, r;
        cin >> n >> r;
        vector<vector<int>> relations(r, {0, 0});
        for(auto &i: relations)
            cin >> i[0] >> i[1];
        vector<int> time(n, 0);
        for(int &i: time)
            cin >> i;
        cout << ob.minimumTime(n, relations, time) << endl;
    }

    return 0;
}

/* Sample Input:
2

3 2
1 3
2 3
3 2 5

5 5
1 5
2 5
3 5
3 4
4 5
1 2 3 4 5


Sample Output:
8
12

*/