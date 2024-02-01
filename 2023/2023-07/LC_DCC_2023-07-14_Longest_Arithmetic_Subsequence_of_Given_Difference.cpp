// LC DCC 2023/07/14
// 1218. Longest Arithmetic Subsequence of Given Difference
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int score = 0;
        unordered_map<int, int> exists;
        for (int k = 0; k < arr.size(); k++) {
            exists[arr[k]] = exists[arr[k] - difference] + 1;
            score = exists[arr[k]] > score? exists[arr[k]]: score;
        }
        return score;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while(T--) {
        int n, difference;
        cin >> n >> difference;
        vector<int> arr(n, 0);
        for(int &i: arr)
            cin >> i;
        cout << ob.longestSubsequence(arr, difference) << endl;
    }
    
    return 0;
}

/* Sample Input:
3
4 1
1 2 3 4
4 1
1 3 5 7
9 -2
1 5 7 8 5 3 4 2 1

Sample Output:
4
1
4

*/