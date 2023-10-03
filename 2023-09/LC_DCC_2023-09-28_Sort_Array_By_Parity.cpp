// LC DCC 2023/09/28
// 905. Sort Array By Parity
// Easy

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0, j = 0, n = nums.size();
        while(j < n) {
            if(nums[j] % 2 == 0)
                swap(nums[i++], nums[j]);
            j++;
        }

        return nums;
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
        ob.sortArrayByParity(nums);
        for(int i: nums)
            cout << i << ' ';
        cout << endl;
    }

    return 0;
}

/* Sample Input:
3
4
3 1 2 4
5
1 2 3 4 5
6
2 4 7 8 9 10

Sample Output:
2 4 3 1 
2 4 3 1 5 
2 4 8 10 9 7 

*/