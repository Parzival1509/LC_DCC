// LC DCC 2023/12/04
// 2264. Largest 3-Same-Digit Number in String
// Easy

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    vector<string> sameDigitNumbers = {"999", "888", "777", "666", "555", "444", "333", "222", "111", "000"};

    bool contains(string sameDigitNumber, string num) {
        for(int i = 0; i <= num.size() - 3; ++i)
            if(num[i] == sameDigitNumber[0] && num[i + 1] == sameDigitNumber[1] && num[i + 2] == sameDigitNumber[2])
                return true;

        return false;
    }

    string largestGoodInteger(string num) {
        for(auto& sameDigitNumber: sameDigitNumbers)
            if(contains(sameDigitNumber, num))
                return sameDigitNumber;

        return "";
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        string num;
        cin >> num;
        cout << ob.largestGoodInteger(num) << endl;
    }

    return 0;
}

/* Sample Input:
3
6777133339
2300019
42352338

Sample Output:
777
000


*/