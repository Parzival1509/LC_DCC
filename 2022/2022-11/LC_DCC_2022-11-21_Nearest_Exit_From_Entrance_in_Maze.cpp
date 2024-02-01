// LC DCC 2022/11/21
// 1926. Nearest Exit from Entrance in Maze
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

// Baijnath's Sol
class Solution {
public:
    bool isvalid(int n,int m,int row,int col){
        if(row>=0 and row<n and col>=0 and col<m)
            return true;
        return false;
    }
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n=maze.size();
        int m=maze[0].size();
        queue<pair<int,int>>q;
        q.push({entrance[0],entrance[1]});  
        maze[entrance[0]][entrance[1]]='+';
        int steps = 0;
        
        while(!q.empty()) {
            int size = q.size();
            while(size--){
                pair<int,int>p = q.front();
                q.pop();
                int i = p.first, j = p.second;
              
                if((i==0 or j==0 or i==n-1 or j==m-1))
                    if((i!=entrance[0] or j!=entrance[1]))
                        return steps;

                if(isvalid(n,m,i+1,j)==true && maze[i+1][j]!='+'){
                    maze[i+1][j]='+';
                    q.push({i+1,j});
                }
                if(isvalid(n,m,i-1,j)==true && maze[i-1][j]!='+'){
                    maze[i-1][j]='+';
                    q.push({i-1,j});
                }
                if(isvalid(n,m,i,j+1)==true && maze[i][j+1]!='+'){
                    maze[i][j+1]='+';
                    q.push({i,j+1});
                }
                if(isvalid(n,m,i,j-1)==true && maze[i][j-1]!='+'){
                    maze[i][j-1]='+';
                    q.push({i,j-1});
                }
            }
            steps++;
        }
        return -1;
    }
};

int main(){
    Solution ob;
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        cout<<ob.calculate(s)<<endl;
    }
    return 0;
}

/* Sample Input
3
[["+","+",".","+"],[".",".",".","+"],["+","+","+","."]]
[1,2]
[["+","+","+"],[".",".","."],["+","+","+"]]
[1,0]
[[".","+"]]
[0,0]

Sample Output
45
16

*/