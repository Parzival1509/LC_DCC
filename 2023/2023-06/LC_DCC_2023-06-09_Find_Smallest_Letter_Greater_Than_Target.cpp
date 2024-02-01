// LC DCC 2023/06/09
// 744. Find Smallest Letter Greater Than Target
// Easy

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        // // Approach 1: Linear Search
        // for(auto letter: letters)
        //     if(letter > target) return letter;
        // return letters[0];

        // Approach 2: Binary Search
        int lo = 0, hi = letters.size() - 1;
        while (hi - lo > 1) {
            int mid = (lo + hi) / 2;
            if(letters[mid] <= target) lo = mid + 1;
            else hi = mid;
        }

        if (letters[lo] > target) return letters[lo];
        if (letters[hi] > target) return letters[hi];
        return letters[0];
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        int n;
        cin >> n;
        vector<char> letters(n);
        for(int i = 0; i < n; i++)
            cin >> letters[i];
        getchar();
        char target;
        cin >> target;
        cout << ob.nextGreatestLetter(letters, target) << endl;
    }
    return 0;
}

/* Sample Input:
2
cfj a
cfj c
xxyy z

Sample Output:
c
f
x

*/