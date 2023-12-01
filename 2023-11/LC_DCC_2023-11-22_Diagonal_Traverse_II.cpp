// LC DCC 2023/11/22
// 1424. Diagonal Traverse II
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        // // Approach 1: Using Adjacency List
        // int m = nums.size(), n = 0;
        // for(int i = 0; i < m; i++)
        //     n = max(n, (int)nums[i].size());
        
        // vector<int> ans;
        // vector<vector<int>> tmp(m + n);
        
        // // Convert mat into adjacency list and keep value in tmp
        // for(int i = 0; i < m; i++)
        //     for(int j = 0; j < nums[i].size(); j++)
        //         tmp[i + j].push_back(nums[i][j]);
        
        // for(int i = 0; i < m + n; i++)
        //     reverse(tmp[i].begin(), tmp[i].end());
        
        // for(int i = 0; i < m + n; i++)
        //     for(int j = 0; j < tmp[i].size(); j++)
        //         ans.push_back(tmp[i][j]);
        
        // // Approach 2: Using Hash
        // int m = nums.size(), maxSum = 0, n = 0, index = 0;
        // vector<vector<int>> hsh(100001);
        
        // for (int i = 0; i < m; i++) {
        //     n += nums[i].size();
        //     for (int j = 0; j < nums[i].size(); j++) {
        //         int sum = i + j;
        //         hsh[sum].push_back(nums[i][j]);
        //         maxSum = max(maxSum, sum);
        //     }
        // }
        
        // vector<int> ans(n);
        // for (int i = 0; i <= maxSum; i++) {
        //     vector<int>& cur = hsh[i];
        //     for (int j = cur.size() - 1; j >= 0; j--) {
        //         ans[index++] = cur[j];
        //     }
        // }
        
        // Approach 3: Using Queue
        int m = nums.size();
        queue<pair<int, int>> q;
        vector<int> ans;

        q.push({0, 0});
        while(!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            ans.push_back(nums[i][j]);
            if(!j && (i + 1 < m))
                q.push({i + 1, 0});
            if(j + 1 < nums[i].size())
                q.push({i, j + 1});
        }

        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int m;
        cin >> m;
        
        vector<vector<int>> nums(m);
        for(int i = 0; i < m; i++) {
            int n;
            cin >> n;
            vector<int> tmp(n, 0);
            for(int &i: tmp)
                cin >> i;
            nums.push_back(tmp);
        }

        vector<int> ans = ob.findDiagonalOrder(nums);
        for(int i: ans)
            cout << i << ' ';
        cout << endl;
    }

    return 0;
}

/* Sample Input:
2

3
3
1 2 3
3
4 5 6
3
7 8 9

5
5
1 2 3 4 5
2
6 7
1
8
3
9 10 11
5
12 13 14 15 16


Sample Output:
1 4 2 7 5 3 8 6 9 
1 6 2 8 7 3 9 4 12 10 5 13 11 14 15 16 

*/