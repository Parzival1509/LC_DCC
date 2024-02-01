// LC DCC 2023/02/13
// 1523. Count Odd Numbers in an Interval Range
// Easy

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int countOdds(int lo, int hi) {
        if((hi-lo)%2 == 0) {
            if(lo%2 == 0) return (hi-lo)/2;
            else return (hi-lo)/2 + 1;
        }
        return (hi-lo)/2 + 1;
    }
};

int main() {
    Solution ob;
    int t;
    cin>>t;
    while(t--) {
        int lo, hi;
        cin>>lo>>hi;
        cout<<ob.countOdds(lo, hi)<<endl;
    }
    return 0;
}

/* Sample Input:
2
3 7
8 10

Sample Output:
3
1

*/