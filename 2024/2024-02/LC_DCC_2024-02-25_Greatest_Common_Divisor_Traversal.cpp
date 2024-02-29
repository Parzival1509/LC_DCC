// LC DCC 2024/02/25
// 2709. Greatest Common Divisor Traversal
// Hard

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int, vector<int>> prime2index, index2prime;

    void dfs(int index, vector<int>& visitedIndex, unordered_map<int, bool>& visitedPrime) {
        if (visitedIndex[index] == true)
            return;

        visitedIndex[index] = true;
        for (auto& prime : index2prime[index]) {
            if (visitedPrime[prime] == true)
                continue;
            visitedPrime[prime] = true;
            for (auto& index1 : prime2index[prime]) {
                if (visitedIndex[index1] == true)
                    continue;
                dfs(index1, visitedIndex, visitedPrime);
            }
        }
    }

    bool canTraverseAllPairs(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int temp = nums[i];
            for (int j = 2; j * j <= nums[i]; j++)
                if (temp % j == 0) {
                    prime2index[j].push_back(i);
                    index2prime[i].push_back(j);
                    while (temp % j == 0)
                        temp /= j;
                }
            
            if (temp > 1) {
                prime2index[temp].push_back(i);
                index2prime[i].push_back(temp);
            }
        }

        vector<int> visitedIndex(nums.size(), 0);
        unordered_map<int, bool> visitedPrime;
        dfs(0, visitedIndex, visitedPrime);

        for (int i = 0; i < visitedIndex.size(); i++)
            if (visitedIndex[i] == false)
                return false;
        
        return true;
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> nums(n, 0);
        for(int &i: nums)
            cin >> i;
        if(ob.canTraverseAllPairs(nums)) cout << "true\n";
        else cout << "false\n";
        ob.prime2index.clear();
        ob.index2prime.clear();
    }

    return 0;
}

/* Sample Input
3
3
2 3 6
3
3 9 5
4
4 3 12 8

Sample Output
true
false
true

*/