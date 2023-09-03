// LC DCC 2023/08/14
// 215. Kth Largest Element in an Array
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int num: nums) {
            pq.push(num);
            if(pq.size() > k)
                pq.pop();
        }
        
        return pq.top();
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
        cout << ob.findKthLargest(nums, k) << endl;
    }

    return 0;
}

/* Sample Input:
2
6 2
3 2 1 5 6 4
9 4
3 2 3 1 2 4 5 5 6

Sample Output:
5
4

*/