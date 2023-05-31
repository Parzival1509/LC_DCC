// LC DCC 2023/02/03
// 6. Zigzag Conversion
// Medium

#include<bits/stdc++.h>
using namespace std;
#define ll long long

// // Approach 1: Simulate Zigzag Movement
// // T.C. = O(N*Rows), S.C. = O(N*Rows)

// class Solution {
// public:
//     string convert(string s, int numRows) {
//         if(numRows == 1) return s;
        
//         int n = int(s.size());
//         int sections = ceil(n / (2 * numRows - 2.0));
//         int numCols = sections * (numRows - 1);
        
//         vector<vector<char>> matrix(numRows, vector<char>(numCols, ' '));
//         int currRow = 0, currCol = 0, currStringIndex = 0;
        
//         // Iterate in zig-zag pattern on matrix and fill it with string characters.
//         while(currStringIndex < n) {
//             // Move down.
//             while(currRow < numRows && currStringIndex < n) {
//                 matrix[currRow][currCol] = s[currStringIndex];
//                 currRow++;
//                 currStringIndex++;
//             }
//             currRow -= 2;
//             currCol++;
            
//             // Move up (with moving right also).
//             while(currRow > 0 && currCol < numCols && currStringIndex < n) {
//                 matrix[currRow][currCol] = s[currStringIndex];
//                 currRow--;
//                 currCol++;
//                 currStringIndex++;
//             }
//         }
        
//         string answer;
//         for(auto& row: matrix)
//             for(auto& character: row)
//                 if(character != ' ') answer += character;
        
//         return answer;
//     }
// };

// Approach 2: String Traversal
// T.C. = O(N), S.C. = O(1)

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;

        string answer;
        int n = s.size(), charsInSection = 2 * (numRows - 1);

        for(int currRow = 0; currRow < numRows; ++currRow) {
            int index = currRow;

            while(index < n) {
                answer += s[index];

                // If currRow is not the first or last row
                // then we have to add one more character of current section.
                if(currRow != 0 && currRow != numRows - 1) {
                    int charsInBetween = charsInSection - 2 * currRow;
                    int secondIndex = index + charsInBetween;
                    
                    if(secondIndex < n) answer += s[secondIndex];
                }
                // Jump to same row's first character of next section.
                index += charsInSection;
            }
        }
        return answer;
    }
};

int main() {
    Solution ob;
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        int n;
        cin>>n;
        cout<<ob.convert(s, n)<<endl;
    }
    return 0;
}

/* Sample Input:
3
PAYPALISHIRING 3
PAYPALISHIRING 4
A 1

Sample Output:
PAHNAPLSIIGYIR
PINALSIGYAHRPI
A

*/