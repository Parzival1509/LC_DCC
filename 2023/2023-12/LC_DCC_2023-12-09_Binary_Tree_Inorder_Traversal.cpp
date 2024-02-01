// LC DCC 2023/12/09
// 94. Binary Tree Inorder Traversal
// Easy

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
    void solve(TreeNode* root, vector<int>& ans) {
        if(root) {
            solve(root->left, ans);
            ans.push_back(root->val);
            solve(root->right, ans);
        }
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        solve(root, ans);
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        
    }

    return 0;
}

/* Sample Input:


Sample Output:


*/