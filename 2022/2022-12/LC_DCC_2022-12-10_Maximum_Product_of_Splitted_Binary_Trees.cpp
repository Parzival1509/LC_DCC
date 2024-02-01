// LC DCC 2022/12/10
// 1339. Maximum Product of Splitted Binary Tree
// Medium

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
    int totalTreeSum(TreeNode* root) {
        if(root == NULL) return 0;
        return root->val + totalTreeSum(root->left) + totalTreeSum(root->right);
    }

    int maxTreePro(TreeNode* root, int totalsum, int &maxPro, int &max_diff) {
        if(root == NULL) return 0;
        int leftsum = maxTreePro(root->left, totalsum, maxPro, max_diff);
        int rightsum = maxTreePro(root->right, totalsum, maxPro, max_diff);
        if(abs(leftsum - totalsum/2) < max_diff) {
            max_diff = abs(leftsum - totalsum/2);
            maxPro = leftsum;
        }
        if(abs(rightsum - totalsum/2) < max_diff) {
            max_diff = abs(rightsum - totalsum/2);
            maxPro = rightsum;
        }
        return leftsum + rightsum + root->val;
    }

    int maxProduct(TreeNode* root) {
        int mod_val = 1000000007;
        int totalsum = totalTreeSum(root);
        int maxPro = INT_MAX, max_diff = INT_MAX;
        maxTreePro(root, totalsum, maxPro, max_diff);
        long long unsigned int res = (long long unsigned int)(totalsum - maxPro) * \
        (long long unsigned int)(maxPro);
        return res % mod_val;
    }
};

/* Sample Input
2
[1,2,3,4,5,6]
[1,null,2,3,4,null,null,5,6]

Sample Output
110
90

*/