// LC DCC 2024/03/21
// 206. Reverse Linked List
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
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* next = NULL;
        ListNode* prev = NULL;

        while(cur != NULL) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        
        return prev;
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