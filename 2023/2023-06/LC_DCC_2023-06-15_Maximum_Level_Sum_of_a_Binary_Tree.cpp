// LC DCC 2023/06/15
// 1161. Maximum Level Sum of a Binary Tree
// Medium

#include<bits/stdc++.h>
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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int maxSum = INT_MIN, level = 1, ans = 1;
        while(!q.empty()) {
            int sz = q.size();
            int curSum = 0;
            for(int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                q.pop();
                curSum += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(curSum>maxSum) {
                maxSum = curSum;
                ans = level;
            }
            level++;
        }
        return ans;
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        
    }
    return 0;
}

/* Sample Input:

Sample Output:

*/