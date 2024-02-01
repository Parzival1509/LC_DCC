// LC DCC 2023/10/31
// 2433. Find The Original Array of Prefix Xor
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int> arr(n, 0);
        arr[0] = pref[0];

        for(int i = 1; i < n; i++)
            arr[i] = pref[i] ^ pref[i - 1];

        return arr;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n;
        cin >> n;
        vector<int> arr(n, 0);
        for(int &i: arr)
            cin >> i;
        vector<int> ans = ob.findArray(arr);
        for(int i: ans)
            cout << i << ' ';
        cout << endl;
    }

    return 0;
}

/* Sample Input:
2
5
5 2 0 3 1
1
13

Sample Output:
5 7 2 3 2 
13 

*/