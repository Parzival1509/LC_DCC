// LC DCC 2023/10/01
// 557. Reverse Words in a String III
// Easy

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    string reverseWords(string s) {
        string ans = "", tmp = "";
        int n = s.size();

        // // Approach 1:

        // for(int i = 0; i <= n; i++) {
        //     if(s[i] == ' ' || i == n) {
        //         if(ans.size() != 0)
        //             ans += " ";
        //         ans += tmp;
        //         tmp = "";
        //     }
        //     else tmp = s[i] + tmp;
        // }

        // return ans;
        
        // Approach 2: Using stringstream
        stringstream ss(s);

        while(ss >> tmp) {
            reverse(tmp.begin(), tmp.end());
            ans += tmp + " ";
        }
        
        return ans.substr(0, n);
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        string s;
        getchar();
        getline(cin, s);
        cout << ob.reverseWords(s) << endl;
    }

    return 0;
}

/* Sample Input:
3
Let's take LeetCode contest
God Ding
hehhhhhhe

Sample Output:
s'teL ekat edoCteeL tsetnoc
do gniD
ehhhhhhe

*/