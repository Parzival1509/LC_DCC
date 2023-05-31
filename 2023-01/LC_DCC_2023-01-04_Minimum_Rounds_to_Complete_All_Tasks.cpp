// LC DCC 2023/01/04
// 2244. Minimum Rounds to Complete All Tasks
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // My Sol
    // O(n log(n)) T.C.
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> mp;
        int ans=0;
        for(int i=0; i<tasks.size(); i++)
            mp[tasks[i]]++;
        for(auto el: mp) {
            if(el.second == 1) return -1;
            ans += ceil((el.second)/3.0);
        }
        return ans;
    }
};

int main() {
    int T;
    cin>>T;
    Solution ob;
    while(T--) {
        int n;
        cin>>n;
        vector<int> tasks(n);
        for(int i=0; i<n; i++)
            cin>>tasks[i];
        cout<<ob.minimumRounds(tasks)<<endl;
    }
    return 0;
}

/* Sample Input
2
10
2 2 3 3 2 4 4 4 4 4
3
2 3 3
4
5 5 5 5

Sample Output
4
-1
2

*/