// LC DCC 2023/01/03
// 944. Delete Columns to Make Sorted
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& st) {
        int ans=0, n=st.size(), m=st[0].size();
        for(int i=0; i<m; i++)
            for(int j=0; j<n-1; j++)
                if(st[j][i] > st[j+1][i]) {
                    ans++;
                    break;
                }
        return ans;
    }
};

int main() {
    int T;
    cin>>T;
    Solution ob;
    while(T--) {
        int n;
        cin>>n;
        vector<string> st(n);
        for(int i=0; i<n; i++)
            cin>>st[i];
        cout<<ob.minDeletionSize(st)<<endl;
    }
    return 0;
}

/* Sample Input
3
3
cba daf ghi
2
a b
3
zyx wvu tsr

Sample Output
1
0
3

*/