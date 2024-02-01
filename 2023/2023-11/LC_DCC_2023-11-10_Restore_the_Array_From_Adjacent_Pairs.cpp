// LC DCC 2023/11/10
// 1743. Restore the Array From Adjacent Pairs
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> graph;
        for(auto& pair: adjacentPairs) {
            graph[pair[0]].push_back(pair[1]);
            graph[pair[1]].push_back(pair[0]);
        }

        vector<int> result;
        for(auto& entry: graph)
            if(entry.second.size() == 1) {
                result = {entry.first, entry.second[0]};
                break;
            }

        while(result.size() < adjacentPairs.size() + 1) {
            int last = result[result.size() - 1];
            int prev = result[result.size() - 2];

            vector<int>& candidates = graph[last];
            int nextElement = (candidates[0] != prev)? candidates[0]: candidates[1];
            result.push_back(nextElement);
        }

        return result;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> adjacentPairs(n - 1, vector<int> (2, 0));
        for(int i = 0; i < n - 1; i++)
            cin >> adjacentPairs[i][0] >> adjacentPairs[i][1];

        vector<int> ans = ob.restoreArray(adjacentPairs);
        for(int i: ans)
            cout << i << ' ';
        cout << endl;
    }

    return 0;
}

/* Sample Input:
3
2
1 -1
4
2 1
3 4
3 2
4
4 -2
1 4
-3 1

Sample Output:
-1 1 
4 3 2 1 
-3 1 4 -2 

*/