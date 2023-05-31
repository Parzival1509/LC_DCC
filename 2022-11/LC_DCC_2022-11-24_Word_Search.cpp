// LC DCC 2022/11/24
// 79. Word Search
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
    bool dfs(vector<vector<char>>& board, string &word, int i, int j, int idx) {
        if(idx==word.size())
            return true;
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || word[idx]!=board[i][j])
            return false;
        
        char cur = board[i][j];
        board[i][j] = '*';
        bool ans = dfs(board, word, i+1, j, idx+1) || dfs(board, word, i-1, j, idx+1) || dfs(board, word, i, j+1, idx+1) || dfs(board, word, i, j-1, idx+1);
        board[i][j] = cur;
        return ans;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        bool ans = 0;
        for(int i=0; i<board.size(); i++)
            for(int j=0; j<board[0].size(); j++)
                if(board[i][j]==word[0])
                    ans |= dfs(board, word, i, j, 0);
        
        return ans;
    }
};

// // Baijnath's Sol
// class Solution {
// public:
// vector<pair<int,int> > dir={{0,1},{1,0},{0,-1},{-1,0}};
//     bool isvalid(int x, int y, vector<vector<char>>& board, string word, int n, int m , int k){
//         if(k>=word.size())
//             return true;
//         if(x<0 || y<0 || x>=n ||  y>=m|| board[x][y]=='.'||word[k]!=board[x][y] )
//             return false;
//         if(word.size()==1 && word[k]==board[x][y])
//             return true;
        
//         board[x][y]='.';
//         bool temp=false;
//         for(auto ele:dir) {
//             int f=ele.first;
//             int s=ele.second;
//             temp=temp|| isvalid(x+f, y+s, board, word, n, m, k+1);
//         }
//         board[x][y]=word[k];
//         return temp;
//     }
    
//     bool exist(vector<vector<char>>& board, string word) {
//         int n=board.size();
//         if(n==0)return false;
//         int m=board[0].size();
//         if(word.size()==0)return false;
//         for(int i=0;i<n;i++)
//             for(int j=0;j<m;j++)
//                 if(word[0]==board[i][j])
//                     if(isvalid(i, j, board, word, n, m, 0))
//                         return true;

//         return false;
//     }
// };

int main(){
    Solution ob;
    int t;
    cin>>t;
    while(t--){
        int m, n;
        cin>>m>>n;
        vector<vector<char>> board(m, vector<char> (n, ' '));
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                cin>>board[i][j];

        string word;
        cin>>word;
        cout<<ob.exist(board, word)<<endl;
    }
    return 0;
}

/* Sample Input
3
3 4
abce
sfcs
adee
abcced
3 4
abce
sfcs
adee
see
3 4
abce
sfcs
adee
abcb

Sample Output
3
2

*/