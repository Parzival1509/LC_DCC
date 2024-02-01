// LC DCC 2023/02/16
// 104. Maximum Depth of Binary Tree
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
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int left = 1 + maxDepth(root->left);
        int right = 1 + maxDepth(root->right);
        return max(left, right);
    }
};

int main() {
    Solution ob;
    int T = 1;
    cin>>T;
    while(T--) {
        int n, k;
        cin>>n>>k;
        vector<int> num(n);
        for(int i=0; i<n; i++)
            cin>>num[i];
        vector<int> ans = ob.addToArrayForm(num, k);
        for(auto i: ans)
            cout<<i<<' ';
        cout<<endl;
    }
    return 0;
}

/* Sample Input:
2
3 9 20 NULL NULL 15 7
1 NULL 2

Sample Output:
3
2

*/