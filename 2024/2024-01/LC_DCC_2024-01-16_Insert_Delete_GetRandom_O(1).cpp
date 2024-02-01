// LC DCC 2024/01/16
// 380. Insert Delete GetRandom O(1)
// Medium

#include<bits/stdc++.h>
using namespace std;

class RandomizedSet {
public:
    vector<int> nums;
    unordered_map<int, int> valToIndex;
    
    RandomizedSet() {}
    
    bool insert(int val) {
        if(valToIndex.count(val)) return false;

        valToIndex[val] = nums.size();
        nums.push_back(val);
        
        return true;
    }
    
    bool remove(int val) {
        if(!valToIndex.count(val)) return false;

        int index = valToIndex[val];
        valToIndex[nums.back()] = index;
        swap(nums[index], nums.back());
        nums.pop_back();
        valToIndex.erase(val);

        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
*/

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        
    }

    return 0;
}

/* Sample Input

Sample Output

*/