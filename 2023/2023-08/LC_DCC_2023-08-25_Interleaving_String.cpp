// LC DCC 2023/08/25
// 97. Interleaving String
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size();
        if(s3.length() != n + m)
            return false;
        
        bool table[n + 1][m + 1];
        
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= m; j++) {
                if(i == 0 && j == 0)
                    table[i][j] = true;
                else if(i == 0)
                    table[i][j] = (table[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
                else if(j == 0)
                    table[i][j] = (table[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
                else
                    table[i][j] = (table[i - 1][j] && s1[i - 1] == s3[i + j - 1] ) || (table[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
            
        return table[n][m];
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        if(ob.isInterleave(s1, s2, s3)) cout<<"true ";
        else cout<<"false ";
        cout<<endl;
    }

    return 0;
}

/* Sample Input:
2
aabcc dbbca aadbbcbcac
aabcc dbbca aadbbbaccc

Sample Output:
true
false

*/