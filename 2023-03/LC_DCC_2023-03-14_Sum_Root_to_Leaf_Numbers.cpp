// LC DCC 2023/03/14
// 129. Sum Root to Leaf Numbers
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
    void findSum(vector<int> &rsum, TreeNode* root, int csum = 0) {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) {
            rsum.push_back(csum*10 + root->val);
            return;
        }
        if(root->left != NULL)
            findSum(rsum, root->left, csum*10+root->val);
        if(root->right != NULL)
            findSum(rsum, root->right, csum*10+root->val);
    }

    int sumNumbers(TreeNode* root) {
        vector<int> rsum;
        int ans = 0;
        findSum(rsum, root);
        for(int i = 0; i < rsum.size(); i++)
            ans += rsum[i];
        return ans;
    }
};

int main() {
    Solution ob;
    int T = 1;
    cin>>T;
    while(T--) {
        
    }
    return 0;
}

/* Sample Input:
2
1 2 3
4 9 0 5 1

Sample Output:
25
1026

*/