// LC DCC 2023/05/29
// 1603. Design Parking System
// Easy

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class ParkingSystem {
public:
    // // Approach 1:
    // int big, medium, small;

    // ParkingSystem(int big, int medium, int small) {
    //     this->big = big;
    //     this->medium = medium;
    //     this->small = small;
    // }
    
    // bool addCar(int carType) {
    //     if(carType == 1) {
    //         if(big > 0) {
    //             big--;
    //             return true;
    //         }
    //     }
    //     else if(carType == 2) {
    //         if(medium > 0) {
    //             medium--;
    //             return true;
    //         }
    //     }
    //     else if(carType == 3) {
    //         if(small > 0) {
    //             small--;
    //             return true;
    //         }
    //     }
    //     return false;
    // }

    // Approach 2: 
    vector<int> cars;

    ParkingSystem(int big, int medium, int small) {
        cars = {big, medium, small};
    }
    
    bool addCar(int carType) {
        return cars[carType - 1] ? cars[carType - 1]-- : 0;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
*/

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        int n, m;
        cin>>n>>m;
        vector<int> cuts(m, 0);
        for(int &i: cuts)
            cin>>i;

        cout<<ob.minCost(n, cuts)<<endl;
    }
    return 0;
}

/* Sample Input:

Sample Output:

*/