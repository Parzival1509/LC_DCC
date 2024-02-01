// LC DCC 2023/07/01
// 2305. Fair Distribution of Cookies
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int unfair = INT_MAX;

    void dfs(int id, int fair, vector<int> &c, vector<int> &side) {
        if(id == c.size()) {
            int maxs = *max_element(side.begin(), side.end());
            if(maxs < unfair) unfair = maxs;
            return;
        }

        for(int i = 0; i < side.size(); ++i) {
            if(i > 0 && side[i - 1] == side[i]) continue;
            if(side[i] >= fair) continue;
            
            side[i] += c[id];
            dfs(id + 1, fair, c, side);
            side[i] -= c[id];
        }
    } 

    int distributeCookies(vector<int>& cookies, int k) {
        int sum = accumulate(cookies.begin(), cookies.end(), 0);
        int n = cookies.size();
        sort(cookies.begin(), cookies.end(), greater<int> ());
        int fair = sum / k;
        vector<int> side(k, 0);
        dfs(0, fair, cookies, side);

        return unfair;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while(T--) {
        int n, k;
        cin >> n >> k;
        vector<int> cookies(n, 0);
        for(int &i: cookies)
            cin >> i;
        cout << ob.distributeCookies(cookies, k) << endl;
    }
    return 0;
}

/* Sample Input:
2
5 2
8 15 10 20 8
8 3
6 1 3 2 2 4 1 2

Sample Output:
2
1
3

*/