// LC DCC 2023/03/11
// 109. Convert Sorted List to Binary Search Tree
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
*/

class Solution {
public:
    TreeNode* func(ListNode*head, int n) {
        // If we have the length of list 0 then we will simply return the nullptr
        if(n <= 0) return nullptr;
        
        // If we are remaining with only one length then we will make node of it and return it
        if(n == 1) return new TreeNode(head->val);
        
        int mid = n/2;
        ListNode*temp = head;
        // Traversing to the mid of the list from head
        while(mid--) temp = temp->next;
        
        // Then we will get our ans
        TreeNode*ans = new TreeNode(temp->val, func(head, n/2), func(temp->next, n-n/2-1));
        return ans;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return nullptr;

        int n = 0;
        // We are calculating the length of the linked list
        // so that we can divide the linked list from middle
        ListNode*temp = head;
        while(temp) {
            n++;
            temp = temp->next;
        }
        return func(head, n);
    }
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
-10 -3 0 5 9


Sample Output:
0 -3 9 -10 NULL 5


*/