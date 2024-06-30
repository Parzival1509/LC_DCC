// LC DCC 2024/06/13
// 2037. Minimum Number of Moves to Seat Everyone
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int moves = 0;
        for (int i = 0; i < seats.size(); i++)
            moves += abs(seats[i] - students[i]);

        return moves;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while (T--) {
        int n;
        cin >> n;
        vector<int> seats(n, 0), students(n, 0);
        for(int &i: seats)
            cin >> i;
        for(int &i: students)
            cin >> i;
        cout << ob.minMovesToSeat(seats, students) << endl;
    }

    return 0;
}

/* Sample Input
3
3
3 1 5
2 7 4
4
4 1 5 9
1 3 2 6
4
2 2 6 6
1 3 2 6

Sample Output
4
7
4

*/