// LC DCC 2023/10/12
// 1095. Find in Mountain Array
// Hard

#include <bits/stdc++.h>
using namespace std;

#define ll long long

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
*/

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int start = 0, end = mountainArr.length() - 1;
        int mid = (start + end) / 2;

        // Finding the Peak
        while(start < end) {
            if(mountainArr.get(mid) < mountainArr.get(mid + 1))
                start = mid + 1;
            else end = mid;
            mid = (start + end) / 2;
        }

        int peak = mid, left = -1, right = -1;

        // Searching the left part
        start = 0;
        end = peak;
        mid = (start + end) / 2;

        while(start <= end) {
            int middle = mountainArr.get(mid);
            if(middle == target)
                left = mid;
            if(middle < target )
                start = mid + 1;
            else end = mid - 1;

            mid = (start + end) / 2;
        }
        
        // Searching the right part
        start = peak;
        end = mountainArr.length() - 1;
        mid = (start + end) / 2;
        while(start <= end) {
            int middle = mountainArr.get(mid);
            if(middle == target)
                right = mid;
            if(middle > target )
                start = mid + 1;
            else end = mid - 1;

            mid = (start + end) / 2;
        }

        if(left == right || left != -1) return left;
        
        return right; 
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        
    }

    return 0;
}

/* Sample Input:


Sample Output:


*/