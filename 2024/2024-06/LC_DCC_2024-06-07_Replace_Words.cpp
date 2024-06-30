// LC DCC 2024/06/07
// 648. Replace Words
// Medium

#include <bits/stdc++.h>
using namespace std;

class Trie {
public:
    Trie* children[26];
    bool isEnd;

    Trie() {
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
        isEnd = false;
    }
};

class Solution {
public:
    Trie* root;

    Solution() { root = new Trie(); }

    void insert(string word) {
        Trie* node = root;
        for (char c : word) {
            int i = c - 'a';
            if (node->children[i] == nullptr)
                node->children[i] = new Trie();
            node = node->children[i];
        }
        node->isEnd = true;
    }

    string search(string word) {
        Trie* node = root;
        string result;
        for (char c : word) {
            int i = c - 'a';
            if (node->children[i] == NULL)
                return word;
            
            result += c;
            if (node->children[i]->isEnd)
                return result;
            
            node = node->children[i];
        }

        return word;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        for (string word : dictionary)
            insert(word);

        stringstream ss(sentence);
        string word, result;
        while (ss >> word) {
            if (!result.empty())
                result += " ";
            result += search(word);
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
        vector<string> dictionary(n, "");
        for(auto &i: dictionary)
            cin >> i;
        string sentence;
        getchar();
        getline(cin, sentence);
        cout << ob.replaceWords(dictionary, sentence) << endl;
    }

    return 0;
}

/* Sample Input
2
3
cat bat rat
the cattle was rattled by the battery
3
a b c
aadsfasf absbs bbab cadsfafs

Sample Output
the cat was rat by the bat
a a b c

*/