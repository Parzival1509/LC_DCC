// LC DCC 2023/04/17
// 1431. Kids With the Greatest Number of Candies
// Easy

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandies = *max_element(candies.begin(), candies.end());
        int n = candies.size();
        vector<bool> ans(n, false);
        for(int i=0; i<n; i++)
            if(candies[i] + extraCandies >= maxCandies) ans[i] = true;
        return ans;
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        int n, extraCandies;
        cin>>n>>extraCandies;
        vector<int> candies(n, 0);
        for(int &i: candies)
            cin>>i;
        vector<bool> ans = ob.kidsWithCandies(candies, extraCandies);
        for(auto el: ans) {
            if(el) cout<<"true ";
            else cout<<"false ";
        }
        cout<<endl;
    }
    return 0;
}

/* Sample Input:
3
5 3
2 3 5 1 3
5 1
4 2 1 1 2
3 10
12 1 12

Sample Output:
true true true false true 
true false false false false 
true false true 

*/