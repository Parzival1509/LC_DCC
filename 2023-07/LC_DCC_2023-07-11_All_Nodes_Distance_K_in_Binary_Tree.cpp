// LC DCC 2023/07/11
// 863. All Nodes Distance K in Binary Tree
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

// Tree Node
struct Node {
    int val;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->val = val;
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
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node() : val(0), left(nullptr), right(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr) {}
 *     Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}
 * };
*/

/**
 * Definition for a binary tree node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node(int x) : val(x), left(NULL), right(NULL) {}
 * };
*/

class Solution {
public:
    vector<int> distanceK(Node* root, Node* target, int k) {
        vector<int> ans;
        unordered_map<int, Node*> parent;
        queue<Node*> q;
        q.push(root);

        while(!q.empty()) {
            int si = q.size();

            for(int i = 0; i < si; i++) {
                auto top = q.front();
                q.pop();
                
                if(top -> left) {
                    parent[top->left->val] = top;
                    q.push(top->left); 
                }

                if(top -> right) {
                    parent[top->right->val] = top;
                    q.push(top->right); 
                }
            }
        }

        unordered_map<int, int> visited;
        q.push(target);
        
        while(k-- && !q.empty()) {
            int size = q.size();

            for(int i = 0; i < size; i++) {
                auto top = q.front();
                q.pop();

                visited[top -> val] = 1;

                if(top -> left && !visited[top->left->val])
                    q.push(top -> left);

                if(top -> right && !visited[top->right->val])
                    q.push(top -> right);

                if(parent[top->val] && !visited[parent[top->val] -> val])
                    q.push(parent[top->val]);
            }
        }

        while(!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
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
        
        vector<int> ans = ob.distanceK(root, target, k);
        for(int i: ans)
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}

/* Sample Input:
2
3 5 1 6 2 0 8 N N 7 4
5 2
1
1 3

Sample Output:
7 4 1


*/