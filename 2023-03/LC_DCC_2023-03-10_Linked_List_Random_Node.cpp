// LC DCC 2023/03/10
// 382. Linked List Random Node
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
    ListNode *randomPointer;
    int size;

    Solution(ListNode* head) {
        size = 0;
        randomPointer = head;
        while(head != NULL) {
            size++;
            head = head->next;
        }
    }

    int getRandom() {
        int num = (rand() %(size));
        ListNode* random = randomPointer;
        int count = 0;
        while(count < num) {
            count++;
            random = random->next;
        }
        int val = random->val;
        return val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */

int main() {
    Solution ob;
    int T = 1;
    cin>>T;
    while(T--) {
        
    }
    return 0;
}

/* Sample Input:


Sample Output:


*/