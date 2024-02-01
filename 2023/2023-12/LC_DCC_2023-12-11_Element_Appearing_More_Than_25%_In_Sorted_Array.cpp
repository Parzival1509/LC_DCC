// LC DCC 2023/12/11
// 1287. Element Appearing More Than 25% In Sorted Array
// Easy

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int ct = 0, n = arr.size();
        for(int i = 0; i < n - 1; i++) {
            if(arr[i] == arr[i + 1])
                ct++;
            else ct = 1;

            if(ct > n / 4) return arr[i];
        }

        return arr[0];
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
        cout << ob.findSpecialInteger(arr) << endl;
    }

    return 0;
}

/* Sample Input:
4
1
1
4
1 2 3 3
2
1 1
9
1 2 2 6 6 6 6 7 10

Sample Output:
1
3
1
6

*/