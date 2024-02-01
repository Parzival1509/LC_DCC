// LC DCC 2024/02/01
// 2966. Divide Array Into Arrays With Max Difference
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> result(size / 3, vector<int> (3));
        int groupIndex = 0;

        for (int i = 0; i < size; i += 3) {
            if (i + 2 < size && nums[i + 2] - nums[i] <= k) {
                result[groupIndex] = { nums[i], nums[i + 1], nums[i + 2] };
                groupIndex++;
            }
            else return vector<vector<int>> ();
        }
 
        return result;
    }
}; 

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n, 0);
        for(int &i: nums)
            cin >> i;
        vector<vector<int>> ans = ob.divideArray(nums, k);
        for(auto i: ans) {
            for(int e: i)
                cout << e << ' ';
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}

/* Sample Input
2
9 2
1 3 4 8 7 9 3 5 1
6 3
1 3 3 2 7 3

Sample Output
1 1 3 
3 4 5 
7 8 9 



*/