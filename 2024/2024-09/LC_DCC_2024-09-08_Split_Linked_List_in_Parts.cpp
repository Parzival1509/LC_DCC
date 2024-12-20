// LC DCC 2024/09/08
// 725. Split Linked List in Parts
// Medium

#include <bits/stdc++.h>
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int ct = 0, n = 0, x, xx;
        vector<ListNode*> parts;

        // Couting the number of nodes
        ListNode *tmp = head, *forward;
        while (tmp) {
            tmp = tmp->next;
            n++;
        }

        // No. of parts which will have one node extra
        ct = n - (n / k) * k;

        tmp = head;

        // If the number of nodes is less than the number of parts
        if (n <= k) {
            x = k - n;
            while (tmp) {
                forward = tmp->next;
                tmp->next = NULL;
                parts.push_back(tmp);
                tmp = forward;
            }
            while (x--)
                parts.push_back(NULL);
        }
        // If the number of nodes is more than the number of
        else {
            x = n / k, xx = x;
            while (k--) {
                parts.push_back(tmp);
                while (tmp && --x) {
                    tmp = tmp->next;
                }
                if (ct > 0) {
                    tmp = tmp->next;
                    ct--;
                }
                if (tmp)
                    forward = tmp->next;
                if (tmp)
                    tmp->next = NULL;
                tmp = forward;
                x = xx;
            }
        }

        return parts;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while (T--) {
        
    }

    return 0;
}

/* Sample Input


Sample Output


*/