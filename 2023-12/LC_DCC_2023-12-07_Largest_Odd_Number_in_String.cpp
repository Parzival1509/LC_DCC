// LC DCC 2023/12/07
// 1903. Largest Odd Number in String
// Easy

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size(), i = n - 1;
        for(; i >= 0; i--)
            if((num[i] - '0') & 1)
                break;

        return num.substr(0, i + 1);
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        string num;
        cin >> num;
        cout << ob.largestOddNumber(num) << endl;
    }

    return 0;
}

/* Sample Input:
3
52
4206
35427

Sample Output:
5

35427

*/