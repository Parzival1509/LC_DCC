// LC DCC 2024/02/17
// 1642. Furthest Building You Can Reach
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < n - 1; ++i) {
            int diff = heights[i + 1] - heights[i];
            if (diff > 0) {
                if (pq.size() < ladders)
                    pq.push(diff);
                else {
                    if (pq.empty() || pq.top() >= diff)
                        bricks -= diff;
                    else {
                        int poll = pq.top(); pq.pop();
                        pq.push(diff);
                        bricks -= poll;
                    }

                    if (bricks < 0) return i;
                }
            }
        }
        
        return n - 1;
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        int n, bricks, ladders;
        cin >> n >> bricks >> ladders;
        vector<int> heights(n, 0);
        for(int &i: heights)
            cin >> i;
        cout << ob.furthestBuilding(heights, bricks, ladders) << endl;
    }

    return 0;
}

/* Sample Input
3
7 5 1
4 2 7 6 9 14 12
9 10 2
4 12 2 7 3 18 20 3 19
4 17 0
14 3 19 3

Sample Output
4
7
3

*/