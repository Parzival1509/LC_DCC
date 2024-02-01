// LC DCC 2024/01/23
// 1239. Maximum Length of a Concatenated String with Unique Characters
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(const vector<string>& arr, const string& path, int idx, int& result) {
        if (isUniqueChars(path))
            result = max(result, (int)(path.length()));

        if (idx == arr.size() || !isUniqueChars(path))
            return;

        for (int i = idx; i < arr.size(); i++)
            dfs(arr, path + arr[i], i + 1, result);
    }

    bool isUniqueChars(const string& s) {
        unordered_set<char> set;
        for (char c : s) {
            if (set.count(c))
                return false;
            set.insert(c);
        }

        return true;
    }

    int maxLength(vector<string>& arr) {
        int res = 0;
        
        // // Approach 1: Bit Operation
        // vector<int> dp = {0};
        // for (string& s : arr) {
        //     int a = 0, dup = 0;
        //     for (char c : s) {
        //         dup |= a & (1 << (c - 'a'));
        //         a |= 1 << (c - 'a');
        //     }
            
        //     if (dup > 0) continue;
            
        //     for (int i = dp.size() - 1; i >= 0; i--) {
        //         if ((dp[i] & a) > 0)
        //             continue;
        //         dp.push_back(dp[i] | a);
        //         res = max(res, __builtin_popcount(dp[i] | a));
        //     }
        // }
        
        // Approach 2: DFS
        dfs(arr, "", 0, res);

        return res;
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<string> arr(n, "");
        for(auto &i: arr)
            cin >> i;
        cout << ob.maxLength(arr) << endl;
    }

    return 0;
}

/* Sample Input
3
3
un iq ue
4
cha r act ers
1
abcdefghijklmnopqrstuvwxyz

Sample Output
4
6
26

*/