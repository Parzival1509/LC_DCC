// LC DCC 2024/06/25
// 1038. Binary Search Tree to Greater Sum Tree
// Medium

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

class Solution {
public:
    int sum = 0;

    void traverse(TreeNode* root) {
        if (root) {
            traverse(root->right);
            sum += root->val;
            root->val = sum;
            traverse(root->left);
        }
    }

    TreeNode* bstToGst(TreeNode* root) {
        traverse(root);
        return root;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while (T--) {
        
    }

    return 0;
}

/* Sample Input
3
3 1
0 1 0
3 2
1 1 0
8 3
0 0 0 1 0 1 1 0

Sample Output
2
-1
3

*/