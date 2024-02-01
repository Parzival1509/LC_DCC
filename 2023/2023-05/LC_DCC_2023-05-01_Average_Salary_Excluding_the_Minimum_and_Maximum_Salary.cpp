// LC DCC 2023/05/01
// 1491. Average Salary Excluding the Minimum and Maximum Salary
// Easy

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    double average(vector<int>& salary) {
        int n = salary.size();
        double ans = 1.0 * accumulate(salary.begin(), salary.end(), 0);
        ans -= (*max_element(salary.begin(), salary.end()) + *min_element(salary.begin(), salary.end()));
        ans = ans / (n - 2);
        return ans;
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        int n;
        cin>>n;
        vector<int> salary(n, 0);
        for(int &i: salary)
            cin>>i;
        cout<<ob.average(salary)<<endl;
    }
    return 0;
}

/* Sample Input:
2
4
4000 3000 1000 2000
3
1000 2000 3000

Sample Output:
2500
2000

*/