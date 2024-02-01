// LC DCC 2024/01/01
// 455. Assign Cookies
// Easy

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = s.size();
        if(n == 0) return 0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int maxNum = 0, cookieIndex = n - 1, childIndex = g.size() - 1;
        while(cookieIndex >= 0 && childIndex >= 0) {
            if(s[cookieIndex] >= g[childIndex]) {
                maxNum++;
                cookieIndex--;
                childIndex--;
            }
            else childIndex--;
        }

        return maxNum;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<int> g(n, 0), s(m, 0);

        for(int &i: g)
            cin >> i;
        for(int &i: s)
            cin >> i;

        cout << ob.findContentChildren(g, s) << endl;
    }

    return 0;
}

/* Sample Input:
2
3 2
1 2 3
1 1
2 3
1 1
1 2 3

Sample Output:
1
2

*/