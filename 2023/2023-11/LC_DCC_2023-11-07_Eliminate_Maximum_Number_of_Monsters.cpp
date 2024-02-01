// LC DCC 2023/11/07
// 1921. Eliminate Maximum Number of Monsters
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        
        // // Approach 1: Initial Sort, T.C. = O(N*logN), S.C. = O(N)
        // vector<int> arrivalTime(n);
        // for(int i = 0; i < n; i++)
        //     arrivalTime[i] = (dist[i] - 1) / speed[i];

        // sort(arrivalTime.begin(), arrivalTime.end());

        // for(int i = 0; i < n; i++)
        //     if(i > arrivalTime[i])
        //         return i;

        // Approach 2: Counting Sort, T.C. = O(N), S.C. = O(N)
        for(int i = 0; i < n; ++i) {
            dist[i] = ceil(static_cast<double>(dist[i]) / speed[i]);
            speed[i] = 0;
        }

        for(int arrivalTime: dist) {
            if(arrivalTime >= n) continue;
            speed[arrivalTime] += 1;
        }

        for(int i = 1; i < n; ++i) {
            speed[i] += speed[i - 1];
            if(speed[i] > i)
                return i;
        }
        
        return n;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n;
        cin >> n;
        vector<int> dist(n, 0);
        for(int &i: dist)
            cin >> i;
        vector<int> speed(n, 0);
        for(int &i: speed)
            cin >> i;
        cout << ob.eliminateMaximum(dist, speed) << endl;
    }

    return 0;
}

/* Sample Input:
3
3
1 3 4
1 1 1
4
1 1 2 3
1 1 1 1
3
3 2 4
5 3 2

Sample Output:
3
1
1

*/