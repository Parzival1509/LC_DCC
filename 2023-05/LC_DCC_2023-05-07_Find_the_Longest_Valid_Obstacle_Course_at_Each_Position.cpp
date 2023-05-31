// LC DCC 2023/05/07
// 1964. Find the Longest Valid Obstacle Course at Each Position
// Hard

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size(), length = 0;
        vector<int> result(n), increasingSubseq(n);
        for(int i = 0; i < n; ++i) {
            int left = 0, right = length;
            while(left < right) {
                int mid = (left + right) / 2;
                if(increasingSubseq[mid] <= obstacles[i])
                    left = mid + 1;
                else right = mid;
            }
            result[i] = left + 1;
            if(length == left) length++;
            increasingSubseq[left] = obstacles[i];
        }
        return result;
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        int n;
        cin>>n;
        vector<int> obstacles(n, 0);
        for(int &i: obstacles)
            cin>>i;
        vector<int> ans = ob.longestObstacleCourseAtEachPosition(obstacles);
        for(int i: ans)
            cout<<i<<' ';
        cout<<endl;
    }
    return 0;
}

/* Sample Input:
3
4
1 2 3 2
3
2 2 1
6
3 1 5 6 4 2

Sample Output:
1 2 3 3 
1 2 1 
1 1 2 3 2 2 

*/