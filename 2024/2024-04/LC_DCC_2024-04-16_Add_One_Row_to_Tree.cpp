// LC DCC 2024/04/16
// 623. Add One Row to Tree
// Medium

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
TreeNode* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input string after spliting by space
    vector<string> ip;
    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    TreeNode* root = new TreeNode(stoi(ip[0]));
    queue<TreeNode*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        TreeNode* currNode = queue.front();
        queue.pop();
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {
            currNode->left = new TreeNode(stoi(currVal));
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {
            currNode->right = new TreeNode(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
*/

class Solution {
public:
    TreeNode* add(TreeNode* root, int val, int depth, int curr) {
        if (!root)
            return NULL;

        if (curr == depth - 1) {
            TreeNode* lTemp = root->left;
            TreeNode* rTemp = root->right;

            root->left = new TreeNode(val);
            root->right = new TreeNode(val);
            root->left->left = lTemp;
            root->right->right = rTemp;

            return root;
        }

        root->left = add(root->left, val, depth, curr + 1);
        root->right = add(root->right, val, depth, curr + 1);

        return root;
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        return add(root, val, depth, 1);
    }
};

int main() {
    int T;
    scanf("%d ", &T);
    while (T--) {
        string treeString;
        getline(cin, treeString);
        TreeNode* root = buildTree(treeString);
        Solution ob;
        int val, depth;
        cin >> val >> depth;
        TreeNode* ans = ob.addOneRow(root, val, depth);
        
    }

    return 0;
}

/* Sample Input
2
4 2 6 3 1 5
1 2
4 2 N 3 1
1 3

Sample Output
0
24

*/