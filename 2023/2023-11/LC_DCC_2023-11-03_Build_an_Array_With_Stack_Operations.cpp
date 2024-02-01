// LC DCC 2023/11/03
// 1441. Build an Array With Stack Operations
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int ptr = 0;

        for(int i = 1; i <= n; i++) {
            if(ptr == target.size()) break;;

            ans.push_back("Push");
            if(i == target[ptr]) ptr++;
            else ans.push_back("Pop");
        }

        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int m, n;
        cin >> m >> n;
        vector<int> target(m, 0);
        for(int &i: target)
            cin >> i;
        vector<string> ans = ob.buildArray(target, n);
        for(auto i: ans)
            cout << i << ' ';
        cout << endl;
    }

    return 0;
}

/* Sample Input:
3
2 3
1 3
3 3
1 2 3
2 4
1 2

Sample Output:
Push Push Pop Push 
Push Push Push 
Push Push 

*/