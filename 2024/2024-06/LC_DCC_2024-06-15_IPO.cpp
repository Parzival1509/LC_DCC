// LC DCC 2024/06/15
// 502. IPO
// Hard

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> projects;
        for (int i = 0; i < n; i++)
            projects.emplace_back(capital[i], profits[i]);
        sort(projects.begin(), projects.end());

        priority_queue<int> q;
        int ptr = 0;
        for (int i = 0; i < k; i++) {
            while (ptr < n && projects[ptr].first <= w)
                q.push(projects[ptr++].second);
            if (q.empty())
                break;

            w += q.top();
            q.pop();
        }

        return w;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while (T--) {
        int n, k, w;
        cin >> n >> k >> w;
        vector<int> profits(n, 0);
        for(int &i: profits)
            cin >> i;
        vector<int> capital(n, 0);
        for(int &i: capital)
            cin >> i;
        cout << ob.findMaximizedCapital(k, w, profits, capital) << endl;
    }

    return 0;
}

/* Sample Input
2
3 2 0
1 2 3
0 1 1
3 3 0
1 2 3
0 1 2

Sample Output
4
6

*/