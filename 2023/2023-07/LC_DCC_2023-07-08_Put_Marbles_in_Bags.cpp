// LC DCC 2023/07/08
// 2551. Put Marbles in Bags
// Hard

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    ll putMarbles(vector<int>& weights, int k) {
        // // Approach 1: Using Priority Queue
        // ll minans = weights[0] + weights[weights.size()-1];
        // ll maxans = minans;
        // priority_queue<int> pqmax;
        // priority_queue<int, vector<int>, greater<int>> pqmin;
        
        // for(int i = 1; i < weights.size(); i++) {
        //     pqmin.push(weights[i] + weights[i - 1]);
        //     pqmax.push(weights[i] + weights[i - 1]);
        // }
        
        // for(int i = 1; i < k; i++) {
        //     minans += pqmin.top();
        //     maxans += pqmax.top();
        //     pqmin.pop();
        //     pqmax.pop();
        // }

        // Approach 2: Using Vector
        int n = weights.size();
        ll maxans = weights[0] + weights[n - 1];
        ll minans = weights[0] + weights[n - 1];
        
        vector<ll> adjSum;
        for(int i = 0; i < n - 1; i++)
            adjSum.push_back(weights[i] + weights[i+1]);
        
        sort(adjSum.begin(), adjSum.end(), greater<int> ());
        
        for(int i = 0; i < k - 1; i++) {
            maxans += adjSum[i];
            minans += adjSum[n - i - 2];
        }

        return (maxans - minans);
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while(T--) {
        int n, k;
        cin >> n >> k;
        vector<int> weights(n, 0);
        for(int &i: weights)
            cin >> i;
        cout << ob.putMarbles(weights, k) << endl;
    }
    return 0;
}

/* Sample Input:
2
4 2
1 3 5 1
2 2
1 3

Sample Output:
4
0

*/