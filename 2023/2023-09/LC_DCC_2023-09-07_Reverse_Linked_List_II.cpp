// LC DCC 2023/09/07
// 92. Reverse Linked List II
// Medium

#include <bits/stdc++.h>
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
    ListNode *reverseBetween(ListNode* head, int left, int right) {
        if(!head || left == right) return head;

        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *leftEnd = dummy;

        for(int i = 1; i < left; i++)
            leftEnd = leftEnd->next;

        ListNode *curr = leftEnd->next;

        ListNode *prev = leftEnd, *rightEnd = curr, *forward;
        leftEnd->next = NULL;

        // Sublist Reversal (Type 1)
        for(int i = 0; i <= right - left; i++) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        
        leftEnd->next = prev;
        rightEnd->next = forward;

        // // Sublist Reversal (Type 2)
        // for(int i = 0; i < right - left; i++) {
        //     ListNode *forward = curr->next;
        //     curr->next = forward->next;
        //     forward->next = leftEnd->next;
        //     leftEnd->next = forward;
        // }
        
        return dummy->next;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        
    }

    return 0;
}

/* Sample Input:
2
5 1 5
1 2 3 4 5
5 2 4
1 2 3 4 5

Sample Output:
5 4 3 2 1
1 4 3 2 5

*/