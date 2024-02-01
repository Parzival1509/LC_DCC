// LC DCC 2024/01/02
// 2610. Convert an Array Into a 2D Array With Conditions
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<int> frequency(nums.size() + 1);
        
        vector<vector<int>> result;
        for(int num: nums) {
            if(frequency[num] >= result.size())
                result.push_back({});
            
            result[frequency[num]].push_back(num);
            frequency[num]++;
        }
        
        return result;
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
        vector<vector<int>> ans = ob.findMatrix(nums);
        for(auto v: ans) {
            for(int i: v)
                cout << i << ' ';
            cout << endl;
        }

        cout << endl;
    }

    return 0;
}

/* Sample Input:
2
7
1 3 4 1 2 3 1
4
1 2 3 4

Sample Output:
1 3 4 2 
1 3 
1 

1 2 3 4 


*/