// LC DCC 2022/11/11
// 26. Remove Duplicates from Sorted Array
// Easy

#include<bits/stdc++.h>
using namespace std;

int start_up(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
int static r = start_up();

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0, j=0;
        for(i=1; i<nums.size(); i++){
            if(nums[i]>nums[j])
                swap(nums[i], nums[++j]);
        }
        return ++j;
    }
};

int main(){
    Solution ob;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> nums(n);
        for(int i=0; i<n; i++)
            cin>>nums[i];
        cout<<ob.removeDuplicates(nums)<<endl;
    }
    return 0;
}

/* Sample Input
2
3
1 1 2
10
0 0 1 1 1 2 2 3 3 4

Sample Output
2
5

*/