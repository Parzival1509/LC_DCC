// LC DCC 2025/01/22
// 1765. Map of Highest Peak
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidCell(pair<int, int> cell, int rows, int columns) {
        return cell.first >= 0 && cell.second >= 0 && cell.first < rows && cell.second < columns;
    }

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        int rows = isWater.size(), columns = isWater[0].size();

        vector<vector<int>> cellHeights(rows, vector<int>(columns, -1));
        queue<pair<int, int>> cellQueue;

        for (int x = 0; x < rows; x++) {
            for (int y = 0; y < columns; y++) {
                if (isWater[x][y]) {
                    cellQueue.push({x, y});
                    cellHeights[x][y] = 0;
                }
            }
        }

        int heightOfNextLayer = 1;
        while (!cellQueue.empty()) {
            int layerSize = cellQueue.size();

            for (int i = 0; i < layerSize; i++) {
                pair<int, int> currentCell = cellQueue.front();
                cellQueue.pop();

                for (int d = 0; d < 4; d++) {
                    pair<int, int> neighborCell = {currentCell.first + dx[d], currentCell.second + dy[d]};

                    if (isValidCell(neighborCell, rows, columns) && cellHeights[neighborCell.first][neighborCell.second] == -1) {
                        cellHeights[neighborCell.first][neighborCell.second] = heightOfNextLayer;
                        cellQueue.push(neighborCell);
                    }
                }
            }

            heightOfNextLayer++;
        }

        return cellHeights;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while (T--) {
        int m, n;
        cin >> m >> n;
        vector<vector<int>> isWater(m, vector<int> (n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> isWater[i][j];
            }
        }

        vector<vector<int>> ans = ob.highestPeak(isWater);
        for(auto row: ans) {
            for(int e: row) {
                cout << e << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}

/* Sample Input
2

2 2
0 1
0 0

3 3
0 0 1
1 0 0
0 0 0

Sample Output
1 0 
2 1 

1 1 0 
0 1 1 
1 2 2 


*/