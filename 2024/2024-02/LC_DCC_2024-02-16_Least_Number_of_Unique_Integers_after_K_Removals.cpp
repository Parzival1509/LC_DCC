// LC DCC 2024/02/16
// 1481. Least Number of Unique Integers after K Removals
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for (auto a : arr)
            mp[a]++;

        vector<int> v;
        int cnt = 0;
        for (auto a : mp)
            v.push_back(a.second);
        sort(v.begin(), v.end());

        for (int i = 0; i < v.size(); i++) {
            if (k > v[i]) {
                k -= v[i];
                v[i] = 0;
            }
            else {
                v[i] -= k;
                k = 0;
            }

            if (v[i] != 0) cnt++;
        }

        return cnt;
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n, 0);
        for(int &i: arr)
            cin >> i;
        cout << ob.findLeastNumOfUniqueInts(arr, k) << endl;
    }

    return 0;
}

/* Sample Input
2
3 1
5 5 4
7 3
4 3 1 1 3 3 2

Sample Output
1
2

*/