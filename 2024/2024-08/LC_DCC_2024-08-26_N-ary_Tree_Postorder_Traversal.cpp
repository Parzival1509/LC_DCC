// LC DCC 2024/08/26
// 590. N-ary Tree Postorder Traversal
// Easy

#include <bits/stdc++.h>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> ans;

    vector<int> postorder(Node* root) {
        if (!root) return ans;
        
        for (auto& child : root->children)
            postorder(child);
        ans.push_back(root->val);

        return ans;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while (T--) {

    }

    return 0;
}

/* Sample Input


Sample Output


*/