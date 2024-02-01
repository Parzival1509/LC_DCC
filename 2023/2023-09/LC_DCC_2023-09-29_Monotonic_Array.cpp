// LC DCC 2023/09/29
// 896. Monotonic Array
// Easy

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        // // Approach 1:
        // bool isIncreasing = true, isDecreasing = true; 
        
        // for(int i = 1; i < nums.size(); i++) {
        //     if(nums[i] > nums[i - 1])
        //         isDecreasing = false;
        //     if(nums[i] < nums[i - 1])
        //         isIncreasing = false;
        // }
        
        // return isIncreasing || isDecreasing;

        // Approach 2:
        int n = nums.size();
        if(n < 3) return true;

        int dir = 0;    // 0 unknown, 1 increasing, -1, decreasing
        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i - 1]) {     // Increasing
                if(dir == 0) dir = 1;
                else if(dir == -1) return false;    // Previously decreasing
            }
            else if(nums[i] < nums[i - 1]) {    // Decreasing
                if(dir == 0) dir = -1;
                else if(dir == 1) return false;     // Previously increasing
            }
        }

        return true;
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
        if(ob.isMonotonic(nums)) cout<<"true ";
        else cout<<"false ";
        cout<<endl;
    }

    return 0;
}

/* Sample Input:
3
4
1 2 2 3
4
6 5 4 4
3
1 3 2

Sample Output:
true 
true 
false 

*/