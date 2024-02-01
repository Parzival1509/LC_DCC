// LC DCC 2023/01/24
// 909. Snakes and Ladders
// Medium

#include<bits/stdc++.h>
using namespace std;

int start_up() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
int static r = start_up();

// Baijnath's Sol
class Solution {
public:
    int n;
    pair<int, int> getCoord(int s) {
        int row = n-1-(s-1)/n;
        int col = (s-1)%n;
        if((n%2==1 && row%2==1) || (n%2==0 && row%2==0))
            col = n-1-col;
        return make_pair(row, col);
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();
        int steps = 0;
        queue<int> que;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[n-1][0] = true;
        que.push(1);
        vector<bool> seen(n*n+1, false);

        while(!que.empty()) {
            int N = que.size();
            while(N--) {
                int x = que.front();
                que.pop();
                if(x == n*n) return steps;

                for(int k = 1; k<=6; k++) {
                    if(x+k > n*n) break;

                    pair<int, int> coord = getCoord(x+k);
                    int r = coord.first, c = coord.second;
                    if(visited[r][c] == true) continue;

                    visited[r][c] = true;
                    if(board[r][c] == -1) que.push(k+x);
                    else que.push(board[r][c]);
                }
            }
            steps++;
        }
        return -1;
    }
};

int main() {
    Solution ob;
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<int>> board(n, vector<int> (n, -1));
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                cin>>board[i][j];
        cout<<ob.snakesAndLadders(board)<<endl;
    }
    return 0;
}

/* Sample Input
3
2
-1 4
-1 3
2
-1 -1
-1 3
6
-1 -1 -1 -1 -1 -1
-1 -1 -1 -1 -1 -1
-1 -1 -1 -1 -1 -1
-1 35 -1 -1 13 -1
-1 -1 -1 -1 -1 -1
-1 15 -1 -1 -1 -1

Sample Output
1
1
4

*/