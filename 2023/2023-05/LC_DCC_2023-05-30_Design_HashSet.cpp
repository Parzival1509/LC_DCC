// LC DCC 2023/05/30
// 705. Design HashSet
// Easy

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class MyHashSet {
private:
    vector<bool> hsh;

public:
    MyHashSet() {
        hsh.resize(1e6 + 1, false);
    }
    
    void add(int key) {
        hsh[key] = true;
    }
    
    void remove(int key) {
        hsh[key] = false;
    }
    
    bool contains(int key) {
        return hsh[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
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