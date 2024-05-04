// LC DCC 2024/04/06
// 1249. Minimum Remove to Make Valid Parentheses
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        // // Approach 1: Without Stack
        // int openParenthesesCount = 0;
        // vector<char> arr(s.begin(), s.end());

        // for (int i = 0; i < arr.size(); i++) {
        //     if (arr[i] == '(')
        //         openParenthesesCount++;
        //     else if (arr[i] == ')') {
        //         if (openParenthesesCount == 0)
        //             arr[i] = '*';
        //         else openParenthesesCount--;
        //     }
        // }

        // for (int i = arr.size() - 1; i >= 0; i--)
        //     if (openParenthesesCount > 0 && arr[i] == '(') {
        //         arr[i] = '*';
        //         openParenthesesCount--;
        //     }
        
        // string result = "";
        // for (char c : arr)
        //     if (c != '*')
        //         result += c;

        // Approach 2: With Stack
        int leftCount = 0, rightCount = 0;
        stack<char> stack;

        for (char ch : s) {
            if (ch == '(')
                leftCount++;
            else if (ch == ')')
                rightCount++;
            
            if (rightCount > leftCount) {
                rightCount--;
                continue;
            }
            else stack.push(ch);
        }

        string result = "";
        while (!stack.empty()) {
            char currentChar = stack.top();
            stack.pop();
            if (leftCount > rightCount && currentChar == '(')
                leftCount--;
            else result += currentChar;
        }

        reverse(result.begin(), result.end());

        return result;
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        cout << ob.minRemoveToMakeValid(s) << endl;
    }

    return 0;
}

/* Sample Input
3
))((
a)b(c)d
lee(t(c)o)de)

Sample Output

ab(c)d
lee(t(c)o)de

*/