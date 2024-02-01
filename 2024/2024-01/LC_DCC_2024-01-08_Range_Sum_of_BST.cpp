// LC DCC 2024/01/08
// 938. Range Sum of BST
// Easy

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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == nullptr) return 0;

        return (root->val >= low && root->val <= high? root->val: 0) + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> nums(n, 0);
        for(int &i: nums)
            cin >> i;
        cout << ob.minimumAverageDifference(nums) << endl;
    }

    return 0;
}

/* Sample Input
2
10 5 3 7 15 null 18

Sample Output
0
3

*/