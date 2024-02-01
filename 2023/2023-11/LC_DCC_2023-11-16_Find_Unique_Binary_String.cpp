// LC DCC 2023/11/16
// 1980. Find Unique Binary String
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string result;
        for(int i = 0; i < nums.size(); ++i)
            result += (nums[i][i] == '0'? '1': '0');

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
        vector<string> nums(n, "");
        for(string &i: nums)
            cin >> i;
        cout << ob.findDifferentBinaryString(nums) << endl;
    }

    return 0;
}

/* Sample Input:
3
2
01 10
2
00 01
3
111 011 001

Sample Output:
11
10
000

*/