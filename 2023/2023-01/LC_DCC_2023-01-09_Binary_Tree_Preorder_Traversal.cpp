// LC DCC 2023/01/09
// 144. Binary Tree Preorder Traversal
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

// Baijnath's Sol
class Solution {
public:
    void helper(TreeNode* root, vector<int>& ans) {
        if(root == NULL) return;
        ans.push_back(root->val);
        helper(root-> left, ans);
        helper(root->right, ans);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        helper(root, ans);
      return ans;
    }
};

int main() {
    int T;
    cin>>T;
    Solution ob;
    while(T--) {
        int n;
        cin>>n;
        vector<vector<int>> points(n, vector<int> (2, 0));
        for(int i=0; i<n; i++)
            cin>>points[i][0]>>points[i][1];
        cout<<ob.maxPoints(points)<<endl;
    }
    return 0;
}

/* Sample Input
2
1 null 2 3
null
1

Sample Output
1 2 3

1

*/