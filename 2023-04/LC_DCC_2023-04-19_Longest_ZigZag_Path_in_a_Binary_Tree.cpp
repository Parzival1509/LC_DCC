// LC DCC 2023/04/19
// 1372. Longest ZigZag Path in a Binary Tree
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
private:
    int maxZigZag = 0;

    // 0 = root, 1 = left, 2 = right
    int helper(TreeNode* root, int lr) {
        if(root == NULL) return 0;
        
        int left = helper(root->left, 1);
        int right = helper(root->right, 2);
        int maxPath = 0;
        
        if(lr == 1) maxPath = right + 1;
        else if(lr == 2) maxPath = left + 1;
        else maxPath = max(left, right);
        
        maxZigZag = max(maxPath, maxZigZag);
        return maxPath;
    }

public:
    int longestZigZag(TreeNode* root) {
        helper(root, 0);
        return maxZigZag;
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