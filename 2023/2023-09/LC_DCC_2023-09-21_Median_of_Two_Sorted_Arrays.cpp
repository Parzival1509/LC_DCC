// LC DCC 2023/09/21
// 4. Median of Two Sorted Arrays
// Hard

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size(), tot = m + n;

        // // Approach 1: Merge and Sort
        // // T.C. = O((m + n) * log(m + n)), S.C. = O(m + n)
        
        // vector<int> merged(nums1.begin(), nums1.end());
        // for(int i = 0; i < n; i++)
        //     merged.push_back(nums2[i]);
        
        // sort(merged.begin(), merged.end());

        // if(tot & 1) return merged[tot / 2];
        // return (merged[tot / 2] + merged[(tot / 2) - 1]) / 2.0;

        // // Approach 2: Two Pointer
        // // T.C. = O(m + n), S.C. = O(1)

        // int i = 0, j = 0, m1 = 0, m2 = 0;
        // for(int k = 0; k <= tot / 2; k++) {
        //     m2 = m1;
            
        //     if(i < m && j < n) {
        //         if(nums1[i] > nums2[j])
        //             m1 = nums2[j++];
        //         else m1 = nums1[i++];
        //     }
        //     else if(i < m)
        //         m1 = nums1[i++];
        //     else m1 = nums2[j++];
        // }

        // if(tot & 1) return m1;
        // return (m1 + m2) / 2.0;

        // Approach 3: Binary Search
        // T.C. = O(log(m + n)), S.C. = O(1)

        if(m > n) return findMedianSortedArrays(nums2, nums1);

        int lo = 0, hi = m;
        int left = (tot + 1) / 2;

        while(lo <= hi) {
            int mid1 = (lo + hi) >> 1;
            int mid2 = left - mid1;

            int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;

            if(mid1 < m) r1 = nums1[mid1];
            if(mid2 < n) r2 = nums2[mid2];

            if(mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
            if(mid2 - 1 >= 0) l2 = nums2[mid2 - 1];

            if(l1 <= r2 && l2 <= r1) {
                if(tot & 1) return max(l1, l2);
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
            else if(l1 > l2) hi = mid1 - 1;
            else lo = mid1 + 1;
        }

        return 0;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int m, n;
        cin >> m >> n;
        vector<int> nums1(m, 0), nums2(n, 0);
        for(int &i: nums1)
            cin >> i;
        for(int &i: nums2)
            cin >> i;
        cout << ob.findMedianSortedArrays(nums1, nums2) << endl;
    }

    return 0;
}

/* Sample Input:
2

2 1
1 3
2

2 2
1 2
3 4

Sample Output:
2
2.5

*/