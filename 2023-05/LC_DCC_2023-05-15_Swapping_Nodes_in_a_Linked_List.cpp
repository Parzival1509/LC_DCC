// LC DCC 2023/05/15
// 1721. Swapping Nodes in a Linked List
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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *left_ptr = head, *right_ptr = head;
        for (int i = 0; i < k-1; i++)
            right_ptr = right_ptr->next;
        
        ListNode *end_ptr = right_ptr;
        while (right_ptr->next) {
            left_ptr = left_ptr->next;
            right_ptr = right_ptr->next;
        }
        
        swap(end_ptr->val, left_ptr->val);
        
        return head;
    }
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
3
5 2
1 2 3 4 5
10 5
7 9 6 6 7 8 3 0 9 5

Sample Output:
1 4 3 2 5
7 9 6 6 8 7 3 0 9 5

*/