// LC DCC 2023/11/19
// 1887. Reduction Operations to Make the Array Elements Equal
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n = nums.size();
        map<int, int> hsh;

        for(int i = 0; i < n; i++)
            hsh[nums[i]]++;

        int ans = 0, i = 0;
        
        if(hsh.size() > 1)  {
            for(auto it: hsh) {
                ans += i * it.second;
                i++;
            }
        }

        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n;
        cin >> n;
        vector<int> nums(n, 0);
        for(int &i: nums)
            cin >> i;
        cout << ob.reductionOperations(nums) << endl;
    }

    return 0;
}

/* Sample Input:
3
3
5 1 3
3
1 1 1
5
1 1 2 2 3

Sample Output:
3
0
4

*/