// LC DCC 2023/09/14
// 332. Reconstruct Itinerary
// Hard

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    void dfs(string airport, unordered_map<string, vector<string>> &adjList, vector<string> &itinerary) {
        while(!adjList[airport].empty()) {
            string next = adjList[airport].back();
            adjList[airport].pop_back();
            dfs(next, adjList, itinerary);
        }
        itinerary.push_back(airport);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> adjList;
        for(auto& ticket: tickets)
            adjList[ticket[0]].push_back(ticket[1]);
        
        for(auto& pr: adjList)
            sort(pr.second.rbegin(), pr.second.rend());
        
        vector<string> itinerary;
        dfs("JFK", adjList, itinerary);
        reverse(itinerary.begin(), itinerary.end());
        
        return itinerary;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<string>> tickets(n, vector<string> (2, ""));
        for(int i = 0; i < n; i++)
            cin >> tickets[i][0] >> tickets[i][1];
        vector<string> ans = ob.findItinerary(tickets);
        for(auto i: ans)
            cout << i << ' ';
        cout << endl;
    }

    return 0;
}

/* Sample Input:
3

4
MUC LHR
JFK MUC
SFO SJC
LHR SFO

3
JFK KUL
JFK NRT
NRT JFK

5
JFK SFO
JFK ATL
SFO ATL
ATL JFK
ATL SFO

Sample Output:
JFK MUC LHR SFO SJC 
JFK NRT JFK KUL 
JFK ATL SFO ATL JFK SFO 

*/