// LC DCC 2024/02/29
// 1609. Even Odd Tree
// Medium

#include<bits/stdc++.h>
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
    bool isEvenOddTree(TreeNode* root) {
        if (!root) return true;

        queue<TreeNode*> queue;
        int level = 0;

        queue.push(root);
        while (!queue.empty()) {
            int size = queue.size();
            int prev_val = (level % 2 == 0) ? INT_MIN : INT_MAX;

            for (int i = 0; i < size; ++i) {
                TreeNode* node = queue.front();
                queue.pop();

                if ((level % 2 == 0 && (node->val % 2 == 0 || node->val <= prev_val)) || (level % 2 == 1 && (node->val % 2 == 1 || node->val >= prev_val)))
                    return false;

                prev_val = node->val;
                if (node->left)
                    queue.push(node->left);
                if (node->right)
                    queue.push(node->right);
            }
            level++;
        }

        return true;
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        
    }

    return 0;
}

/* Sample Input

Sample Output

*/