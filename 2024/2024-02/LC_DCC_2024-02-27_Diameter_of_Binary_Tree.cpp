// LC DCC 2024/02/27
// 543. Diameter of Binary Tree
// Easy

#include<bits/stdc++.h>
using namespace std;

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
    int diameter(TreeNode* curr, int& res) {
        if (!curr) return 0;
        
        int left = diameter(curr->left, res);
        int right = diameter(curr->right, res);
        res = max(res, left + right);
        
        return max(left, right) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        diameter(root, res);
        return res;
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        
    }

    return 0;
}

/* Sample Input

Sample Output

*/