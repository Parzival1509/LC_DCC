// LC DCC 2023/11/12
// 815. Bus Routes
// Hard

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;

        int maxStop = -1;
        for(auto& route: routes)
            for (int stop: route)
                maxStop = max(maxStop, stop);

        if(maxStop < target) return -1;

        int n = routes.size();
        vector<int> minBusesToReach(maxStop + 1, INT_MAX);
        minBusesToReach[source] = 0;

        bool flag = true;
        while(flag) {
            flag = false;
            for(auto& route: routes) {
                int mn = n + 1;
                for(int stop: route)
                    mn = min(mn, minBusesToReach[stop]);
                mn++;

                for(int stop: route)
                    if(minBusesToReach[stop] > mn) {
                        minBusesToReach[stop] = mn;
                        flag = true;
                    }
            }
        }

        return (minBusesToReach[target] < n + 1)? minBusesToReach[target]: -1;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n, source, target;
        cin >> n >> source >> target;
        vector<vector<int>> routes(n);
        for(int i = 0; i < n; i++) {
            int r;
            cin >> r;
            routes[i].resize(r);
            for(int j = 0; j < r; j++)
                cin >> routes[i][j];
        }

        cout << ob.numBusesToDestination(routes, source, target) << endl;
    }

    return 0;
}

/* Sample Input:
2

2 1 6
3 1 2 7
3 3 6 7

5 15 12
2 7 12
3 4 5 15
1 6
2 15 19
3 9 12 13

Sample Output:
2
-1

*/