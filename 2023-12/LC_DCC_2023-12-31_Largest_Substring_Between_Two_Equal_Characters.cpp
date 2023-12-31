// LC DCC 2023/12/31
// 1624. Largest Substring Between Two Equal Characters
// Easy

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int ans = -1;

        // // Approach 1: Using Map
        // unordered_map<char, int> firstIndex;
        
        // for(int i = 0; i < s.size(); i++)
        //     if (firstIndex.find(s[i]) != firstIndex.end())
        //         ans = max(ans, i - firstIndex[s[i]] - 1);
        //     else firstIndex[s[i]] = i;

        // Approach 2: Using Array
        vector<int> v1(26, -1), v2(26, -1);

        for(int i = 0; i < s.size(); ++i) {
            int temp = s[i] - 'a';

            if(v1[temp] == -1) v1[temp] = i;
            else {
                v2[temp] = i;
                ans = max(ans, v2[temp] - v1[temp] - 1);
            }
        }

        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        string s;
        cin >> s;
        cout << ob.maxLengthBetweenEqualCharacters(s) << endl;
    }

    return 0;
}

/* Sample Input:
3
aa
abca
cbzxy

Sample Output:
0
2
-1

*/