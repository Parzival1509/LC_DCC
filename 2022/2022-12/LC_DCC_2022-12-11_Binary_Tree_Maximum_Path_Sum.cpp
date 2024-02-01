// LC DCC 2022/12/11
// 124. Binary Tree Maximum Path Sum
// Hard

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
int ret = INT_MIN;
    int maxPathSum(TreeNode* root) {
        MaxDownPath(root);
        return ret;
    }

    // starting from node downward only, the max-sum path
    int MaxDownPath(TreeNode* node) {
        if (node==NULL) return 0;
        
        int leftSum = MaxDownPath(node->left);
        int rightSum = MaxDownPath(node->right);
        
        int maxTurnSum = node->val;
        if (leftSum >= 0) maxTurnSum += leftSum;
        if (rightSum >= 0) maxTurnSum += rightSum;
        ret = max(ret, maxTurnSum);
        
        if (leftSum < 0 && rightSum < 0)
            return node->val;
        else
            return max(leftSum, rightSum) + node->val;
    }
};

/* Sample Input
2
1 2 3
[-10,9,20,null,null,15,7]

Sample Output
6
42

*/