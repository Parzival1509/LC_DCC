// LC DCC 2023/12/19
// 661. Image Smoother
// Easy

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int smoothen(vector<std::vector<int>>& img, int x, int y) {
        int m = img.size(), n = img[0].size();
        int sum = 0, ct = 0;

        for(int i = -1; i <= 1; ++i)
            for(int j = -1; j <= 1; ++j) {
                int nx = x + i;
                int ny = y + j;
                if(nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    sum += img[nx][ny];
                    ++ct;
                }
            }

        return sum / ct;
    }
    
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        vector<vector<int>> res(m, vector<int> (n, 0));

        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                res[i][j] = smoothen(img, i, j);

        return res;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int m, n;
        cin >> m >> n;
        vector<vector<int>> img(m, vector<int> (n, 0));
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                cin >> img[i][j];

        vector<vector<int>> ans = ob.imageSmoother(img);
        for(auto r: ans) {
            for(int e: r)
                cout << e << ' ';
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}

/* Sample Input:
2
3 3
1 1 1
1 0 1
1 1 1
3 3
100 200 100
200 50 200
100 200 100

Sample Output:
0 0 0 
0 0 0 
0 0 0 

137 141 137 
141 138 141 
137 141 137 


*/