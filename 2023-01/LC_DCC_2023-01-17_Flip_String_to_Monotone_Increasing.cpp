// LC DCC 2023/01/17
// 926. Flip String to Monotone Increasing
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int ones = 0, ans = 0;
        for(int i=0; i<s.size(); i++)
            if(s[i] == '1') ones++;
            else ans = min(ones, ans+1);
        return ans;
    }
};

int main() {
    int T;
    cin>>T;
    Solution ob;
    while(T--) {
        string s;
        cin>>s;
        cout<<ob.minFlipsMonoIncr(s)<<endl;
    }
    return 0;
}

/* Sample Input
3
00110
010110
00011000

Sample Output
1
2
2

*/