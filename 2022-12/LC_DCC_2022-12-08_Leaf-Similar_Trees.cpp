// LC DCC 2022/12/08
// 872. Leaf-Similar Trees
// Easy

#include<bits/stdc++.h>
using namespace std;

int start_up(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
int static r = start_up();

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

 // Adi's Sol
class Solution {
public:
    void solve(vector<int> &temp, TreeNode* root) {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL)
            temp.push_back(root->val);
        solve(temp,root->left);
        solve(temp,root->right);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> temp1 , temp2;
        solve(temp1, root1);
        solve(temp2, root2);
        return temp1 == temp2;
    }
};

int main(){
    Solution ob;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> nums(n);
        for(int i=0; i<n; i++)
            cin>>nums[i];
        cout<<ob.minimumAverageDifference(nums)<<endl;
    }
    return 0;
}

/* Sample Input


Sample Output


*/