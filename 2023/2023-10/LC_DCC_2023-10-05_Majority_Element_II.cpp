// LC DCC 2023/10/05
// 229. Majority Element II
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // // Approach 1: Using map, T.C. = O(N*log(N)), S.C. = O(N)
        // int n = nums.size();
        
        // map<int, int> hsh;
        // for(int i = 0; i < n; i++)
        //     hsh[nums[i]]++;

        // vector<int> ans;
        // for(auto i: hsh)
        //     if(i.second > n / 3)
        //         ans.push_back(i.first);

        // Approach 2: Finding the possible 2 candidates
        // There can be only at max 2 numbers having count more than (n / 3)

        int candidate1 = 0, candidate2 = 0, ct1 = 0, ct2 = 0;

        // First pass to find potential candidates
        for(auto num: nums) {
            if(candidate1 == num) ct1++;
            else if(candidate2 == num) ct2++;
            else if(ct1 == 0) {
                candidate1 = num;
                ct1 = 1;
            }
            else if (ct2 == 0) {
                candidate2 = num;
                ct2 = 1;
            }
            else {
                ct1--;
                ct2--;
            }
        }

        // Second pass to verify candidates
        ct1 = ct2 = 0;
        for(int num: nums) {
            if(num == candidate1) ct1++;
            else if(num == candidate2)
                ct2++;
        }
        
        vector<int> ans;
        if(ct1 > nums.size() / 3)
            ans.push_back(candidate1);
        if(ct2 > nums.size() / 3)
            ans.push_back(candidate2);

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
        for(auto i: ob.majorityElement(nums))
            cout << i << ' ';
        cout << endl;
    }

    return 0;
}

/* Sample Input:
3
1
1
2
1 2
3
3 2 3

Sample Output:
1 
1 2 
3 

*/