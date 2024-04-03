// LC DCC 2024/03/06
// 141. Linked List Cycle
// Easy

#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return false;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return true;
        }

        return false;
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