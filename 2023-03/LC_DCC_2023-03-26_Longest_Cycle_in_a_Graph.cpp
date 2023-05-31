// LC DCC 2023/03/26
// 2360. Longest Cycle in a Graph
// Hard

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int ans = -1, time = 1;
        vector<int> timeVisited(edges.size());

        for (int i = 0; i < edges.size(); ++i) {
            if (timeVisited[i]) continue;

            int startTime = time, u = i;
            while (u != -1 && !timeVisited[u]) {
                timeVisited[u] = time++;
                u = edges[u];
            }
        
            if (u != -1 && timeVisited[u] >= startTime)
                ans = max(ans, time - timeVisited[u]);
        }

        return ans;
    }
};

int main() {
    Solution ob;
    int T = 1;
    cin>>T;
    while(T--) {
        int n;
        cin>>n;
        vector<int> edges(n);
        for(int i=0; i<n; i++)
            cin>>edges[i];
        cout<<ob.longestCycle(edges)<<endl;
    }
    return 0;
}

/* Sample Input:
2
5
3 3 4 2 3
4
2 -1 3 1

Sample Output:
3
-1

*/