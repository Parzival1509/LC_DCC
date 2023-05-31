// LC DCC 2022/11/23
// 36. Valid Sudoku
// Medium

#include<bits/stdc++.h>
using namespace std;

int start_up(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
int static r = start_up();
bool cmp(pair<string, int> A, pair<string, int> B){
    if(A.first != B.first)
        return A.second < B.second;
    return B.first > A.first;
}

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int used1[9][9]={0}, used2[9][9]={0}, used3[9][9]={0};
        
        for(int i=0; i<board.size(); i++)
            for(int j=0; j<board[i].size(); j++)
                if(board[i][j] != '.') {
                    int num = board[i][j]-'0'-1, k=(i/3)*3+(j/3);
                    if(used1[i][num] || used2[j][num] || used3[k][num])
                        return false;
                    used1[i][num] = used2[j][num] = used3[k][num] = 1;
                }
        return true;
    }
};

int main(){
    Solution ob;
    int t;
    cin>>t;
    while(t--){
        int m, n;
        cin>>m>>n;
        vector<vector<char>> board(m, vector<char> (n, '.'));
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                cin>>board[i][j];
        cout<<ob.isValidSudoku(board)<<endl;
    }
    return 0;
}

/* Sample Input
2
9 9
5 3 . . 7 . . . .
6 . . 1 9 5 . . .
. 9 8 . . . . 6 .
8 . . . 6 . . . 3
4 . . 8 . 3 . . 1
7 . . . 2 . . . 6
. 6 . . . . 2 8 .
. . . 4 1 9 . . 5
. . . . 8 . . 7 9
9 9
8 3 . . 7 . . . .
6 . . 1 9 5 . . .
. 9 8 . . . . 6 .
8 . . . 6 . . . 3
4 . . 8 . 3 . . 1
7 . . . 2 . . . 6
. 6 . . . . 2 8 .
. . . 4 1 9 . . 5
. . . . 8 . . 7 9

Sample Output
1
0

*/