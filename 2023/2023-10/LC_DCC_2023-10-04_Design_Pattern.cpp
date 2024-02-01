// LC DCC 2023/10/04
// 706. Design HashMap
// Easy

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class MyHashMap {
public:
    int hsh[1000001];
    
    MyHashMap() {
        fill(hsh, hsh + 1000000, -1);
    }
    
    void put(int key, int value) {
        hsh[key] = value;
    }
    
    int get(int key) {
        return hsh[key];
    }
    
    void remove(int key) {
        hsh[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
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