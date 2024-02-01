// LC DCC 2023/03/06
// 1539. Kth Missing Positive Number
// Easy

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // // T.C. = O(N)
        // for(int i: arr)
        //     if(i<=k) k++;
        //     else break;
        // return k;

        // T.C. = O(log(N))
        int n = arr.size(), lo = 0, hi = n-1;
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            if(arr[mid] - (mid + 1) < k) lo = mid + 1;
            else hi = mid - 1;
        }
        return lo + k;
    }
};

int main() {
    Solution ob;
    int T = 1;
    cin>>T;
    while(T--) {
        int n, k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0; i<n; i++)
            cin>>arr[i];
        cout<<ob.findKthPositive(arr, k)<<endl;
    }
    return 0;
}

/* Sample Input:
2
5 5
2 3 4 7 11
4 2
1 2 3 4

Sample Output:
9
6

*/