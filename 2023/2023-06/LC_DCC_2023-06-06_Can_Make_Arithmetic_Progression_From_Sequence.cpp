// LC DCC 2023/06/06
// 1502. Can Make Arithmetic Progression From Sequence
// Easy

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        for(int i = 2; i < arr.size(); i++)
            if(arr[i] - arr[i - 1] != arr[1] - arr[0]) return false;
        
        return true;
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        int n;
        cin >> n;
        vector<int> arr(n, 0);
        for(int &i: arr)
            cin >> i;
        if(ob.canMakeArithmeticProgression(arr)) cout<<"true ";
        else cout<<"false ";
        cout<<endl;
    }
    return 0;
}

/* Sample Input:
2
3
3 5 1
3
1 2 4

Sample Output:
true 
false 

*/