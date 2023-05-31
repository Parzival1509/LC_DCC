// LC DCC 2023/02/18
// 226. Invert Binary Tree
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
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return NULL;
        
        TreeNode* tempRight = root->right;
            
        root->right = invertTree(root->left) ;
        root->left  = invertTree(tempRight);
        
        return root;
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
3
4 2 7 1 3 6 9
2 1 3


Sample Output:
4 7 2 9 6 3 1
2 3 1


*/