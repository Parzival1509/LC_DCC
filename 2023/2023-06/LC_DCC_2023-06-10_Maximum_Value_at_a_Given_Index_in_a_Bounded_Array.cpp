// LC DCC 2023/06/10
// 1802. Maximum Value at a Given Index in a Bounded Array
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    // // Approach 1:
    // int maxValue(int n, int index, int maxSum) {
    //     if(n == 1) return maxSum;

    //     maxSum -= n;
    //     int left = index, right = n - index - 1, ans = 1;
    //     int t1 = -1, t2 = -1;

    //     while(maxSum) {
    //         t1++;
    //         t2++;
    //         int x = min(t1, left) + min(t2, right) + 1;

    //         if(maxSum < x) break; 
            
    //         maxSum -= x;
    //         ans++;
    //         if(x == (left + right + 1)) {
    //             ans += (maxSum/x);
    //             break;
    //         }
    //     }

    //     return ans;
    // }

    // Approach 2:
    ll test(int a, int index, int n) {
        ll b = max(0, a - index);
        ll res = (a + b) * (a - b + 1)/2;
        b = max(0, (a - ((n - 1) - index)));
        res += (a + b) * (a - b + 1)/2;
        
        return res - a;
    }
    
    int maxValue(int n, int index, int maxSum) {
        maxSum -= n;
        int l = 0, r = maxSum;
        
        while(l < r) {
            int m = (l + r + 1)/2;
            if(test(m, index, n) > maxSum)
                r = m - 1;
            else l = m;
        }

        return l + 1;
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        int n, index, maxSum;
        cin >> n >> index >> maxSum;
        cout << ob.maxValue(n, index, maxSum) << endl;
    }
    return 0;
}

/* Sample Input:
2
4 2 6
6 1 10

Sample Output:
2
3

*/