// LC DCC 2023/09/11
// 1282. Group the People Given the Group Size They Belong To
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> hsh;
        vector<vector<int>> ans;
        
        for(int i = 0; i < groupSizes.size(); ++i) {
            int sz = groupSizes[i];
            hsh[sz].push_back(i);
            
            if(hsh[sz].size() == sz) {
                ans.push_back(hsh[sz]);
                hsh[sz].clear();
            }
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n;
        cin >> n;
        vector<int> groupSizes(n, 0);
        for(int &i: groupSizes)
            cin >> i;

        vector<vector<int>> ans = ob.groupThePeople(groupSizes);
        for(auto v: ans) {
            for(int i: v)
                cout << i << ' ';
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}

/* Sample Input:
2
7
3 3 3 3 3 1 3
6
2 1 3 3 3 2

Sample Output:
0 1 2 
5 
3 4 6 

1 
2 3 4 
0 5 


*/