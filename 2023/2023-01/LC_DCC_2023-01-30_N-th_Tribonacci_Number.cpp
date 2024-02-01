// LC DCC 2023/01/30
// 1137. N-th Tribonacci Number
// Easy

#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int tribonacci(int n) {
        int nums[38];
        nums[0] = 0, nums[1] = nums[2] = 1;
        for(int i=3; i<=n; i++)
            nums[i] = nums[i-1] + nums[i-2] + nums[i-3];
        return nums[n];
    }
};

int main() {
    Solution ob;
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        cout<<ob.tribonacci(n)<<endl;
    }
    return 0;
}

/* Sample Input:
3
4
25
37

Sample Output:
4
1389537
2082876103

*/