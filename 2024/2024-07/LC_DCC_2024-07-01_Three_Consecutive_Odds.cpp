// LC DCC 2024/07/01
// 1550. Three Consecutive Odds
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count = 0;
        for (int num : arr) {
            if (num % 2 != 0) {
                count++;
                if (count == 3)
                    return true;
            } else
                count = 0;
        }

        return false;
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
        if(ob.threeConsecutiveOdds(arr)) cout << "true\n";
        else cout << "false\n";
    }

    return 0;
}

/* Sample Input
2
4
2 6 4 1
9
1 2 34 3 4 5 7 23 12

Sample Output
false
true

*/