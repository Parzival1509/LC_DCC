// LC DCC 2024/04/09
// 2073. Time Needed to Buy Tickets
// Easy

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int total = 0;
        for (int i = 0; i < tickets.size(); ++i)
            if (i <= k)
                total += min(tickets[i], tickets[k]);
            else total += min(tickets[i], tickets[k] - 1);

        return total;
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> tickets(n, 0);
        for(int &i: tickets)
            cin >> i;
        cout << ob.timeRequiredToBuy(tickets, k) << endl;
    }

    return 0;
}

/* Sample Input
2
3 2
2 3 2
4 0
5 1 1 1

Sample Output
6
8

*/