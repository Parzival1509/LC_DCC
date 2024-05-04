// LC DCC 2024/04/14
// 404. Sum of Left Leaves
// Easy

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int value) {
        val = value;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input string after spliting by space
    vector<string> ip;
    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    Node* root = new Node(stoi(ip[0]));
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        Node* currNode = queue.front();
        queue.pop();
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {
            currNode->left = new Node(stoi(currVal));
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {
            currNode->right = new Node(stoi(currVal));
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
    int dfs(Node* node, bool isLeft) {
        if (!node)
            return 0;
        if (!node->left && !node->right)
            return isLeft ? node->val : 0;
        
        int leftSum = dfs(node->left, true);
        int rightSum = dfs(node->right, false);

        return leftSum + rightSum;
    }

    int sumOfLeftLeaves(Node* root) {
        if (!root)
            return 0;

        // // Approach 1: BFS
        // queue<pair<Node*, bool>> q;
        // q.push({root, false});
        // int totalSum = 0;

        // while (!q.empty()) {
        //     auto [node, isLeft] = q.front();
        //     q.pop();

        //     if (isLeft && !node->left && !node->right)
        //         totalSum += node->val;

        //     if (node->left)
        //         q.push({node->left, true});
        //     if (node->right)
        //         q.push({node->right, false});
        // }

        // return totalSum;

        // Approach 2: DFS
        return dfs(root, false);
    }
};

int main() {
    int T;
    scanf("%d ", &T);
    while (T--) {
        string treeString;
        getline(cin, treeString);
        Node* root = buildTree(treeString);
        Solution ob;
        cout << ob.sumOfLeftLeaves(root) << endl;
    }

    return 0;
}

/* Sample Input
2
1
3 9 20 N N 15 17

Sample Output
0
24

*/