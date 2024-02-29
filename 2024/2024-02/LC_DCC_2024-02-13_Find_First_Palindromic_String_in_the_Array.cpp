// LC DCC 2024/02/13
// 2108. Find First Palindromic String in the Array
// Easy

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while(left <= right)
            if(s[left++] != s[right--])
                return false;
        
        return true;
    }
        
    string firstPalindrome(vector<string>& words) {
        string ans = "";
        for(auto s: words)
            if(isPalindrome(s)) {
                ans = s;
                break;
            }

        return ans;
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<string> words(n, "");
        for(auto &i: words)
            cin >> i;
        cout << ob.firstPalindrome(words) << endl;
    }

    return 0;
}

/* Sample Input
3
5
abc car ada racecar cool
2
notapalindrome racecar
2
def ghi

Sample Output
ada
racecar


*/