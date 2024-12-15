// LC DCC 2024/07/02
// 350. Intersection of Two Arrays II
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int i = 0, j = 0;
        vector<int> result;
        
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j])
                i++;
            else if (nums1[i] > nums2[j])
                j++;
            else {
                result.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        
        return result;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while (T--) {
        int m, n;
        cin >> m >> n;
        vector<int> nums1(m, 0), nums2(n, 0);
        for(int &i: nums1)
            cin >> i;
        for(int &i: nums2)
            cin >> i;
        vector<int> ans = ob.intersect(nums1, nums2);
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
2 2 
4 9 

*/