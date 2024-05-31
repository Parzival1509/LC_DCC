// LC DCC 2024/05/30
// 1442. Count Triplets That Can Form Two Arrays of Equal XOR
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int count = 0, n = arr.size();

        // // Approach 1: T.C. = O(N^3)
        // for (int i = 0; i < n; i++)
        //     for (int j = i + 1; j < n; j++) {
        //         int a = 0, b = 0;
        //         for (int k = i; k < j; k++)
        //             a ^= arr[k];
        //         for (int k = j; k < n; k++) {
        //             b ^= arr[k];
        //             if (a == b)
        //                 count++;
        //         }
        //     }
        
        // Approach 2: T.C. = O(N^2)
        for (int i = 0; i < n; i++) {
            int val = arr[i];
            for (int k = i + 1; k < n; k++) {
                val ^= arr[k];
                if (val == 0)
                    count += (k - i);
            }
        }

        return count;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while (T--) {
        int n;
        cin >> n;
        vector<int> arr(n, 0);
        for(int &i: arr)
            cin >> i;
        cout << ob.countTriplets(arr) << endl;
    }

    return 0;
}

/* Sample Input
2
5
2 3 1 6 7
5
1 1 1 1 1

Sample Output
4
10

*/