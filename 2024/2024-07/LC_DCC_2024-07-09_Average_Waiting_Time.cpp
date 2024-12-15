// LC DCC 2024/07/09
// 1701. Average Waiting Time
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        double time_waiting = customers[0][1];
        int finished_prev = customers[0][0] + customers[0][1];

        for (int customer_ind = 1; customer_ind < n; ++customer_ind) {
            vector<int> times = customers[customer_ind];
            int arrive = times[0];

            int start_cook = max(arrive, finished_prev);
            int end_time = start_cook + times[1];
            finished_prev = end_time;
            time_waiting += end_time - arrive;
        }

        return time_waiting / n;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while (T--) {
        int n;
        cin >> n;
        vector<vector<int>> customers(n, {0, 0});
        for(int i = 0; i < n; i++)
            cin >> customers[i][0] >> customers[i][1];
        cout << fixed << setprecision(5) << ob.averageWaitingTime(customers) << endl;
    }

    return 0;
}

/* Sample Input
2
3
1 2
2 5
4 3
4
5 2
5 4
10 3
20 1

Sample Output
5.00000
3.25000

*/