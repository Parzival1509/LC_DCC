// LC DCC 2023/06/14
// 530. Minimum Absolute Difference in BST
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
    // int ans = INT_MAX, num = -1;

    // int getMinimumDifference(TreeNode* root) {
    //     if (root->left != NULL)
    //         getMinimumDifference(root->left);

    //     if (num >= 0)
    //         ans = min(ans, root->val - num);

    //     num = root->val;
    //     if (root->right != NULL)
    //         getMinimumDifference(root->right);

    //     return ans;
    // }

    int minDistance = INT_MAX;
    TreeNode* prevValue;
        
    void inorderTraversal(TreeNode* root) {
        if (root == NULL) return;
        
        inorderTraversal(root->left);

        if (prevValue != NULL)
            minDistance = min(minDistance, root->val - prevValue->val);
        prevValue = root;
        
        inorderTraversal(root->right);
    }
    
    int getMinimumDifference(TreeNode* root) {
        inorderTraversal(root);
        return minDistance;
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        int n;
        cin >> n;
        
    }
    return 0;
}

/* Sample Input:

Sample Output:

*/