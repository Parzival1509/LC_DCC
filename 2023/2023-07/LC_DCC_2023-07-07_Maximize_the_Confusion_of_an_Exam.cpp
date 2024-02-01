// LC DCC 2023/07/07
// 2024. Maximize the Confusion of an Exam
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size(), start = 0, end = 0;
        int ctT = 0, ctF = 0, ans = 0;

        // Approach 1:
        for(int i = 0; i < answerKey.size(); i++) {
            answerKey[i] == 'T'? ctT++: ctF++;
            if(min(ctT, ctF) <= k) ans++;
            else answerKey[end++] == 'T'? ctT--: ctF--;
        }

        // // Approach 2:
        // while (end < n) {
        //     answerKey[end] == 'T'? ctT++: ctF++;

        //     while (ctT > k && ctF > k) {
        //         if (answerKey[start] == 'T') ctT--;
        //         else ctF--;

        //         start++;
        //     }

        //     ans = max(ans, end - start + 1);
        //     end++;
        // }

        return ans;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while(T--) {
        int k;
        string answerKey;
        cin >> k >> answerKey;
        cout << ob.maxConsecutiveAnswers(answerKey, k) << endl;
    }
    return 0;
}

/* Sample Input:
3
2 TTFF
1 TFFT
1 TTFTTFTT

Sample Output:
4
3
5

*/