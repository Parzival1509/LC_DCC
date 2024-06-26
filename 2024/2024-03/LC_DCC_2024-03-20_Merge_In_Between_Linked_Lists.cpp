// LC DCC 2024/03/20
// 1669. Merge In Between Linked Lists
// Medium

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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* ptr = list1;
        for (int i = 0; i < a - 1; ++i)
            ptr = ptr->next;

        ListNode* qtr = ptr->next;
        for (int i = 0; i < b - a + 1; ++i)
            qtr = qtr->next;

        ptr->next = list2;
        while (list2->next)
            list2 = list2->next;
        list2->next = qtr;

        return list1;
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