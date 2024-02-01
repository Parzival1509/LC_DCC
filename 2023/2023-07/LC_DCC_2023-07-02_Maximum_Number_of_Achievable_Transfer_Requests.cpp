// LC DCC 2023/07/02
// 1601. Maximum Number of Achievable Transfer Requests
// Hard

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    void helper(int &ans, int start, vector<vector<int>>& requests, vector<int>& indegree, int n, int count) {
        if (start == requests.size()) {
            for (int i = 0; i < n; i++)
                if (indegree[i] != 0) return;
                
            ans = max(ans, count);
            return;
        }

        // Take 
        indegree[requests[start][0]]--;
        indegree[requests[start][1]]++;
        helper(ans, start + 1, requests, indegree, n, count + 1);

        // Not-take
        indegree[requests[start][0]]++;
        indegree[requests[start][1]]--;
        helper(ans, start + 1, requests, indegree, n, count);
    }
    
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int ans = 0;
        vector<int> indegree(n, 0);
        helper(ans, 0, requests, indegree, n, 0);
        return ans;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while(T--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> requests(k, vector<int> (2, 0));
        for(int i = 0; i < k; i++)
            cin >> requests[i][0] >> requests[i][1];
        cout << ob.maximumRequests(n, requests) << endl;
    }
    return 0;
}

/* Sample Input:
3

5 6
0 1
1 0
0 1
1 2
2 0
3 4

3 3
0 0
1 2
2 1

4 4
0 3
3 1
1 2
2 0

Sample Output:
5
3
4

*/