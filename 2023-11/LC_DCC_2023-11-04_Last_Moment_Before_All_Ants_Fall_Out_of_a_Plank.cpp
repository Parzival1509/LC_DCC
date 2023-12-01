// LC DCC 2023/11/04
// 1503. Last Moment Before All Ants Fall Out of a Plank
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // Variable to store the time
        int time = 0;
        
        // Finding the ant which will take the most time to reach the left end
        for(int l: left)
            time = max(time, l);

        // Finding the ant which will take the most time to reach the right end
        for(int r: right)
            time = max(time, n - r);    // (n - r) = the distance from right end

        return time;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n, l, r;
        cin >> n >> l >> r;
        
        vector<int> left(l, 0);
        for(int &i: left)
            cin >> i;
        vector<int> right(r, 0);
        for(int &i: right)
            cin >> i;

        cout << ob.getLastMoment(n, left, right) << endl;
    }

    return 0;
}

/* Sample Input:
6
4
2 4 3
2 0 1
7
0
8 0 1 2 3 4 5 6 7
7
8 0 1 2 3 4 5 6 7
0
9
1 5
1 4
20
3 4 7 15
4 9 3 13 10
1000
1 0
0

Sample Output:
4
7
7
5
17
0

*/