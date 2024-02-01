// LC DCC 2023/11/06
// 1845. Seat Reservation Manager
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class SeatManager {
public:
    priority_queue<int> pq;

    SeatManager(int n) {
        for(int i = 1; i <= n; i++)
            pq.push(-i);
    }
    
    int reserve() {
        int seatNumber = -(pq.top());
        pq.pop();
        return seatNumber;
    }
    
    void unreserve(int seatNumber) {
        pq.push(-seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
*/

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        
    }

    return 0;
}

/* Sample Input:


Sample Output:


*/