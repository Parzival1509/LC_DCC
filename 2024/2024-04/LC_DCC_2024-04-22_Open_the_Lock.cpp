// LC DCC 2024/04/22
// 752. Open the Lock
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadendSet(deadends.begin(), deadends.end());
        if (deadendSet.count("0000"))
            return -1;
        
        queue<pair<string, int>> queue;
        queue.push({"0000", 0});
        unordered_set<string> visited;
        visited.insert("0000");
        
        while (!queue.empty()) {
            auto current = queue.front();
            queue.pop();
            string currentCombination = current.first;
            int moves = current.second;
            
            if (currentCombination == target)
                return moves;
            
            for (int i = 0; i < 4; i++) {
                for (int delta : {-1, 1}) {
                    int newDigit = (currentCombination[i] - '0' + delta + 10) % 10;
                    string newCombination = currentCombination;
                    newCombination[i] = '0' + newDigit;
                    
                    if (visited.find(newCombination) == visited.end() && deadendSet.find(newCombination) == deadendSet.end()) {
                        visited.insert(newCombination);
                        queue.push({newCombination, moves + 1});
                    }
                }
            }
        }
        
        return -1;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while (T--) {
        int n;
        string target;
        cin >> n >> target;

        vector<string> deadends(n, " ");
        for(auto &i: deadends)
            cin >> i;

        cout << ob.openLock(deadends, target) << endl;
    }

    return 0;
}

/* Sample Input
3
5 0202
0201 0101 0102 1212 2002
1 0009
8888
8 8888
8887 8889 8878 8898 8788 8988 7888 9888

Sample Output
6
1
-1

*/