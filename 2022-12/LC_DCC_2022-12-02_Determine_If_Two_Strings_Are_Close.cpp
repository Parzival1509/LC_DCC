// LC DCC 2022/12/02
// 1657. Determine if Two Strings Are Close
// Medium

#include<bits/stdc++.h>
using namespace std;

int start_up(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
int static r = start_up();

class Solution {
public:
    bool closeStrings(string w1, string w2) {
        if(w1.size()!=w2.size())
            return false;
        
        // Counting the frequencies
        vector<int> f1(26, 0), f2(26, 0);
        for(int i=0; i<w1.size(); i++) {
            f1[w1[i]-'a']++;
            f2[w2[i]-'a']++;
        }

        // Checking for non-equal characters
        for(int i=0; i<26; i++)
            if((f1[i]==0 && f2[i]!=0) || (f1[i]!=0 && f2[i]==0))
                return false;
        sort(f1.begin(), f1.end());
        sort(f2.begin(), f2.end());

        // Checking for equal frequencies
        for(int i=0; i<26; i++)
            if(f1[i]!=f2[i])
                return false;
        return true;
    }
};

int main(){
    Solution ob;
    int t;
    cin>>t;
    while(t--){
        string word1, word2;
        cin>>word1>>word2;
        cout<<ob.closeStrings(word1, word2)<<endl;
    }
    return 0;
}

/* Sample Input
3
a aa
abc bca
cabbba abbccc

Sample Output
0
1
1

*/