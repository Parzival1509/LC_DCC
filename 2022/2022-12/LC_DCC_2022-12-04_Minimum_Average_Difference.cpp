// LC DCC 2022/12/04
// 2256. Minimum Average Difference
// Medium

#include<bits/stdc++.h>
using namespace std;

int start_up(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
int static r = start_up();

// Baijnath's Sol
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n=nums.size(), ans = 0, minDiff = INT_MAX;
        long prefix = 0, suffix = accumulate(begin(nums), end(nums), 0L);

        for(int i = 0; i < nums.size(); ++i) {
            prefix += nums[i];
            suffix -= nums[i];
            int prefixAvg = prefix / (i + 1);
            int suffixAvg = (i == n - 1) ? 0 : suffix / (n - i - 1);
            int diff = abs(prefixAvg - suffixAvg);
            if(diff < minDiff) {
                ans = i;
                minDiff = diff;
            }
        }
        return ans;  
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
        cout<<ob.minimumAverageDifference(nums)<<endl;
    }
    return 0;
}

/* Sample Input
2
1
0
6
2 5 3 9 5 3

Sample Output
0
3

*/