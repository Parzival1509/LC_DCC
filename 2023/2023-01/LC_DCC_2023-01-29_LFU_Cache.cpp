// LC DCC 2023/01/29
// 460. LFU Cache
// Hard

#include<bits/stdc++.h>
using namespace std;
#define ll long long

class LFUCache {
    int maxSizeCache, size, minFreq;
    unordered_map<int, pair<int, int>> keyNode;
    unordered_map<int, list<int>> freqKeyLt;
    unordered_map<int, list<int>::iterator> keylist;

public:
    LFUCache(int capacity) {
        maxSizeCache = capacity;
        size = 0;
    }
    
    int get(int key) {
        if(keyNode.count(key) == 0) return -1;

        // Updation of data of the Key
        freqKeyLt[keyNode[key].second].erase(keylist[key]);
        keyNode[key].second++;
        freqKeyLt[keyNode[key].second].push_back(key);
        keylist[key] = --freqKeyLt[keyNode[key].second].end();

        // Updation of Min Frequency
        if(freqKeyLt[minFreq].size() == 0) minFreq++;

        return keyNode[key].first;
    }
    
    void put(int key, int value) {
        // Container not possible if capacity <= 0
        if(maxSizeCache <= 0) return;

        // Updation of the value of the Key
        int storedValue = get(key);
        if(storedValue != -1) {
            keyNode[key].first = value;
            return;
        }

        // Deletion of the LFU+LRU Key
        if(size >= maxSizeCache) {
            keyNode.erase(freqKeyLt[minFreq].front());
            keylist.erase(freqKeyLt[minFreq].front());
            freqKeyLt[minFreq].pop_front();
            size--;
        }

        // Insertion of the new Key
        keyNode[key] = {value, 1};
        freqKeyLt[1].push_back(key);
        keylist[key] = --freqKeyLt[1].end();
        minFreq = 1;
        size++;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
    LFU ob;
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<string> words(n);
        for(int i=0; i<n; i++)
            cin>>words[i];

        for(auto word: ob.findAllConcatenatedWordsInADict(words))
            cout<<word<<endl;
        cout<<endl;
    }
    return 0;
}

/* Sample Input:
1
SummaryRanges addNum getIntervals addNum getIntervals addNum getIntervals addNum getIntervals addNum getIntervals

Sample Output:
catdog

catsdogcats
dogcatsdog
ratcatdogcat


*/