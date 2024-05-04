// LC DCC 2024/04/10
// 950. Reveal Cards In Increasing Order
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());

        int n = deck.size();
        vector<int> result(n);
        deque<int> indices;

        for (int i = 0; i < n; i++)
            indices.push_back(i);

        for (int card : deck) {
            int idx = indices.front();
            indices.pop_front();
            result[idx] = card;
            if (!indices.empty()) {
                indices.push_back(indices.front());
                indices.pop_front();
            }
        }

        return result;
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> deck(n, 0);
        for(int &i: deck)
            cin >> i;
        vector<int> ans = ob.deckRevealedIncreasing(deck);
        for(int i: ans)
            cout << i << ' ';
        cout << endl;
    }

    return 0;
}

/* Sample Input
2
7
17 13 11 2 3 5 7
2
1 1000

Sample Output
2 13 3 11 5 17 7 
1 1000 

*/