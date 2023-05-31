// LC DCC 2022/11/30
// 1207. Unique Number of Occurrences
// Easy

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
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> ump;
        for(auto x: arr)
            ump[x]++;
        unordered_set<int> s;
        for(auto x: ump)
            s.insert(x.second);
        return (ump.size()==s.size());
    }
};

int main(){
    Solution ob;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0; i<n; i++)
            cin>>arr[i];
        cout<<ob.uniqueOccurrences(arr)<<endl;
    }
    return 0;
}

/* Sample Input
2
6
1 2 2 1 1 3
2
1 2

Sample Output
1
0

*/