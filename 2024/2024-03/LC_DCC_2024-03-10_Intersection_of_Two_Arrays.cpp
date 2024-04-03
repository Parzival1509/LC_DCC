// LC DCC 2024/03/10
// 349. Intersection of Two Arrays
// Easy

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int m = nums2.size();
        vector<int> result;
        
        unordered_set<int> mp;
        for (auto& num : nums1)
            mp.insert(num);

        for (auto& num : nums2)
            if (mp.find(num) != mp.end()) {
                result.push_back(num);
                mp.erase(num);
            }
        
        return result;
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<int> nums1(n, 0), nums2(m, 0);
        for(int &i: nums1)
            cin >> i;
        for(int &i: nums2)
            cin >> i;

        vector<int> ans = ob.intersection(nums1, nums2);
        for(int i: ans)
            cout << i << ' ';
        cout << endl;
    }

    return 0;
}

/* Sample Input
2
4 2
1 2 2 1
2 2
3 5
4 9 5
9 4 9 8 4

Sample Output
2 
9 4 

*/