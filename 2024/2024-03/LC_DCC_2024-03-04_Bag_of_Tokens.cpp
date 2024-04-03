// LC DCC 2024/03/04
// 948. Bag of Tokens
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int n = tokens.size(), left = 0, right = n - 1;
        int score = 0, max_score = 0;

        while (left <= right) {
            if (power >= tokens[left]) {
                power -= tokens[left];
                score += 1;
                left += 1;
                max_score = max(max_score, score);
            } else if (score > 0) {
                power += tokens[right];
                score -= 1;
                right -= 1;
            } else break;
        }

        return max_score;
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        int n, power;
        cin >> n >> power;
        vector<int> tokens(n, 0);
        for(int &i: tokens)
            cin >> i;
        cout << ob.bagOfTokensScore(tokens, power) << endl;
    }

    return 0;
}

/* Sample Input
3
1 50
100
2 150
200 100
4 200
100 200 300 400

Sample Output
0
1
2

*/