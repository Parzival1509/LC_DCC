// LC DCC 2024/06/26
// 1382. Balance a Binary Search Tree
// Medium

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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> sortedElements;
        inOrderTraversal(root, sortedElements);

        return buildBalancedBST(sortedElements, 0, sortedElements.size() - 1);
    }

    void inOrderTraversal(TreeNode* node, vector<int>& sortedElements) {
        if (!node)
            return;

        inOrderTraversal(node->left, sortedElements);
        sortedElements.push_back(node->val);
        inOrderTraversal(node->right, sortedElements);
    }

    TreeNode* buildBalancedBST(vector<int>& elements, int start, int end) {
        if (start > end)
            return NULL;

        int mid = start + (end - start) / 2;
        TreeNode* node = new TreeNode(elements[mid]);
        node->left = buildBalancedBST(elements, start, mid - 1);
        node->right = buildBalancedBST(elements, mid + 1, end);

        return node;
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
3
3 1
0 1 0
3 2
1 1 0
8 3
0 0 0 1 0 1 1 0

Sample Output
2
-1
3

*/