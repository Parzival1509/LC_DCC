// LC DCC 2023/03/15
// 958. Check Completeness of a Binary Tree
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
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    bool isCompleteBinaryTree(TreeNode* root, int index, int totalNodes) {
        if(root == nullptr) return true;
        if(index >= totalNodes) return false;
    
        return isCompleteBinaryTree(root->left, 2 * index + 1, totalNodes) && isCompleteBinaryTree(root->right, 2 * index + 2, totalNodes);
    }

    bool isCompleteTree(TreeNode* root) {
        int totalNodes = countNodes(root);
        return isCompleteBinaryTree(root, 0, totalNodes);
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
1 2 3
4 9 0 5 1

Sample Output:
25
1026

*/