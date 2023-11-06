// LC DCC 2023/10/19
// 844. Backspace String Compare
// Easy

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    string solve(string str) {
        stack<char> s;
        string a = "";
        for(int i = 0; i < str.size(); i++) {
            if(!s.empty() && str[i] == '#')
                s.pop();
            else if(str[i] != '#')
                s.push(str[i]);
        }

        while(!s.empty()) {
            a += s.top();
            s.pop();
        }

        return a;
    }

    int get_next_valid_char_index(string str, int end) {
        int backspace_count = 0;
        while(end >= 0) {
            if(str[end] == '#')
                backspace_count++;
            else if(backspace_count > 0)
                backspace_count--;
            else break;
            
            end--;
        }

        return end;
    }

    bool backspaceCompare(string s, string t) {
        // // Approach 1: Stack, S.C. = O(max(s, t))
        // string a = solve(s);
        // string b = solve(t);
        // return a == b;

        // Appraoch 2: Using Pointers, S.C. = O(1)
        int ps = s.length() - 1;
        int pt = t.length() - 1;

        while(ps >= 0 || pt >= 0) {
            ps = get_next_valid_char_index(s, ps);
            pt = get_next_valid_char_index(t, pt);

            if(ps < 0 && pt < 0)
                return true;
            if(ps < 0 || pt < 0)
                return false;
            else if(s[ps] != t[pt])
                return false;

            ps--;
            pt--;
        }

        return true;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        string s, t;
        cin >> s >> t;
        if(ob.backspaceCompare(s, t)) cout << "true ";
        else cout << "false ";
        cout << endl;
    }

    return 0;
}

/* Sample Input:
4
ab#c ad#c
ab## c#d#
a#c b
y#fo##f y#f#o##f

Sample Output:
true 
true 
false 
true 

*/