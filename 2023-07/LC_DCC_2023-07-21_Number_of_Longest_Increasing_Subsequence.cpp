// LC DCC 2023/07/21
// 673. Number of Longest Increasing Subsequence
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> size(n, 1), ways(n, 1);

        int maxL = 1;
        for(int i = 1; i < n; i++)
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
                    if(size[j] + 1 > size[i]) {
                        size[i] = size[j] + 1;
                        ways[i] = ways[j];
                    }
                    else if(nums[i] > nums[j] && size[j] + 1 == size[i]) {
                        ways[i] += ways[j];
                    }
                }
                
                maxL = max(maxL, size[i]);
            }

        int res = 0;
        for(int i = 0; i < n; i++)
            if(size[i] == maxL)
                res += ways[i];

        return res;
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
        cout << ob.findNumberOfLIS(nums) << endl;
    }
    
    return 0;
}

/* Sample Input:
2
5
1 3 5 7 4
5
2 2 2 2 2

Sample Output:
1
5

*/