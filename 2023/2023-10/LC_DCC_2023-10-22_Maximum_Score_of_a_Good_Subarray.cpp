// LC DCC 2023/10/22
// 1793. Maximum Score of a Good Subarray
// Hard

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        // // Approach 1: Using Monotonics Stack property
        // int n = nums.size();
        // vector<int> leftBoundary(n, -1), rightBoundary(n, n);
        // stack<int> leftStack, rightStack;
        
        // // Calculate next lower element from the left.
        // for(int i = n - 1; i >= 0; i--) {
        //     while(!leftStack.empty() && nums[leftStack.top()] > nums[i]) {
        //         leftBoundary[leftStack.top()] = i;
        //         leftStack.pop();
        //     }
        //     leftStack.push(i);
        // }
        
        // // Calculate next lower element from the right
        // for(int i = 0; i < n; i++) {
        //     while(!rightStack.empty() && nums[rightStack.top()] > nums[i]) {
        //         rightBoundary[rightStack.top()] = i; 
        //         rightStack.pop();
        //     }
        //     rightStack.push(i);
        // }
        
        // // Calculate the maximum score for good subarrays
        // int maxScore = 0;
        // for(int i = 0; i < n; i++) {
        //     if(leftBoundary[i] < k && rightBoundary[i] > k) {
        //         int subarrayScore = nums[i] * (rightBoundary[i] - leftBoundary[i] - 1);
        //         maxScore = max(maxScore, subarrayScore);
        //     }
        // }
        
        // return maxScore;

        // Approach 2: Using Two Pointers
        int left = k, right = k;
        int min_val = nums[k];
        int max_score = min_val;

        while(left > 0 || right < nums.size() - 1) {
            if(left == 0 || (right < nums.size() - 1 && nums[right + 1] > nums[left - 1]))
                right++;
            else left--;
            
            min_val = min(min_val, min(nums[left], nums[right]));
            max_score = max(max_score, min_val * (right - left + 1));
        }
        
        return max_score;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n, 0);
        for(int &i: nums)
            cin >> i;
        cout << ob.maximumScore(nums, k) << endl;
    }

    return 0;
}

/* Sample Input:
2
6 3
1 4 3 7 4 5
8 0
5 5 4 5 4 1 1 1

Sample Output:
15
20

*/