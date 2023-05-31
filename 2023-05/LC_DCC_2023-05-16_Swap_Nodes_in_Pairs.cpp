// LC DCC 2023/05/16
// 24. Swap Nodes in Pairs
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
    // Three Pointer Approach
    ListNode* swapPairs(ListNode* head) {
        if(!head) return head;
        if(!head->next) return head;
        
        ListNode* n1 = head;
        ListNode* n2 = head->next;
        ListNode* n3;
        head = n2;
        while(n2) {
            n1->next = n2->next? (n2->next->next? n2->next->next: n2->next): n2->next;
            n3 = n2->next;
            n2->next = n1;
            n1 = n3;
            n2 = n1? n1->next: 0;
        }
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
2
1 2 3 4
1 2 3

Sample Output:
2 1 4 3
2 1 3

*/