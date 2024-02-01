// LC DCC 2023/04/24
// 1046. Last Stone Weight
// Easy

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    // // Approach 1: Using Multiset
    // int lastStoneWeight(vector<int>& stones) {
    //     multiset<int> s;
    //     for(int i = 0; i < stones.size(); i++)
    //         s.insert(stones[i]);
    //     while(s.size()>1) {
    //         auto a = --s.end();
    //         auto b = --(--s.end());
    //         if((*a - *b) != 0)
    //             s.insert(abs(*a - *b));
    //         s.erase(a);
    //         s.erase(b);
    //     }
    //     if(s.size() == 0) return 0;
    //     auto it = s.begin();
    //     return *it;
    // }

    // Approach 2: Using Priority Queue
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        while(pq.size() > 1) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            if(a != b) pq.push(abs(a-b));
        }
        return pq.empty()? 0: pq.top();
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        int n;
        cin>>n;
        vector<int> stones(n, 0);
        for(int &i: stones)
            cin>>i;
        cout<<ob.lastStoneWeight(stones)<<endl;
    }
    return 0;
}

/* Sample Input:
3
1
2
4
2 2 2 2
6
2 7 4 1 8 1

Sample Output:
2
0
1

*/