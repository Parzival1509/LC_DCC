// LC DCC 2022/11/12
// 295. Find Median from Data Stream
// Hard

#include<bits/stdc++.h>
using namespace std;

int start_up(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
int static r = start_up();

class MedianFinder {
public:
    priority_queue<int>MaxHeap;
    priority_queue<int,vector<int>,greater<int>>MinHeap;
    
    MedianFinder(){}
    
    void addNum(int num) {
        MaxHeap.push(num);
        MinHeap.push(MaxHeap.top());
        MaxHeap.pop();
        if(MinHeap.size() > MaxHeap.size()) {
            MaxHeap.push(MinHeap.top());
            MinHeap.pop();
        }
    }
    
    double findMedian() {    
        if(MaxHeap.size() > MinHeap.size()) return MaxHeap.top();
        else return (double)(MaxHeap.top()+MinHeap.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main(){
    Solution ob;
    int t;
    cin>>t;
    while(t--){
        
    }
    return 0;
}

/* Sample Input
2
3
1 1 2
10
0 0 1 1 1 2 2 3 3 4

Sample Output
2
5

*/