// LC DCC 2023/05/05
// 1456. Maximum Number of Vowels in a Substring of Given Length
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    bool check(char ch) {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;
        return false;
    }

    int maxVowels(string s, int k) {
        int ct = 0, i = 0, j = 0, ans = 0;

        while(j < s.size()) {
            if(j - i < k) {
                if(check(s[j])) ct++;
                j++;
            }
            else {
                if(check(s[i])) ct--;
                i++;
            }
            if(ct == k) return k;
            ans = max(ans, ct);
        }

        return ans;
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        string s;
        int k;
        cin>>s>>k;
        cout<<ob.maxVowels(s, k)<<endl;
    }
    return 0;
}

/* Sample Input:
4
abciiidef 3
aeiou 2
leetcode 3
zpuerktejfp 3

Sample Output:
3
2
2
2

*/