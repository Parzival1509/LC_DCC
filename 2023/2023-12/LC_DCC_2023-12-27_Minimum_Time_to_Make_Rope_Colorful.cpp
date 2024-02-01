// LC DCC 2023/12/27
// 1578. Minimum Time to Make Rope Colorful
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int totalTime = 0, i = 0, j = 0;

        while(i < neededTime.size() && j < neededTime.size()) {
            int currTotal = 0, currMax = 0;
            while(j < neededTime.size() && colors[i] == colors[j]) {
                currTotal += neededTime[j];
                currMax = max(currMax, neededTime[j]);
                j++;
            }

            totalTime += currTotal - currMax;
            i = j;
        }

        return totalTime;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        string colors;
        int n;
        cin >> colors >> n;
        vector<int> neededTime(n, 0);
        for(int &i: neededTime)
            cin >> i;
        cout << ob.minCost(colors, neededTime) << endl;
    }

    return 0;
}

/* Sample Input:
3
abaac 5
1 2 3 4 5
abc 3
1 2 3
aabaa 5
1 2 3 4 1

Sample Output:
3
0
2

*/