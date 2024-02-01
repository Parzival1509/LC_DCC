// LC DCC 2023/06/11
// 1146. Snapshot Array
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class SnapshotArray {
    vector<vector<pair<int, int>>> updates;
    int snap_id;

public:
    SnapshotArray(int length) {
        updates.resize(length);
        snap_id = 0;
    }

    void set(int index, int val) {
        if (!updates[index].empty() && updates[index].back().first == snap_id)
            updates[index].back().second = val;
        else
            updates[index].push_back({snap_id, val});
    }

    int snap() {
        snap_id++;
        return snap_id - 1;
    }

    int get(int index, int snap_id) {
        int idx = upper_bound(updates[index].begin(), updates[index].end(), make_pair(snap_id,INT_MAX)) - updates[index].begin();
        if (idx == 0) return 0;
        return updates[index][idx - 1].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
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
2
4 2 6
6 1 10

Sample Output:
2
3

*/