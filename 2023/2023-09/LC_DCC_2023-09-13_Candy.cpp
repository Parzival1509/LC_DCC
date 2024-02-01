// LC DCC 2023/09/13
// 135. Candy
// Hard

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n == 1) return 1;

        vector<int> candies(n, 1);

        // First we move right and increase the no. of candies
        for(int i = 1; i < n; i++)
            if(ratings[i] > ratings[i - 1])
                candies[i] = candies[i - 1] + 1;

        // Now we go from right to left, and compare the candies and ratings
        for(int i = n - 2; i >= 0; i--)
            if(ratings[i] > ratings[i + 1])
                candies[i] = max(candies[i + 1] + 1, candies[i]);

        int ans = accumulate(candies.begin(), candies.end(), 0);
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n;
        cin >> n;
        vector<int> ratings(n, 0);
        for(int &i: ratings)
            cin >> i;
        cout << ob.candy(ratings) << endl;
    }

    return 0;
}

/* Sample Input:
2
3
1 0 2
3
1 2 2

Sample Output:
5
4

*/