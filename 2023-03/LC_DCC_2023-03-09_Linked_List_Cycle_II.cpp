// LC DCC 2023/03/09
// 142. Linked List Cycle II
// Medium

#include<bits/stdc++.h>
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
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL)
            return NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *entry = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                while(slow != entry) {
                    slow = slow->next;
                    entry = entry->next;
                }
                return entry;
            }
        }
        return NULL;
    }
};

int main() {
    Solution ob;
    int T = 1;
    cin>>T;
    while(T--) {
        int n, h;
        cin>>n>>h;
        vector<int> piles(n);
        for(int i=0; i<n; i++)
            cin>>piles[i];
        cout<<ob.minEatingSpeed(piles, h)<<endl;
    }
    return 0;
}

/* Sample Input:
3
4 1
3 2 0 -4
2 0
1 2
1 -1
1

Sample Output:
1
0
-1

*/