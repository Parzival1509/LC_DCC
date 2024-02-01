// LC DCC 2024/01/10
// 2385. Amount of Time for Binary Tree to Be Infected
// Easy

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance = 0;

    int traverse(TreeNode* root, int start) {
        int depth = 0;
        if (root == NULL) return depth;

        int leftDepth = traverse(root->left, start);
        int rightDepth = traverse(root->right, start);

        if (root->val == start) {
            maxDistance = max(leftDepth, rightDepth);
            depth = -1;
        } else if (leftDepth >= 0 && rightDepth >= 0)
            depth = max(leftDepth, rightDepth) + 1;
        else {
            int distance = abs(leftDepth) + abs(rightDepth);
            maxDistance = max(maxDistance, distance);
            depth = min(leftDepth, rightDepth) - 1;
        }

        return depth;
    }

    int amountOfTime(TreeNode* root, int start) {
        traverse(root, start);
        return maxDistance;
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