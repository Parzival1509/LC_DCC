// LC DCC 2023/06/03
// 1376. Time Needed to Inform All Employees
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    unordered_map<int,vector<int>> adj;
    int maxi = 0, ans = 0;
    
    void dfs(int mng, vector<int>& informTime) {
        maxi = max(maxi, ans);
        for(auto emp: adj[mng]) {
            ans += informTime[mng];
            dfs(emp, informTime);
            ans -= informTime[mng];
        }
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        for(int i = 0; i < n; i++) {
            int mng = manager[i];
            if(mng != -1)
                adj[mng].push_back(i);
        }
        dfs(headID, informTime);

        return maxi;
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        int n, headID;
        cin >> n >> headID;
        vector<int> manager(n, 0), informTime(n, 0);
        for(int &i: manager)
            cin >> i;
        for(int &i: informTime)
            cin >> i;
        cout << ob.numOfMinutes(n, headID, manager, informTime) << endl;
    }
    return 0;
}

/* Sample Input:
2

1 0
-1
0

6 2
2 2 -1 2 2 2
0 0 1 0 0 0

Sample Output:
0
1

*/