// LC DCC 2023/08/24
// 68. Text Justification
// Hard

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
private:
    string connect(const vector<string>& words, int maxWidth, int begin, int end, int len, bool is_last) {
        string s;
        int n = end - begin;
        for(int i = 0; i < n; ++i) {
            s += words[begin + i];
            addSpaces(i, n - 1, maxWidth - len, is_last, &s);
        }

        if(s.size() < maxWidth)
            s.append(maxWidth - s.size(), ' ');
        
        return s;
    }

    void addSpaces(int i, int spaceCnt, int maxWidth, bool is_last, string *s) {
        if(i < spaceCnt) {
            int spaces = is_last? 1: maxWidth / spaceCnt + (i < maxWidth % spaceCnt);
            s->append(spaces, ' ');
        }
    }

public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        const int n = words.size();
        int begin = 0, len = 0;

        for(int i = 0; i < n; ++i) {
            if(len + words[i].size() + (i - begin) > maxWidth) {
                res.emplace_back(connect(words, maxWidth, begin, i, len, false));
                begin = i;
                len = 0;
            }
            len += words[i].size();
        }
        
        res.emplace_back(connect(words, maxWidth, begin, n, len, true));
        return res;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n, maxWidth;
        cin >> n >> maxWidth;
        vector<string> words(n, "");
        for(auto &i: words)
            cin >> i;
        vector<string> ans = ob.fullJustify(words, maxWidth);
        for(auto i: ans)
            cout << i << endl;
        cout << endl;
    }

    return 0;
}

/* Sample Input:
3

7 16
This is an example of text justification.

6 16
What must be acknowledgement shall be

18 20
Science is what we understand well enough to explain to a computer. Art is everthing else we do


Sample Output:
This    is    an
example  of text
justification.  

What   must   be
acknowledgement 
shall be        

Science  is  what we
understand      well
enough to explain to
a  computer.  Art is
everthing else we do


*/