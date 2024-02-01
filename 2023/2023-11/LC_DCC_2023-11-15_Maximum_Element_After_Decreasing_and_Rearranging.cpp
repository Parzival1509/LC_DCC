// LC DCC 2023/11/15
// 1846. Maximum Element After Decreasing and Rearranging
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        if(arr[0] != 1) arr[0] = 1;
        int n = arr.size(), ans = 1;

        for(int i = 1; i < n; i++) {
            if(arr[i] - arr[i - 1] > 1)
                arr[i] = arr[i - 1] + 1;
            ans = max(ans, arr[i]);
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
        vector<int> arr(n, 0);
        for(int &i: arr)
            cin >> i;
        cout << ob.maximumElementAfterDecrementingAndRearranging(arr) << endl;
    }

    return 0;
}

/* Sample Input:
3
5
2 2 1 2 1
3
10 1 100
5
1 2 3 4 5

Sample Output:
2
3
5

*/