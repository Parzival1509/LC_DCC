// LC DCC 2023/05/27
// 1406. Stone Game III
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> sfsum(n+1, 0);

        for(int i = n-1; i >= 0; i--)
            sfsum[i] = sfsum[i+1] + stoneValue[i];

        vector<int> rv(n+1, 0);
        for(int i = n-1; i >= 0; i--) {
            rv[i] = INT_MIN;
            rv[i] = max(rv[i], sfsum[i] - rv[i+1]);

            if(i+2 <= n) rv[i] = max(rv[i], sfsum[i] - rv[i+2]);
            if(i+3 <= n) rv[i] = max(rv[i], sfsum[i] - rv[i+3]);
        }

        if(2*rv[0] < sfsum[0]) return "Bob";
        if(2*rv[0] > sfsum[0]) return "Alice";
        return "Tie";
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        int n;
        cin>>n;
        vector<int> stoneValue(n, 0);
        for(int &i: stoneValue)
            cin>>i;

        cout<<ob.stoneGameIII(stoneValue)<<endl;
    }
    return 0;
}

/* Sample Input:
3
4
1 2 3 7
4
1 2 3 -9
4
1 2 3 6

Sample Output:
Bob
Alice
Tie

*/