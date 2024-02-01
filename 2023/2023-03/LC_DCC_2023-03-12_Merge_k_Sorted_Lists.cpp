// LC DCC 2023/03/12
// 23. Merge k Sorted Lists
// Hard

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
    ListNode* merge2list(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        
        ListNode* head;
        if(l1->val <= l2->val) head = l1;
        else head = l2;
        
        if(l1->val <= l2->val) head->next = merge2list(l1->next, l2);
        else head->next = merge2list(l1, l2->next);
        
        return head;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;

        ListNode* head = lists[0];
        for(int i=1; i<lists.size(); i++)
            head = merge2list(head, lists[i]);
        return head;
    }

    // // 2nd Approach
    // ListNode* mergeKLists(vector<ListNode*>& lists) {
    //     map<int, int> m;
    //     for(auto& i: lists)
    //         while(i) {
    //             m[i->val]++;
    //             i = i->next;
    //         }

    //     ListNode dummy(0);
    //     ListNode* tail = &dummy;
    //     if(!m.size())
    //     return NULL;

    //     for(auto& it : m)
    //         for(int i{}; i<it.second; i++) {
    //             tail->next = new ListNode(it.first);
    //             tail = tail->next;
    //         }
    //     return dummy.next;
    // }
};

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