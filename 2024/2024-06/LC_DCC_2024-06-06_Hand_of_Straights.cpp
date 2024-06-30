// LC DCC 2024/06/06
// 846. Hand of Straights
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool findSuccessors(vector<int>& hand, int groupSize, int i, int n) {
        int next = hand[i] + 1;
        hand[i] = -1;
        int count = 1;
        i += 1;
        while (i < n && count < groupSize) {
            if (hand[i] == next) {
                next = hand[i] + 1;
                hand[i] = -1;
                count++;
            }
            i++;
        }
        
        return count == groupSize;
    }

    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0)
            return false;
        
        sort(hand.begin(), hand.end());
        for (int i = 0; i < n; i++)
            if (hand[i] >= 0)
                if (!findSuccessors(hand, groupSize, i, n))
                    return false;

        return true;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while (T--) {
        int n, groupSize;
        cin >> n >> groupSize;
        vector<int> hand(n, 0);
        for(int &i: hand)
            cin >> i;
        if(ob.isNStraightHand(hand, groupSize)) cout << "true\n";
        else cout << "false\n";
    }

    return 0;
}

/* Sample Input
2
9 3
1 2 3 6 2 3 4 7 8
5 4
1 2 3 4 5

Sample Output
true
false

*/