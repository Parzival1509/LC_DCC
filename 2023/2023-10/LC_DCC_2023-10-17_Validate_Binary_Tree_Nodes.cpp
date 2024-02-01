// LC DCC 2023/10/17
// 1361. Validate Binary Tree Nodes
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    bool validateBinaryTreeNodes(int n, std::vector<int>& leftChild, std::vector<int>& rightChild) {
        // Calculating indegree for each node
        vector<int> indegree(n, 0);
        for(int i = 0; i < n; ++i) {
            if(leftChild[i] != -1) indegree[leftChild[i]]++;
            if(rightChild[i] != -1) indegree[rightChild[i]]++;
        }

        // Ensuring that there is only 1 root
        int root = -1;
        for(int i = 0; i < n; ++i) {
            if(indegree[i] == 0) {
                if(root == -1) root = i;
                else return false;
            }
        }

        // If the tree has no root, then it is a cycle
        if(root == -1) return false;

        // Ensuring that every node has single parent
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(root);
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            if(visited[node]) return false;

            visited[node] = true;
            if(leftChild[node] != -1) q.push(leftChild[node]);
            if(rightChild[node] != -1) q.push(rightChild[node]);
        }

        return accumulate(visited.begin(), visited.end(), 0) == n;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n;
        cin >> n;
        vector<int> leftChild(n, 0);
        for(int &i: leftChild)
            cin >> i;
        vector<int> rightChild(n, 0);
        for(int &i: rightChild)
            cin >> i;
        if(ob.validateBinaryTreeNodes(n, leftChild, rightChild)) cout << "true ";
        else cout << "false ";
        cout << endl;
    }

    return 0;
}

/* Sample Input:
4
4
1 -1 3 -1
2 -1 -1 -1
4
1 -1 3 -1
2 3 -1 -1
2
1 0
-1 -1
6
1 -1 -1 4 -1 -1
2 -1 -1 5 -1 -1

Sample Output:
true 
false 
false 
false 

*/