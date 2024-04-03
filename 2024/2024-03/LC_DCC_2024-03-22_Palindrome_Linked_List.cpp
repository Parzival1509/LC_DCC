// LC DCC 2024/03/22
// 234. Palindrome Linked List
// Easy

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
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* rev = reverse(slow);
        while (rev) {
            if (head->val != rev->val)
                return false;
            
            head = head->next;
            rev = rev->next;
        }

        return true;
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
3
2 6
AAABBB
1 6
ACABDB
3 6
AAABBB

Sample Output
8
6
10

*/