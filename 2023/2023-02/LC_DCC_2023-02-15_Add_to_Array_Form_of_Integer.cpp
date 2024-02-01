// LC DCC 2023/02/15
// 989. Add to Array-Form of Integer
// Easy

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        for(int i=num.size()-1; i>=0 && k>0; --i) {
            num[i] += k;
            k = num[i] / 10;
            num[i] %= 10;
        }
        while(k > 0) {
            num.insert(num.begin(), k % 10);
            k /= 10;
        }
        return num;
    }
};

int main() {
    Solution ob;
    int T = 1;
    cin>>T;
    while(T--) {
        int n, k;
        cin>>n>>k;
        vector<int> num(n);
        for(int i=0; i<n; i++)
            cin>>num[i];
        vector<int> ans = ob.addToArrayForm(num, k);
        for(auto i: ans)
            cout<<i<<' ';
        cout<<endl;
    }
    return 0;
}

/* Sample Input:
6
4 34
1 2 0 0
3 181
2 7 4
3 806
2 1 5
5 1
9 9 9 9 9
1 123
0
1 809
6

Sample Output:
1 2 3 4 
4 5 5 
1 0 2 1 
1 0 0 0 0 0 
1 2 3 
8 1 5 

*/