// LC DCC 2023/03/18
// 1472. Design Browser History
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class BrowserHistory {
private:
    vector<string> history;
    int cur_idx;

public:
    //The BrowserHistory class uses a vector to store the history of visited URLs, and an integer cur_idx to keep track of the current index in the history.
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        cur_idx = 0;
    }
    
    //The visit method adds a new URL to the history, clearing any forward history that may exist.
    void visit(string url) {
        history.resize(cur_idx + 1); // clear forward history
        history.push_back(url);
        cur_idx++;
    }
    
    //The back method moves back in the history by the given number of steps, clamping the new index to the range [0, cur_idx]. It then returns the URL at the new index.
    string back(int steps) {
        int new_idx = max(0, cur_idx - steps);
        string url = history[new_idx];
        cur_idx = new_idx;
        return url;
    }
    
    //The forward method is similar to back, but moves forward in the history instead. The new index is clamped to the range [cur_idx, history.size()-1], and the URL at the new index is returned.
    string forward(int steps) {
        int new_idx = min((int)history.size()-1, cur_idx + steps);
        string url = history[new_idx];
        cur_idx = new_idx;
        return url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */


int main() {
    Solution ob;
    int T = 1;
    cin>>T;
    while(T--) {
        
    }
    return 0;
}

/* Sample Input:

Sample Output:

*/