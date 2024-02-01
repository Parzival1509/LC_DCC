// LC DCC 2023/03/13
// 101. Symmetric Tree
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
    bool isEqual(TreeNode*r1,TreeNode*r2) {
        // if we have both root to nullptr then we will return true
        // else we will be returning false
        if(!r1 || !r2) return r1 == r2;
        
        // if not null then we will check for the r1 and r2 values
        // we will check for the r1 left and r2 right because they will be on opposite sides
        if(r1->val == r2->val)
            return isEqual(r1->left, r2->right) && isEqual(r1->right, r2->left);
        
        // if r1 val not equal to r2 val then return false
        return false;
    }
    
    bool isSymmetric(TreeNode* root) {
        return isEqual(root->left, root->right);
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
1 2 2 3 4 4 3
1 2 2 N 3 N 3

Sample Output:

*/