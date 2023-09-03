// LC DCC 2023/06/04
// 547. Number of Provinces
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int i) {
        visited[i] = true;
        for(int j = 0; j < isConnected.size(); j++)
            if(isConnected[i][j] == 1 && !visited[j])
                dfs(isConnected, visited, j);
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited(isConnected.size(), false);
        int count = 0;
        for(int i = 0;i < isConnected.size(); i++)
            if(!visited[i]) {
                count++;
                dfs(isConnected, visited, i);
            }

        return count;
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> isConnected(n, vector<int> (n, 0));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> isConnected[i][j];
        cout << ob.findCircleNum(isConnected) << endl;
    }
    return 0;
}

/* Sample Input:
2

3
1 1 0
1 1 0
0 0 1

3
1 0 0
0 1 0
0 0 1

Sample Output:
2
3

*/