// LC DCC 2023/04/25
// 2336. Smallest Number in Infinite Set
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class SmallestInfiniteSet {
    map<int, int> m;
    
public:
    SmallestInfiniteSet() {
        // We will put all the numbers till 1001, so that even after all the pop operations, map does not become empty
        for(int i=1; i<1002; i++) m[i]++;
    }
    
    int popSmallest() {
        int val = m.begin()->first;
        m.erase(m.begin());
        return val;
    }
    
    void addBack(int num) {
        m[num]++;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
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