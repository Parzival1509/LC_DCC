// LC DCC 2023/07/10
// 111. Minimum Depth of Binary Tree
// Easy

#include<bits/stdc++.h>
using namespace std;

#define ll long long

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    Node* root = newNode(stoi(ip[0]));
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
            currNode->left = newNode(stoi(currVal));
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {
            currNode->right = newNode(stoi(currVal));
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
*/

class Solution {
public:
    int minDepth(Node* root) {
        if(root == NULL) return 0;
        
        // // Approach 1: DFS
        // int left = minDepth(root->left);
        // int right = minDepth(root->right);

        // if(root->left && root->right)
        //     return min(left + 1, right + 1);
        // return max(left + 1, right + 1);

        // Approach 2: BFS
        queue<Node*> q;
        q.push(root);
        int depth = 0;
        
        while(!q.empty()) {
            int size = q.size();
            depth++;
            for(int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();
                
                if(node->left == NULL && node->right == NULL)
                    return depth;
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        
        return 0; // In case the tree is empty
    }
};

int main() {
    int T = 1;
    string tc;
    getline(cin, tc);
    T = stoi(tc);
    Solution ob;
    while(T--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        cout << ob.minDepth(root) << endl;
    }
    return 0;
}

/* Sample Input:
2
3 9 20 N N 15 7
2 N 3 N 4 N 5 N 6

Sample Output:
2
5

*/