// LC DCC 2023/05/23
// 703. Kth Largest Element in a Stream
// Easy

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> k_largest;
    int k;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(auto& num: nums)
            add(num);
    }

    int add(int val) {
        k_largest.push(val);
        if(k_largest.size() > k)
            k_largest.pop();
        return k_largest.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
*/

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        
    }
    return 0;
}

/* Sample Input:


Sample Output:


*/