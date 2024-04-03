// LC DCC 2024/03/26
// 41. First Missing Positive
// Hard

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int x = nums[i];
            while (x >= 1 && x <= n && x != i + 1 && nums[x - 1] != x) {
                swap(nums[x - 1], nums[i]);
                x = nums[i];
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] == i + 1)
                continue;
            return i + 1;
        }

        return n + 1;
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> nums(n, 0);
        for(int &i: nums)
            cin >> i;
        cout << ob.firstMissingPositive(nums) << endl;
    }

    return 0;
}

/* Sample Input
3
3
1 2 0
4
3 4 -1 1
5
7 8 9 11 12

Sample Output
3
2
1

*/