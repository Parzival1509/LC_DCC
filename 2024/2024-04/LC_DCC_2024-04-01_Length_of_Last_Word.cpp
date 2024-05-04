// LC DCC 2024/04/01
// 58. Length of Last Word
// Easy

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ' ' && count == 0)
                continue;
            if (s[i] == ' ' && count != 0)
                break;
            if (s[i] != ' ')
                count++;
        }
        
        return count;
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    getchar();
    while(t--) {
        string s;
        getline(cin, s);
        cout << ob.lengthOfLastWord(s) << endl;
    }

    return 0;
}

/* Sample Input
3
Hello World
   fly me   to   the moon  
luffy is still joyboy

Sample Output
5
4
6

*/