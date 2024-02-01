// LC DCC 2023/08/29
// 2483. Minimum Penalty for a Shop
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();

        // // Approach 1: Using Extra Space
        // vector<int> nSum(n + 1, 0), ySum(n + 1, 0), penalty(n + 1, 0);

        // for(int i = 1; i <= n; i++) {
        //     nSum[i] = nSum[i - 1] + (customers[i - 1] == 'N');
        //     ySum[n - i] = ySum[n + 1 - i] + (customers[n - i] == 'Y');
        // }

        // int mn = INT_MAX, minHour = 0;
        // for(int i = 0; i <= n; i++) {
        //     penalty[i] = nSum[i] + ySum[i];
        //     if(penalty[i] < mn) {
        //         mn = penalty[i];
        //         minHour = i;
        //     }
        // }

        // return minHour;

        // Approach 2: Without Extra Space
        int score = 0, mxScore = 0, minHour = -1;
        for(int i = 0; i < n; i++) {
            score += (customers[i] == 'Y')? 1: -1;
            if(score > mxScore) {
                mxScore = score;
                minHour = i;
            }
        }

        return minHour + 1;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        string customers;
        cin >> customers;
        cout << ob.bestClosingTime(customers) << endl;
    }

    return 0;
}

/* Sample Input:
3
YYNY
NNNNN
YYYY

Sample Output:
2
0
4

*/