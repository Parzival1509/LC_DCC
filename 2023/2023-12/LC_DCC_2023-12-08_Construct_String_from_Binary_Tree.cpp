// LC DCC 2023/12/08
// 606. Construct String from Binary Tree
// Easy

#include <bits/stdc++.h>
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
    void check(TreeNode* root, string &str) {
        if(root == NULL) return;

        str += to_string(root->val);
        if(root->left || root->right) {
            str += '(';
            check(root->left, str);
            str += ')';
        }
        if(root->right) {
            str += '(';
            check(root->right, str);
            str += ')';
        }
    }

    string tree2str(TreeNode* root) {
        string str = "";
        check(root, str);

        return str;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        
    }

    return 0;
}

/* Sample Input:
2
1 2 3 4
1 2 3 N 4

Sample Output:
1(2(4))(3)
1(2()(4))(3)

*/