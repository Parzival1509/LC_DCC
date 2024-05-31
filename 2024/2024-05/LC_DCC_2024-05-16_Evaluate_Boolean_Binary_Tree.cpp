// LC DCC 2024/05/16
// 2331. Evaluate Boolean Binary Tree
// Easy

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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
*/

class Solution {
public:
    bool helper(TreeNode* root) {
        if(root -> val == 0 || root -> val == 1)
            return root -> val == 1;
        if(root -> val == 2)
            return helper(root -> left) || helper(root -> right);
        if(root -> val == 3)
            return helper(root -> left) && helper(root -> right); 
        return false;
    }

    bool evaluateTree(TreeNode* root) {
        return helper(root);
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

Sample Output

*/