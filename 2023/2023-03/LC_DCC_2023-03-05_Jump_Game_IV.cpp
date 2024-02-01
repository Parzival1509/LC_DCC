// LC DCC 2023/03/05
// Jump Game IV
// Hard

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> mp;
        for (int i=0; i<n; i++)
            mp[arr[i]].push_back(i);
        
        queue<int>q;
        vector<bool>visited(n, false);
        q.push(0);
        int steps = 0;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int currIdx = q.front();
                q.pop();
                if (currIdx == n - 1) return steps;

                //OPTION-1 (Move Forward)
                if (currIdx + 1 < n && !visited[currIdx + 1]) {
                    visited[currIdx + 1] = true;
                    q.push(currIdx + 1);
                }

                //OPTION-2 (Move Backward)
                if (currIdx - 1 >= 0 && !visited[currIdx - 1]) {
                    visited[currIdx - 1] = true;
                    q.push(currIdx - 1);
                }

                //OPTION-3 (Move to same valued idx)
                //newIdx coud be before currIdx or after currIdx
                for (int newIdx : mp[arr[currIdx]]) {
                    if (!visited[newIdx]) {
                        visited[newIdx] = true;
                        q.push(newIdx);
                    }
                }
                mp[arr[currIdx]].clear();
            }
            steps++;
        }
        return -1;
    }
};

int main() {
    Solution ob;
    int T = 1;
    cin>>T;
    while(T--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0; i<n; i++)
            cin>>arr[i];
        cout<<ob.minJumps(arr)<<endl;
    }
    return 0;
}

/* Sample Input:
3
10
100 -23 -23 404 100 23 23 23 3 404
1
7
8
7 6 9 6 9 6 9 7

Sample Output:
3
0
1

*/