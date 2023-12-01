// LC DCC 2023/11/20
// 2391. Minimum Amount of Time to Collect Garbage
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        int lastM = -1, lastP = -1, lastG = -1;
        
        // Finding the last house for each type of garbage
        for(int i = n - 1; i >= 0; i--) {
            if(lastM == -1 && garbage[i].find("M") != string::npos)
                lastM = i;
            if(lastP == -1 && garbage[i].find("P") != string::npos)
                lastP = i;
            if(lastG == -1 && garbage[i].find("G") != string::npos)
                lastG = i;

            // To avoid unnecessaray iterations
            if(lastM != -1 && lastP != -1 && lastG != -1)
                break;
        }
        
        int ans = 0;
        // Time to pick up garbage
        for(auto g: garbage)
            ans += g.size();

        // Time to travel
        if(lastM != -1)
            ans = accumulate(travel.begin(), travel.begin() + lastM, ans);
        if(lastP != -1)
            ans = accumulate(travel.begin(), travel.begin() + lastP, ans);
        if(lastG != -1)
            ans = accumulate(travel.begin(), travel.begin() + lastG, ans);

        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n;
        cin >> n;

        vector<string> garbage(n, "");
        for(string &i: garbage)
            cin >> i;
        vector<int> travel(n - 1, 0);
        for(int &i: travel)
            cin >> i;

        cout << ob.garbageCollection(garbage, travel) << endl;
    }

    return 0;
}

/* Sample Input:
2
4
G P GP GG
2 4 3
3
MMM PGM GP
3 10

Sample Output:
21
37

*/