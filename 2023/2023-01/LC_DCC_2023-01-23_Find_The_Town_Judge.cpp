// LC DCC 2023/01/23
// 997. Find the Town Judge
// Easy

#include<bits/stdc++.h>
using namespace std;

int start_up() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
int static r = start_up();

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> hsh(n+1, 0), f(n+1, 0);
        for(int i=0; i<trust.size(); i++) {
            f[trust[i][0]]++;
            hsh[trust[i][1]]++;
        }
        for(int i=1; i<=n; i++)
            if(hsh[i] == n-1 && f[i] == 0)
                return i;
        return -1;
    }
};

int main() {
    Solution ob;
    int t;
    cin>>t;
    while(t--) {
        int n, x;
        cin>>n>>x;
        vector<vector<int>> trust(x, vector<int> (2, 0));
        for(int i=0; i<x; i++)
            cin>>trust[i][0]>>trust[i][1];
        cout<<ob.findJudge(n, trust)<<endl;
    }
    return 0;
}

/* Sample Input
3
2 1
1 2
3 2
1 3
2 3
3 3
1 3
2 3
3 1

Sample Output
2
3
-1

*/