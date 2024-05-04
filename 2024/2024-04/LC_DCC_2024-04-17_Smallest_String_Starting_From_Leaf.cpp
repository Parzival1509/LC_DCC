// LC DCC 2024/04/17
// 988. Smallest String Starting From Leaf
// Medium

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        val = value;
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
    void dfs(TreeNode* root, string path, string& ans) {
        if (!root) return;

        path += char('a' + root->val);

        if (!root->left && !root->right) {
            reverse(path.begin(), path.end());
            if (ans.empty() || path < ans)
                ans = path;
            reverse(path.begin(), path.end());
        }

        dfs(root->left, path, ans);
        dfs(root->right, path, ans);
    }

    string smallestFromLeaf(TreeNode* root) {
        string ans;
        dfs(root, "", ans);
        return ans;
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
        cout << ob.smallestFromLeaf(root) << endl;
    }

    return 0;
}

/* Sample Input
3
0 1 2 3 4 3 4
25 1 3 1 3 0 2
2 2 1 N 1 0 N 0

Sample Output
dba
adz
abc

*/