// LC DCC 2023/05/02
// 1822. Sign of the Product of an Array
// Easy

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ans = 1;
        for(int num: nums) {
            if(num == 0) return 0;
            if(num < 0) ans *= -1;
        }
        return ans;
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        int n;
        cin>>n;
        vector<int> nums(n, 0);
        for(int &num: nums)
            cin>>num;
        cout<<ob.arraySign(nums)<<endl;
    }
    return 0;
}

/* Sample Input:
3
7
-1 -2 -3 -4 3 2 1
5
1 5 0 2 -3
5
-1 1 -1 1 -1

Sample Output:
1
0
-1

*/