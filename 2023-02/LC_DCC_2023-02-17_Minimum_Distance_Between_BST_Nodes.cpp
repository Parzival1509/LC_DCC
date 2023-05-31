// LC DCC 2023/02/17
// 783. Minimum Distance Between BST Nodes
// Easy

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
    int minDistance = INT_MAX;
    // Initially, it will be null.
    TreeNode* prevValue;
        
    void inorderTraversal(TreeNode* root) {
        if (root == NULL) return;
        
        inorderTraversal(root->left);

        // Find the difference with the previous value if it is there.
        if (prevValue != NULL)
            minDistance = min(minDistance, root->val - prevValue->val);
        prevValue = root;
        
        inorderTraversal(root->right);
    }
    
    int minDiffInBST(TreeNode* root) {
        inorderTraversal(root);
        return minDistance;
    }
};

int main() {
    Solution ob;
    int T = 1;
    cin>>T;
    while(T--) {
        
    }
    return 0;
}

/* Sample Input:
2
4 2 6 1 3
1 0 48 NULL NULL 12 49

Sample Output:
1
1

*/