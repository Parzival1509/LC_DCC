// LC DCC 2024/03/19
// 621. Task Scheduler
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {0};
        for (char task : tasks)
            freq[task - 'A']++;

        sort(begin(freq), end(freq));

        int chunk = freq[25] - 1;
        int idel = chunk * n;
        for (int i = 24; i >= 0; i--)
            idel -= min(chunk, freq[i]);

        return (idel < 0) ? tasks.size() : (tasks.size() + idel);
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<char> tasks(m, ' ');
        for(char &i: tasks)
            cin >> i;
        cout << ob.leastInterval(tasks, n) << endl;
    }

    return 0;
}

/* Sample Input
3
2 6
AAABBB
1 6
ACABDB
3 6
AAABBB

Sample Output
8
6
10

*/