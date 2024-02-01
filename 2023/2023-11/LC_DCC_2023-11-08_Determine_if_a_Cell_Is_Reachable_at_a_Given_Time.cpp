// LC DCC 2023/11/08
// 2849. Determine if a Cell Is Reachable at a Given Time
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx == fx && sy == fy && t == 1)
            return false;
        
        int mnDis = max(abs(fx - sx), abs(fy - sy));
        
        return mnDis <= t;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int sx, sy, fx, fy, t;
        cin >> sx >> sy >> fx >> fy >> t;
        if(ob.isReachableAtTime(sx, sy, fx, fy, t)) cout << "true ";
        else cout << "false ";
        cout << endl;
    }

    return 0;
}

/* Sample Input:
4
2 4 7 7 6
3 1 7 3 3
1 1 1 1 1
1 1 1 1 2

Sample Output:
true 
false 
false 
true 

*/