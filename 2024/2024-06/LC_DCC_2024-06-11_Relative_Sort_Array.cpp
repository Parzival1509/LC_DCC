// LC DCC 2024/06/11
// 1122. Relative Sort Array
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int maxElement = *max_element(arr1.begin(), arr1.end());
        vector<int> count(maxElement + 1);

        for (int element : arr1)
            count[element]++;

        vector<int> result;
        for (int element : arr2)
            while (count[element] > 0) {
                result.push_back(element);
                count[element]--;
            }

        for (int num = 0; num <= maxElement; num++)
            while (count[num] > 0) {
                result.push_back(num);
                count[num]--;
            }

        return result;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while (T--) {
        int m, n;
        cin >> m >> n;
        vector<int> arr1(m, 0);
        for(int &i: arr1)
            cin >> i;
        vector<int> arr2(n, 0);
        for(int &i: arr2)
            cin >> i;
        vector<int> ans = ob.relativeSortArray(arr1, arr2);
        for(int i: ans)
            cout << i << ' ';
        cout << endl;
    }

    return 0;
}

/* Sample Input
2
11 6
2 3 1 3 2 4 6 7 9 2 19
2 1 4 3 9 6
6 4
28 6 22 8 44 17
22 28 8 6

Sample Output
2 2 2 1 4 3 3 9 6 7 19 
22 28 8 6 17 44 

*/