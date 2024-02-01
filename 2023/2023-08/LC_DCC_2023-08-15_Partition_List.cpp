// LC DCC 2023/08/15
// 86. Partition List
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
    ListNode* partition(ListNode* head, int x) {
        ListNode *leftHead = new ListNode(0);
        ListNode *rightHead = new ListNode(0);

        ListNode *leftTail = leftHead;
        ListNode *rightTail = rightHead;

        while(head != NULL) {
            if(head->val < x) {
                leftTail->next = head;
                leftTail = leftTail->next;
            }
            else {
                rightTail->next = head;
                rightTail = rightTail->next;
            }

            head = head->next;
        }

        leftTail->next = rightHead->next;
        rightTail->next = NULL;

        return leftHead->next;
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
4

6 3
1 4 3 2 5 2

2 2
2 1

2 0
1 1

0 0

Sample Output:
1 2 2 4 3 5
1 2
1 1


*/