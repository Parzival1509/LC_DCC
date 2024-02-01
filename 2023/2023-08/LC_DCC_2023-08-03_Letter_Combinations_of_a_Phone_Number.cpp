// LC DCC 2023/08/03
// 17. Letter Combinations of a Phone Number
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    vector<string> hash = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void helper(vector<string> &ans, string digits, int d, string tmp) {
        if(d == digits.size()) {
            ans.push_back(tmp);
            return;
        }

        int key = digits[d] - '0' - 2;
        for(char ch: hash[key]) {
            tmp.push_back(ch);
            helper(ans, digits, d + 1, tmp);
            tmp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits == "") return {};

        vector<string> ans;
        helper(ans, digits, 0, "");
        return ans;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while(T--) {
        string digits;
        cin >> digits;
        vector<string> combinations = ob.letterCombinations(digits);
        for(auto el: combinations)
            cout << el << ' ';
        cout << endl;
    }
    
    return 0;
}

/* Sample Input:
3

2
23
234

Sample Output:
a b c 
ad ae af bd be bf cd ce cf 
adg adh adi aeg aeh aei afg afh afi bdg bdh bdi beg beh bei bfg bfh bfi cdg cdh cdi ceg ceh cei cfg cfh cfi 

*/