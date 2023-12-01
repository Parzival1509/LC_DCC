// LC DCC 2023/11/01
// 501. Find Mode in Binary Search Tree
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
    // // Approach 1: S.C. = O(N)
    // vector<int> findMode(TreeNode* root) {
    //     vector<int> inorderr;
    //     inorder(root, inorderr);
    //     unordered_map<int, int> freq;
    //     int maxx = 0;
        
    //     for(int val: inorderr) {
    //         freq[val]++;
    //         maxx = max(maxx, freq[val]);
    //     }
        
    //     vector<int> result;
    //     for(auto& pair: freq)
    //         if(pair.second == maxx)
    //             result.push_back(pair.first);
        
    //     return result;
    // }

    // void inorder(TreeNode* root, vector<int>& result) {
    //     if(!root) return;

    //     result.push_back(root->val);
    //     inorder(root->left, result);
    //     inorder(root->right, result);
    // }

    // Approach 2: S.C. = O(1)
    int val = INT_MIN, freq = 0, maxFreq = 0;
    vector<int> ans;

    void inOrder(TreeNode* Node) {
        if(Node == NULL) return;

        inOrder(Node->left);
        if(val == Node->val)
            freq++;
        else {
            val = Node->val;
            freq = 1;
        }

        if(freq > maxFreq) {
            maxFreq=freq;
            ans={Node->val};
        } 
        else if(freq == maxFreq) 
            ans.push_back(Node->val);
        
        inOrder(Node->right);
    }

    vector<int> findMode(TreeNode* root) {
        inOrder(root);
        return ans;
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
4
1 N 2 2
1
0

Sample Output:
2
0

*/