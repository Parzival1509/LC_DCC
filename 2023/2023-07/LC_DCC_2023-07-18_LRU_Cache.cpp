// LC DCC 2023/07/18
// 146. LRU Cache
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class LRUCache {
    int maxCacheSize, size;
    unordered_map<int, int> keyMap;
    unordered_map<int, list<int>::iterator> itMap;
    list<int> keyList;

public:
    LRUCache(int capacity) {
        maxCacheSize = capacity;
        size = 0;
    }
    
    int get(int key) {
        if(keyMap.count(key) == 0) return -1;

        // Updation of data of the Key
        keyList.erase(itMap[key]);
        keyList.push_back(key);
        itMap[key] = --keyList.end();

        return keyMap[key];
    }
    
    void put(int key, int value) {
        // Container not possible if capacity <= 0
        if(maxCacheSize <= 0) return;

        // Updation of the value of the Key
        int storedValue = get(key);
        if(storedValue != -1) {
            keyMap[key] = value;
            return;
        }

        // Deletion of the LRU Key
        if(size >= maxCacheSize) {
            itMap.erase(keyList.front());
            keyMap.erase(keyList.front());
            keyList.pop_front();
            size--;
        }

        // Insertion of the new Key
        keyMap[key] = value;
        keyList.push_back(key);
        itMap[key] = --keyList.end();
        size++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while(T--) {
        
    }
    
    return 0;
}

/* Sample Input:


Sample Output:


*/