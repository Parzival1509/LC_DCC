// LC DCC 2024/04/29
// 2997. Minimum Number of Operations to Make Array XOR Equal to K
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int finalXor = 0, count = 0;
        for (int n : nums)
            finalXor = finalXor ^ n;
        
        while (k || finalXor) {
            if ((k % 2) != (finalXor % 2))
                count++;
            k /= 2;
            finalXor /= 2;
        }
        
        return count;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n, 0);
        for(int &i: nums)
            cin >> i;
        cout << ob.minOperations(nums, k) << endl;
    }

    return 0;
}

/* Sample Input
2
4 1
2 1 3 4
4 0
2 0 2 0

Sample Output
2
0 

*/