// LC DCC 2022/12/29
// 1834. Single-Threaded CPU
// Medium

#include <bits/stdc++.h>
using namespace std;

// Baijnath's Sol
class Solution {
public:
    vector<int> getOrder(vector<vector<int>> tasks) {
        for(int i=0; i<tasks.size(); ++i) tasks[i].push_back(i);
        sort(tasks.begin(), tasks.end());
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> remaining;
        
        vector<int> res;
        int curMoment = 0;
        int curIdx = 0;
        while(res.size() < tasks.size()) {
            if(remaining.empty() && curIdx < tasks.size())
                curMoment = max(curMoment, tasks[curIdx][0]);
            
            while(curIdx < tasks.size() && tasks[curIdx][0] <= curMoment) {
                remaining.push({tasks[curIdx][1], tasks[curIdx][2]});
                ++curIdx;
            }
            auto next = remaining.top();
            
            remaining.pop();
            curMoment = min(1000000000, curMoment+next[0]);
            res.push_back(next[1]);
        }
        return res;
    }
};

int main() {
    int T;
    cin>>T;
    Solution ob;
    while(T--) {
        int n;
        cin>>n;
        vector<vector<int>> tasks(n, vector<int> (2, 0));
        for(int i=0; i<n; i++)
            cin>>tasks[i][0]>>tasks[i][1];
        vector<int> ans = ob.getOrder(tasks);
        for(auto task: ans)
            cout<<task<<' ';
        cout<<endl;
    }
    return 0;
}

/* Sample Input
2
4
1 2
2 4
3 2
4 1
5
7 10
7 12
7 5
7 4
7 2

Sample Output
0 2 3 1 
4 3 2 0 1 

*/