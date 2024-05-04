// LC DCC 2024/04/03
// 79. Word Search
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    vector<pair<int, int>> del = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};

    bool solve(int i, int j, int ind, string& word, vector<vector<char>>& board, int n, int m) {
        if (ind >= word.size())
            return true;
        
        if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] != word[ind] ||
            board[i][j] == '*')
            return false;

        if (word.size() == 1 && word[ind] == board[i][j])
            return true;

        char ch = board[i][j];
        board[i][j] = '*';
        bool temp = false;

        for (auto ele : del) {
            int x = ele.first;
            int y = ele.second;
            temp = temp || solve(i + x, j + y, ind + 1, word, board, n, m);
        }
        board[i][j] = ch;

        return temp;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        int ind = 0;

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (word[0] == board[i][j])
                    if (solve(i, j, ind, word, board, n, m))
                        return true;

        return false;
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    // getchar();
    while(t--) {
        int m, n;
        string word;
        cin >> m >> n >> word;
        vector<vector<char>> board(m, vector<char> (n, ' '));
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                cin >> board[i][j];

        if(ob.exist(board, word)) cout << "true\n";
        else cout << "false\n";
    }

    return 0;
}

/* Sample Input
3

3 4 ABCCED
ABCE
SFCS
ADEE

3 4 SEE
ABCE
SFCS
ADEE

3 4 ABCB
ABCE
SFCS
ADEE

Sample Output
true
true
false

*/