// LC DCC 2024/04/11
// 402. Remove K Digits
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.length() == k)
            return "0";

        string ans;
        vector<char> stack;
        for (int i = 0; i < num.length(); ++i) {
            while (k > 0 && !stack.empty() && stack.back() > num[i]) {
                stack.pop_back();
                --k;
            }
            stack.push_back(num[i]);
        }

        while (k-- > 0)
            stack.pop_back();

        for (char c : stack) {
            if (c == '0' && ans.empty())
                continue;
            ans += c;
        }

        return ans.empty() ? "0" : ans;
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        int k;
        string num;
        cin >> num >> k;
        cout << ob.removeKdigits(num, k) << endl;
    }

    return 0;
}

/* Sample Input
3
1432219 3
10200 1
10 2

Sample Output
1219
200
0

*/