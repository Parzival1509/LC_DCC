// LC DCC 2023/03/01
// 912. Sort an Array
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    void merge(int l, int r, int mid, vector<int> &nums) {
        int ls = mid-l+1, rs = r-mid;
        
        int L[ls+1], R[rs+1];
        for(int i=0; i<ls; i++)
            L[i] = nums[i+l];
        for(int i=0; i<rs; i++)
            R[i] = nums[i+mid+1];

        L[ls] = R[rs] = INT_MAX;
        int li = 0, ri = 0;

        for(int i=l; i<=r; i++)
            if(L[li] <= R[ri])
                nums[i] = L[li++];
            else
                nums[i] = R[ri++];
    }

    void mergeSort(int l, int r, vector<int> &nums) {
        if(l == r) return;
        int mid = (l+r)/2;
        mergeSort(l, mid, nums);
        mergeSort(mid+1, r, nums);
        merge(l, r, mid, nums);
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(0, n-1, nums);
        return nums;
    }
};

int main() {
    Solution ob;
    int T = 1;
    cin>>T;
    while(T--) {
        int n;
        cin>>n;
        vector<int> nums(n);
        for(int i=0; i<n; i++)
            cin>>nums[i];
        vector<int> ans = ob.sortArray(nums);
        for(int el: ans)
            cout<<el<<' ';
        cout<<endl;
    }
    return 0;
}

/* Sample Input:
2
4
5 2 3 1
6
5 1 1 2 0 0

Sample Output:
1 2 3 5 
0 0 1 1 2 5 

*/