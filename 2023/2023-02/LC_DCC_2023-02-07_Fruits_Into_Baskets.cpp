// LC DCC 2023/02/07
// 904. Fruit Into Baskets
// Medium

#include<bits/stdc++.h>
using namespace std;
#define ll long long

// T.C. = O(N) and S.C. = O(1)
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> ct;
        int i = 0, j = 0, ans = INT_MIN;
        for(; j<fruits.size(); j++) {
            ct[fruits[j]]++;
            while(ct.size() > 2) {
                if(--ct[fruits[i]] == 0) ct.erase(fruits[i]);
                i++;
            }
            ans = max(ans, j-i+1);
        }
        return ans;
    }
};

int main() {
    Solution ob;
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> fruits(n);
        for(int i=0; i<n; i++)
            cin>>fruits[i];
        cout<<ob.totalFruit(fruits)<<endl;
    }
    return 0;
}

/* Sample Input:
3
3
1 2 1
4
0 1 2 2
5
1 2 3 2 2

Sample Output:
3
3
4

*/