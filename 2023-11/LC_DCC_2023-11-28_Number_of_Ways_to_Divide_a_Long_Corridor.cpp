// LC DCC 2023/11/28
// 2147. Number of Ways to Divide a Long Corridor
// Hard

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int numberOfWays(string corridor) {
        int seats = 0, plants = 0;
        long long ans = 1;

        for(char i: corridor) {
            if(i == 'S') seats++;
            else if(seats == 2) plants++;

            if(seats == 3) {
                ans = (ans * (plants + 1)) % 1000000007;
                seats = 1;
                plants = 0;
            }
        }

        return (seats == 2)? (int)ans: 0;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        string corridor;
        cin >> corridor;
        cout << ob.numberOfWays(corridor) << endl;
    }

    return 0;
}

/* Sample Input:
5
SSPPSPS
SSPSPS
PPSPSP
SSSSSS
S

Sample Output:
3
2
1
1
0

*/