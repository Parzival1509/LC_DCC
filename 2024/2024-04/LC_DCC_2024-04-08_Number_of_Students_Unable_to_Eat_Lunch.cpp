// LC DCC 2024/04/08
// 1700. Number of Students Unable to Eat Lunch
// Easy

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        vector<int> counts(2, 0);
        for (int student : students)
            counts[student]++;

        int remaining = sandwiches.size();
        for (int sandwich : sandwiches) {
            if (counts[sandwich] == 0 || remaining == 0)
                break;
            counts[sandwich]--;
            remaining--;
        }

        return remaining;
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> students(n, 0), sandwiches(n, 0);
        for(int &i: students)
            cin >> i;
        for(int &i: sandwiches)
            cin >> i;

        cout << ob.countStudents(students, sandwiches) << endl;
    }

    return 0;
}

/* Sample Input
2
4
1 1 0 0
0 1 0 1
6
1 1 1 0 0 1
1 0 0 0 1 1

Sample Output
0
3

*/