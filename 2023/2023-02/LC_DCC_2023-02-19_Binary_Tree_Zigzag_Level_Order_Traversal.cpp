// LC DCC 2023/02/19
// 103. Binary Tree Zigzag Level Order Traversal
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        bool reverse = false;
        while (!q.empty()) {
            int n = q.size();
            vector<int> level(n);
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                int index = reverse ? n - i - 1 : i;
                level[index] = node->val;
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            reverse = !reverse;
            ans.push_back(level);
        }
        return ans;
    }
};

int main() {
    Solution ob;
    int T = 1;
    cin>>T;
    while(T--) {
        
    }
    return 0;
}

/* Sample Input:
3
3 9 20 NULL NULL 15 7
1


Sample Output:
3
20 9
15 7

1



*/