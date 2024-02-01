// LC DCC 2023/03/20
// 605. Can Place Flowers
// Easy

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len = flowerbed.size();
        for(int i=0; i<len; i++) {
            if(flowerbed[i] == 0 && (i == 0 || flowerbed[i-1] == 0) && (i == len-1 || flowerbed[i+1] == 0)) {
                flowerbed[i] = 1;
                n--;
            }
        }
        if(n > 0) return false;
        return true;
    }
};

int main() {
    Solution ob;
    int T = 1;
    cin>>T;
    while(T--) {
        int n, ct;
        cin>>n>>ct;
        vector<int> flowerbed(n);
        for(int i=0; i<n; i++)
            cin>>flowerbed[i];
        cout<<ob.canPlaceFlowers(flowerbed, ct)<<endl;
    }
    return 0;
}

/* Sample Input:
2
5 1
1 0 0 0 1
5 2
1 0 0 0 1

Sample Output:
1
0

*/