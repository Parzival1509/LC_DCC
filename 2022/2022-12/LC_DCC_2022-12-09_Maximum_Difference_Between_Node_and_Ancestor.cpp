// LC DCC 2022/12/09
// 1026. Maximum Difference Between Node and Ancestor
// Medium

#include<bits/stdc++.h>
using namespace std;

int start_up(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
int static r = start_up();

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

// Baijnath's Sol
class Solution {
public:
    int helper(TreeNode* root, int currmin, int currmax){
        if(root==NULL) return currmax-currmin;
        currmax=max(root->val, currmax);
        currmin=min(root->val, currmin);

        int l=helper(root->left, currmin, currmax);
        int r=helper(root->right, currmin, currmax);
        return max(l,r);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        if(root==NULL) return 0;
        return helper(root, root->val, root->val);
    }
};

/* Sample Input
2
[8,3,10,1,6,null,14,null,null,4,7,13]
[1,null,2,null,0,3]

Sample Output
7
3

*/