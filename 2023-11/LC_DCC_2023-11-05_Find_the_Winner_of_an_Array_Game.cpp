// LC DCC 2023/11/05
// 1535. Find the Winner of an Array Game
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        if(n <= k) return *max_element(arr.begin(), arr.end());

        int current_winner = arr[0], consecutive_wins = 0;
        for(int i = 1; i < n; ++i) {
            if(current_winner > arr[i])
                consecutive_wins++;
            else {
                current_winner = arr[i];
                consecutive_wins = 1;
            }

            if(consecutive_wins == k)
                return current_winner;
        }

        return current_winner;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n, 0);
        for(int &i: arr)
            cin >> i;
        cout << ob.getWinner(arr, k) << endl;
    }

    return 0;
}

/* Sample Input:
2
7 2
2 1 3 5 4 6 7
3 10
3 2 1

Sample Output:
5
3

*/