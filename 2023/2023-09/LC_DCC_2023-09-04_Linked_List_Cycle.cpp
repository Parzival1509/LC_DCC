// LC DCC 2023/09/04
// 141. Linked List Cycle
// Easy

#include <bits/stdc++.h>
using namespace std;

#define ll long long

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
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return false;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) return true;
        }

        return false;
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
4 1
3 2 0 -4
2 0
1 2
1 -1
1

Sample Output:
true
true
false

*/