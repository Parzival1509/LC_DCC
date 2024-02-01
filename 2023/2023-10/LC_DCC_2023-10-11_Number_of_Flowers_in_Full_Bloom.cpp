// LC DCC 2023/10/11
// 2251. Number of Flowers in Full Bloom
// Hard

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        vector<int> start, end;
        for(auto& f: flowers) {
            start.push_back(f[0]);
            end.push_back(f[1]);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        vector<int> res;
        for(int p: persons) {
            int started = upper_bound(start.begin(), start.end(), p) - start.begin();
            int ended = lower_bound(end.begin(), end.end(), p) - end.begin();
            res.push_back(started - ended);
        }

        return res;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int f, n;
        cin >> f >> n;
        vector<vector<int>> flowers(f, vector<int> (2, 0));
        for(int i = 0; i < f; i++)
            cin >> flowers[i][0] >> flowers[i][1];

        vector<int> persons(n, 0);
        for(int &i: persons)
            cin >> i;

        vector<int> ans = ob.fullBloomFlowers(flowers, persons);
        for(int i: ans)
            cout << i << ' ';
        cout << endl;
    }

    return 0;
}

/* Sample Input:
2

4 4
1 6
3 7
9 12
4 13
2 3 7 11

2 3
1 10
3 3
3 3 2

Sample Output:
1 2 2 2 
2 2 1 

*/