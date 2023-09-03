// LC DCC 2023/08/01
// 77. Combinations
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        // // Approach 1:
        // vector<vector<int>> result;
        // vector<int> p(k, 0);
        // int i = 0;
        
        // while(i >= 0) {
        //     p[i]++;
        //     if(p[i] > n) --i;
        //     else if(i == k - 1) result.push_back(p);
        //     else {
        //         ++i;
        //         p[i] = p[i - 1];
        //     }
        // }

        // Approach 2: Backtracking
        vector<vector<int>> result;
        vector<int> combination(k);
        generateCombinations(1, n, k, combination, result);

        return result;
    }

    void generateCombinations(int start, int n, int k, vector<int> &combination, vector<vector<int>> &result) {
        if(k == 0) {
            result.push_back(combination);
            return;
        }
        for (int i = start; i <= n; ++i) {
            combination[combination.size() - k] = i;
            generateCombinations(i + 1, n, k - 1, combination, result);
        }
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while(T--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> ans = ob.combine(n, k);

        for(auto i: ans) {
            for(auto e: i)
                cout << e << ' ';
            cout << endl;
        }
        cout << endl;
    }
    
    return 0;
}

/* Sample Input:
2
1 1
4 2

Sample Output:
1 

1 2 
1 3 
1 4 
2 3 
2 4 
3 4 


*/