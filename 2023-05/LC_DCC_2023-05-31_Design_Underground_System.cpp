// LC DCC 2023/05/31
// 1396. Design Underground System
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class UndergroundSystem {
private:
    unordered_map<int, pair<int, string>> checkInLog;
    unordered_map<string,pair<double, double>> stationData;
    unordered_map<string, double> avgTime;

public:
    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        checkInLog[id] = make_pair(t,stationName);
    }
    
    void checkOut(int id, string stationName, int t) {
        int totalTime = t - checkInLog[id].first;
        string stationKey = checkInLog[id].second + "-" + stationName;
        checkInLog.erase(id);
        
        stationData[stationKey].first += totalTime;
        stationData[stationKey].second++;
        avgTime[stationKey] = stationData[stationKey].first / stationData[stationKey].second;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string stationKey = startStation + "-" + endStation;
        return avgTime[stationKey];
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
*/

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        
    }
    return 0;
}

/* Sample Input:

Sample Output:

*/