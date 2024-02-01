// LC DCC 2023/04/20
// 662. Maximum Width of Binary Tree
// Medium

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
    int helper(TreeNode* root, int depth, int index, vector<int>& list) {
        if(root == nullptr) return 0;
        
        if(depth == list.size()) list.push_back(index);
        int currWidth = index - list[depth] + 1;
        int leftWidth = helper(root->left, depth + 1, index * 2, list);
        int rightWidth = helper(root->right, depth + 1, index * 2 + 1, list);
        return max(currWidth, max(leftWidth, rightWidth));
    }

    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        vector<int> list;
        return helper(root, 0, 1, list);
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        
    }
    return 0;
}

/* Sample Input:


Sample Output:


*/