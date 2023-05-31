// LC DCC 2023/01/10
// 100. Same Tree
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

//Baijnath's Sol
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL) return true;
        if(p==NULL || q==NULL) return false;
        return ((p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right)); 
    }
};

int main() {
    int T;
    cin>>T;
    Solution ob;
    while(T--) {
        
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