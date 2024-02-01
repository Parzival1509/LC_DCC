// LC DCC 2022/11/18
// 263. Ugly Number
// Easy

#include<bits/stdc++.h>
using namespace std;

int start_up(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
int static r = start_up();

class Solution {
public:
    bool isUgly(int n) {
        if(n<=0) return false;
        while(n%5==0) n/=5;
        while(n%3==0) n/=3;
        while(n%2==0) n/=2;
        if(n==1) return true;
        return false;
    }
};


int main(){
    Solution ob;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<ob.isUgly(n)<<endl;
    }
    return 0;
}

/* Sample Input
4
6
1
14
-2147483648

Sample Output
1
1
0
0

*/