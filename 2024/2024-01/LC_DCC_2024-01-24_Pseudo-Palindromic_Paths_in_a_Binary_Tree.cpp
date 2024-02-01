// LC DCC 2024/01/24
// 1457. Pseudo-Palindromic Paths in a Binary Tree
// Medium

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
    int countPseudoPalindromicPaths(TreeNode* node, int path) {
        if (!node) return 0;

        path ^= (1 << node->val);
        if (!node->left && !node->right)
            return (path & (path - 1)) == 0? 1: 0;

        return countPseudoPalindromicPaths(node->left, path) + countPseudoPalindromicPaths(node->right, path);
    }

    int pseudoPalindromicPaths(TreeNode* root) {
        return countPseudoPalindromicPaths(root, 0);
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