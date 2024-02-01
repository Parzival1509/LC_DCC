// LC DCC 2023/11/02
// 2265. Count Nodes Equal to Average of Subtree
// Medium

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
    int matchingSubtreeCount = 0;

    pair<int, int> calculateSubtreeValues(TreeNode* currentNode) {
        if(currentNode == nullptr)
            return {0, 0};

        auto leftSubtree = calculateSubtreeValues(currentNode->left);
        auto rightSubtree = calculateSubtreeValues(currentNode->right);

        int sumOfValues = leftSubtree.first + rightSubtree.first + currentNode->val;
        int numberOfNodes = leftSubtree.second + rightSubtree.second + 1;

        if(sumOfValues / numberOfNodes == currentNode->val)
            matchingSubtreeCount++; 

        return {sumOfValues, numberOfNodes};
    }

    int averageOfSubtree(TreeNode* root) {
        calculateSubtreeValues(root);
        return matchingSubtreeCount; 
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
4 8 5 0 1 N 6
1

Sample Output:
5
1

*/