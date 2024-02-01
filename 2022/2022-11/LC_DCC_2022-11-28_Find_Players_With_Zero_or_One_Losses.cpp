// LC DCC 2022/11/28
// 2225. Find Players With Zero or One Losses
// Medium

#include<bits/stdc++.h>
using namespace std;

int start_up(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
int static r = start_up();
bool cmp(pair<string, int> A, pair<string, int> B){
    if(A.first != B.first)
        return A.second < B.second;
    return B.first > A.first;
}

// Baijnath's Sol
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> mp;
        for(auto& m : matches) {
            mp[m[1]]++;
            mp[m[0]] += 0;
        }
        vector<vector<int>> res(2);
        
        for(auto el: mp) {
            if(el.second == 0)
                res[0].push_back(el.first);
            else if(el.second == 1)
                res[1].push_back(el.first);
        }
        
        sort(res[0].begin(), res[0].end());
        sort(res[1].begin(), res[1].end());
        return res;
    }
};

int main(){
    Solution ob;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> matches(n, vector<int> (2, 0));
        for(int i=0; i<n; i++)
            cin>>matches[i][0]>>matches[i][1];
        vector<vector<int>> ans = ob.findWinners(matches);
        for(auto el: ans) {
            for(int i=0; i<el.size(); i++)
                cout<<el[i]<<' ';
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}

/* Sample Input
2
10
1 3
2 3
3 6
5 6
5 7
4 5
4 8
4 9
10 4
10 9
4
2 3
1 3
5 4
6 4

Sample Output
1 2 10 
4 5 7 8 

1 2 5 6 



*/