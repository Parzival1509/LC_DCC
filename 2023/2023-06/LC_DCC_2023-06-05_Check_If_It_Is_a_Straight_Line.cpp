// LC DCC 2023/06/05
// 1232. Check If It Is a Straight Line
// Easy

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates.size() < 3) return true;

        int x0 = coordinates[0][0], y0 = coordinates[0][1];
        int x1 = coordinates[1][0], y1 = coordinates[1][1];
        for(int i = 2; i < coordinates.size(); i++) {
            int x = coordinates[i][0];
            int y = coordinates[i][1];
            if((x - x0) * (y1 - y0) != (y - y0) * (x1 - x0))
                return false;
        }

        return true;
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> coordinates(n, vector<int> (2, 0));
        for(int i = 0; i < n; i++)
            cin >> coordinates[i][0] >> coordinates[i][1];
        if(ob.checkStraightLine(coordinates)) cout<<"true ";
        else cout<<"false ";
        cout<<endl;
    }
    return 0;
}

/* Sample Input:
2
6
1 2
2 3
3 4
4 5
5 6
6 7
6
1 1
2 2
3 4
4 5
5 6
7 7

Sample Output:
true 
false 

*/