// LC DCC 2024/05/07
// 2816. Double a Number Represented as a Linked List
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
    ListNode* reverseList(ListNode* node) {
        ListNode* previous = NULL, *current = node, *nextNode;

        while (current != NULL) {
            nextNode = current->next;
            current->next = previous;
            previous = current;
            current = nextNode;
        }

        return previous;
    }
    
    int twiceOfVal(ListNode* head){
        if (!head) return 0;
        
        int doubledValue = head->val * 2 + twiceOfVal(head->next);
        head->val = doubledValue % 10;
        
        return doubledValue / 10;
    }
    
    ListNode* doubleIt(ListNode* head) {
        // // Approach 1: Reversing the List
        // ListNode* reversedList = reverseList(head);
        // ListNode* current = reversedList, *previous = NULL;
        // int carry = 0;

        // while (current != NULL) {
        //     int newValue = current->val * 2 + carry;
            
        //     current->val = newValue % 10;
        //     if (newValue > 9)
        //         carry = 1;
        //     else carry = 0;
            
        //     previous = current;
        //     current = current->next;
        // }

        // if (carry != 0) {
        //     ListNode* extraNode = new ListNode(carry);
        //     previous->next = extraNode;
        // }
        // ListNode* result = reverseList(reversedList);

        // return result;

        // // Approach 2: Stack
        // stack<int> values;
        // int val = 0;

        // while (head != NULL) {
        //     values.push(head->val);
        //     head = head->next;
        // }

        // ListNode* newTail = NULL;
        // while (!values.empty() || val != 0) {
        //     newTail = new ListNode(0, newTail);
            
        //     if (!values.empty()) {
        //         val += values.top() * 2;
        //         values.pop();
        //     }
        //     newTail->val = val % 10;
        //     val /= 10;
        // }

        // return newTail;

        // // Approach 3: Recursion
        // int carry = twiceOfVal(head);
        // if (carry) 
        //     head = new ListNode(carry, head);
        
        // return head;

        // Approach 4: Two Pointers
        ListNode *curr = head, *prev = NULL;
        while (curr != NULL) {
            int twiceOfVal = curr->val * 2;
            if (twiceOfVal < 10)
                curr->val = twiceOfVal;
            else if (prev != NULL) {
                curr->val = twiceOfVal % 10;
                prev->val = prev->val + 1;
            } 
            else {
                head = new ListNode(1, curr);
                curr->val = twiceOfVal % 10;
            }

            prev = curr;
            curr = curr->next;
        }

        return head;
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
2
1 8 9
9 9 8

Sample Output
3 7 8 
1 9 9 8 

*/