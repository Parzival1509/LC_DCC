// LC DCC 2024/06/05
// 1002. Find Common Characters
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> count(const string& str) {
        vector<int> frequency(26, 0);
        for (char c : str)
            frequency[c - 'a']++;
        
        return frequency;
    }
    
    vector<int> intersection(const vector<int>& a, const vector<int>& b) {
        vector<int> t(26, 0);
        for (int i = 0; i < 26; i++)
            t[i] = min(a[i], b[i]);
        
        return t;
    }
    
    vector<string> commonChars(vector<string>& words) {
        vector<int> last = count(words[0]);
        for (int i = 1; i < words.size(); i++)
            last = intersection(last, count(words[i]));
        
        vector<string> result;
        for (int i = 0; i < 26; i++)
            while (last[i] > 0) {
                result.push_back(string(1, 'a' + i));
                last[i]--;
            }
        
        return result;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while (T--) {
        int n;
        cin >> n;
        vector<string> words(n, "");
        for(auto &i: words)
            cin >> i;
        vector<string> ans = ob.commonChars(words);
        for(auto i: ans)
            cout << i << ' ';
        cout << endl;
    }

    return 0;
}

/* Sample Input
2
3
bella label roller
3
cool lock cook

Sample Output
e l l 
c o 

*/