// LC DCC 2023/05/17
// 2130. Maximum Twin Sum of a Linked List
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
*/

class Solution {
public:
    // Approach 1: Using a vector
    // T.C. = O(N), S.C. = O(N)
    int pairSum(ListNode* head) {
        vector<int> nodeVals;
        int returnVal = 0;

        while(head != nullptr) {
            nodeVals.emplace_back(head->val);
            head = head->next;
        }

        for(int i=0, j=nodeVals.size()-1; i<nodeVals.size()/2; i++, j--)
            returnVal = max(returnVal, nodeVals[i] + nodeVals[j]);

        return returnVal;
    }

    // // Approach 2: Using slow and fast pointers
    // int pairSum(ListNode* head) {
    //     ListNode* slow = head;
    //     ListNode* fast = head;
    //     int maxVal = 0;

    //     while(fast && fast -> next) {
    //         slow = slow -> next;
    //         fast = fast -> next -> next;
    //     }

    //     ListNode *nextNode, *prev = NULL;
    //     while(slow) {
    //         nextNode = slow -> next;
    //         slow -> next = prev;
    //         prev = slow;
    //         slow = nextNode;
    //     }

    //     while(prev) {
    //         maxVal = max(maxVal, head -> val + prev -> val);
    //         prev = prev -> next;
    //         head = head -> next;
    //     }

    //     return maxVal;
    // }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        int n;
        cin>>n;
        
    }
    return 0;
}

/* Sample Input:
2
4
5 4 2 1
4
4 2 2 3

Sample Output:
6
7

*/