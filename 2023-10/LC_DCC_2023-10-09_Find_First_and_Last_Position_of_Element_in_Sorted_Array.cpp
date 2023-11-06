// LC DCC 2023/10/09
// 34. Find First and Last Position of Element in Sorted Array
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int x) {
        int n = arr.size(), lb = -1, rb = -1, lo = 0, hi = n - 1;
        
        // Finding the left bound
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            if(arr[mid] == x) lb = mid;
            
            if(arr[mid] >= x) hi = mid - 1;
            else lo = mid + 1;
        }
        
        // Finding the right bound
        lo = 0, hi = n - 1;
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            if(arr[mid] == x) rb = mid;
            
            if(arr[mid] > x) hi = mid - 1;
            else lo = mid + 1;
        }
        
        return {lb, rb};
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n, 0);
        for(int &i: arr)
            cin >> i;
        vector<int> ans = ob.searchRange(arr, x);
        for(int i: ans)
            cout << i << ' ';
        cout << endl;
    }

    return 0;
}

/* Sample Input:
2
6 8
5 7 7 8 8 10
6 6
5 7 7 8 8 10

Sample Output:
3 4 
-1 -1 

*/