// LC DCC 2024/05/04
// 881. Boats to Save People
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int i = 0, n = people.size(), j = n - 1, ans = 0;
        while (i < j) {
            if (people[i] + people[j] <= limit) {
                i++;
                j--;
                ans++;
            } else {
                j--;
                ans++;
            }
        }
        if (i == j)
            ans++;

        return ans;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while (T--) {
        int n, limit;
        cin >> n >> limit;
        vector<int> people(n, 0);
        for(int &i: people)
            cin >> i;
        cout << ob.numRescueBoats(people, limit) << endl;
    }

    return 0;
}

/* Sample Input
3
2 3
1 2
4 3
3 2 2 1
4 5
3 5 3 4

Sample Output
1
3
4

*/