// LC DCC 2023/01/07
// 134. Gas Station
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size(), total_cost=0, total_gas=0;
        
        for(int i=0; i<n; i++) {
            total_cost += cost[i];
            total_gas += gas[i];
        }

        if(total_gas < total_cost) return -1;
        
        int ans=0, currfuel=0;
        for(int i=0; i<n; i++) {
            currfuel += gas[i]-cost[i];
            if(currfuel < 0){
                ans = i+1;
                currfuel = 0;
            }
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
        vector<int> gas(n), cost(n);
        for(int i=0; i<n; i++)
            cin>>gas[i];
        for(int i=0; i<n; i++)
            cin>>cost[i];
        cout<<ob.canCompleteCircuit(gas, cost)<<endl;
    }
    return 0;
}

/* Sample Input
2
5
1 2 3 4 5
3 4 5 1 2
3
2 3 4
3 4 3

Sample Output
3
-1

*/