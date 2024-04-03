// LC DCC 2024/03/03
// 19. Remove Nth Node From End of List
// Medium

#include<bits/stdc++.h>
using namespace std;

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == NULL) return NULL;

        int sz = 0;
        ListNode* dummy = head;
        while(dummy != NULL) {
            dummy = dummy->next;
            sz++;
        }

        if(sz == n) return head->next;
        
        dummy = head;
        while(--sz != n && sz > 0)
            dummy = dummy->next;
        dummy->next = dummy->next->next;

        return head;
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        
    }

    return 0;
}

/* Sample Input

Sample Output

*/