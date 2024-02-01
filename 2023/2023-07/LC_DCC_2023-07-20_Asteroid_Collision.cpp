// LC DCC 2023/07/20
// 735. Asteroid Collision
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size(), j = 0;
        stack<int> stk;
        
        for(int i = 0; i < n; i++) {
            if(stk.empty() || asteroids[i] > 0)
                stk.push(asteroids[i]);
            else {
                while(!stk.empty() && stk.top() > 0 && stk.top() < abs(asteroids[i]))
                    stk.pop();

                if(!stk.empty() && stk.top() == abs(asteroids[i]))
                    stk.pop();
                else if(stk.empty() || stk.top() < 0)
                        stk.push(asteroids[i]);
            }
        }
        vector<int> ans;
        while(!stk.empty()) {
            ans.push_back(stk.top());
            stk.pop();
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while(T--) {
        int n;
        cin >> n;
        vector<int> asteroids(n, 0);
        for(int &i: asteroids)
            cin >> i;
        
        vector<int> ans = ob.asteroidCollision(asteroids);
        for(int asteroid: ans)
            cout << asteroid << ' ';
        cout << endl;
    }
    
    return 0;
}

/* Sample Input:
3
3
10 5 -2
2
5 -5
3
10 2 -5

Sample Output:
10 5 

10 

*/