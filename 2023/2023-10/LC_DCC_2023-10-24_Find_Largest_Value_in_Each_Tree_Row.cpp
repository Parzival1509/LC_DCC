// LC DCC 2023/10/24
// 515. Find Largest Value in Each Tree Row
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
*/

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(root == NULL) return {};
        
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int n = q.size(), mx = INT_MIN;

            for(int i = 0; i < n; i++) {
                TreeNode* tmp = q.front();
                q.pop();
                
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);

                mx = max(mx, tmp->val);
            }

            ans.push_back(mx);
        }

        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n;
        cin >> n;
        if(ob.isPowerOfFour(n)) cout << "true ";
        else cout << "false ";
        cout << endl;
    }

    return 0;
}

/* Sample Input:
3
1 3 2 5 3 N 9
1 2 3


Sample Output:
1 3 9
1 3


*/