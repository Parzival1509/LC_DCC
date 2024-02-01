// LC DCC 2023/07/04
// 137. Single Number II
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for (int num: nums) {
            ones = (ones ^ num) & ~twos;
            twos = (twos ^ num) & ~ones;
        }
        return ones;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while(T--) {
        int n;
        cin >> n;
        vector<int> nums(n, 0);
        for(int &i: nums)
            cin >> i;
        cout << ob.singleNumber(nums) << endl;
    }
    return 0;
}

/* Sample Input:
2
4
2 2 3 2
7
1 0 1 0 1 0 99

Sample Output:
3
99

*/