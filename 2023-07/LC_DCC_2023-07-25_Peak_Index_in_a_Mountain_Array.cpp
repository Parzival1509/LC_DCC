// LC DCC 2023/07/25
// 852. Peak Index in a Mountain Array
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0, high = arr.size() - 1;
        while(low < high) {
            int mid = (low + high) / 2;

            if(arr[mid] < arr[mid + 1]) low = mid + 1;
            else high = mid; 
        }

        return low;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while(T--) {
        int n;
        cin >> n;
        vector<int> arr(n, 0);
        for(int &i: arr)
            cin >> i;
        cout << ob.peakIndexInMountainArray(arr) << endl;
    }
    
    return 0;
}

/* Sample Input:
3
3
0 1 0
4
0 2 1 0
4
0 10 5 2

Sample Output:
1
1
1

*/