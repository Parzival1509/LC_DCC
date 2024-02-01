// LC DCC 2023/02/09
// 2306. Naming a Company
// Hard

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    ll distinctNames(vector<string>& ideas) {
        // Group idea by their initials.
        unordered_set<string> initialGroup[26];
        for(auto& idea: ideas)
            initialGroup[idea[0]-'a'].insert(idea.substr(1));
        
        // Calculate number of valid names from every pair of groups.
        ll answer = 0;
        for(int i=0; i<25; ++i) {
            for(int j=i+1; j<26; ++j) {
                // Get the number of mutual suffixes.
                int numOfMutual = 0;
                for(auto& ideaA: initialGroup[i])
                    if(initialGroup[j].count(ideaA))
                        numOfMutual++;

                // Valid names are only from distinct suffixes in both groups.
                // Since we can swap a with b and swap b with a to create two valid names, multiple answer by 2.
                answer += 2LL*(initialGroup[i].size() - numOfMutual)*(initialGroup[j].size() - numOfMutual);
            }
        }
        return answer;
    }
};

int main() {
    Solution ob;
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<string> ideas(n);
        for(auto &idea: ideas)
            cin>>idea;
        cout<<ob.distinctNames(ideas)<<endl;
    }
    return 0;
}

/* Sample Input:
2
2
lack back
4
coffee donuts time toffee

Sample Output:
0
6

*/