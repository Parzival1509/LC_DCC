// LC DCC 2023/10/02
// 2038. Remove Colored Pieces if Both Neighbors are the Same Color
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    bool winnerOfGame(string colors) {
        int a = 0, b = 0;
        for(int i = 1; i < colors.size() - 1; i++)
            if(colors[i] == 'A' && colors[i + 1] == 'A' && colors[i - 1] == 'A')
                a++;
            else if(colors[i] == 'B' && colors[i + 1] == 'B' && colors[i - 1] == 'B')
                b++;

        return a > b;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        string colors;
        cin >> colors;
        if(ob.winnerOfGame(colors)) cout<<"true ";
        else cout<<"false ";
        cout<<endl;
    }

    return 0;
}

/* Sample Input:
3
AAABABB
AA
ABBBBBBBAAA

Sample Output:
true 
false 
false 

*/