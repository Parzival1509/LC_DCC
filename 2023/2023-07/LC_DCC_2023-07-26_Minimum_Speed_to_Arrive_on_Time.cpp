// LC DCC 2023/07/26
// 1870. Minimum Speed to Arrive on Time
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    bool check(vector<int> dist, int speed, double hour) {
        double time = 0.0;
        int n = dist.size();
        for(int i = 0; i < n - 1; i++)
            time += ceil(1.0 * dist[i] / speed);
        time += 1.0 * dist[n - 1] / speed;

        return time <= hour;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        if(hour < dist.size() - 1) return -1;

        int lo = 1, hi = 1e7;
        int ans = -1;
        while(lo <= hi) {
            int speed = (lo + hi) / 2;
            if(check(dist, speed, hour)) {
                ans = speed;
                hi = speed - 1;
            }
            else lo = speed + 1;
        }

        return ans;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while(T--) {
        int n;
        double hour;
        cin >> n >> hour;
        vector<int> dist(n, 0);
        for(int &i: dist)
            cin >> i;
        cout << ob.minSpeedOnTime(dist, hour) << endl;
    }
    
    return 0;
}

/* Sample Input:
4

3 6
1 3 2

3 2.7
1 3 2

3 1.9
1 3 2

3 2.01
1 1 100000

Sample Output:
1
3
-1
10000000

*/