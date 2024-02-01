// LC DCC 2022/11/13
// 223. Rectangle Area
// Medium

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
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        return (ax2-ax1)*(ay2-ay1) + (bx2-bx1)*(by2-by1) - 
        max(min(ax2, bx2)-max(ax1, bx1), 0)*max(min(ay2, by2)-max(ay1, by1), 0);
    }
};

int main(){
    Solution ob;
    int t;
    cin>>t;
    while(t--){
        int ax1, ay1, ax2, ay2, bx1, by1, bx2, by2;
        cin>>ax1>>ay1>>ax2>>ay2>>bx1>>by1>>bx2>>by2;
        cout<<ob.computeArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2)<<endl;
    }
    return 0;
}

/* Sample Input
2
-3 0 3 4 0 -1 9 2
-2 -2 2 2 -2 -2 2 2

Sample Output
45
16

*/