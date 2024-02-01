// LC DCC 2023/01/01
// 290. Word Pattern
// Easy

#include <bits/stdc++.h>
using namespace std;

// Good T.C.
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> char_map;
        unordered_map<string, char> word_map;
        
        stringstream s(str);
        string word;
        int n = pattern.size(), i = 0;
        
        while(s >> word) {
            if(i == n) return false;
            char c = pattern[i];
            if(char_map.count(c) != word_map.count(word))
                return false;
            if(char_map.count(c)) {
                if((word_map[word] != c) || (char_map[c] != word)) 
                    return false;
            }
            else {
                char_map.insert({c, word});
                word_map.insert({word, c});
            }
            i++;
        }
        return i == n;
    }
};

// // Baijnath's Sol
// class Solution {
// public:
//     bool wordPattern(string pattern, string s) {
//         vector<string> v;
//         string word;
//         stringstream iss(s);
//         while(iss>> word)
//             v.push_back(word);
//         if(v.size() != pattern.size())
//             return false;
        
//         unordered_map<char, string> m;
//         set<string> st;
//         for(int i=0;i<pattern.size();i++)
//             if(m.find(pattern[i]) != m.end()) {
//                 if(m[pattern[i]] != v[i])
//                     return false;
//             }
//             else {
//                 if(st.count(v[i])>0)
//                     return false;
//                 m[pattern[i]] = v[i];
//                 st.insert(v[i]);
//             }
//         return true;
//     }
// };

int main() {
    int T;
    cin>>T;
    Solution ob;
    while(T--) {
        string pattern, s;
        cin>>pattern;
        // char ch;
        // cin>>ch;
        getline(cin, s);
        cout<<ob.wordPattern(pattern, s)<<endl;
    }
    return 0;
}

/* Sample Input
3
abba dog cat cat dog
abba dog cat cat fish
aaaa dog cat cat dog

Sample Output
1
0
0

*/