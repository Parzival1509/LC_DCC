// LC DCC 2023/07/17
// 445. Add Two Numbers II
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class ListNode {
public:
    int val;
    ListNode* next;

    // Constructor
    ListNode(int val) {
        this -> val = val;
        this -> next = NULL;
    }

    // Destructor
    ~ListNode() {
        int value = this -> val;
        while(this -> next != NULL) {
            delete next;
            this -> next = NULL;
        }
        cout << "Memory is free for the val " << value << endl;
    }
};

// Inserting a node at the Tail
void insertAtTail(ListNode* &head, ListNode* &tail, int d) {
    ListNode* tmp = new ListNode(d);
    if(tail == NULL) {
        head = tmp;
        tail = tmp;
        return;
    }
    tail -> next = tmp;
    tail = tail -> next;
}

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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;

        while(head != NULL) {
            ListNode* forward = head->next;
            head->next = prev;
            prev = head;
            head = forward;
        }

        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        
        ListNode* ansTail = new ListNode(0);
        ListNode* ansHead = ansTail;
        int carry = 0;
        while(l1 != NULL || l2 != NULL || carry != 0) {
            int sum = 0;
            if(l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum / 10;

            ListNode* tmp = new ListNode(sum % 10);
            ansTail->next = tmp;
            ansTail = tmp;
        }

        ansHead = reverseList(ansHead->next);

        return ansHead;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while(T--) {
        int m, n;
        cin >> m >> n;

        int tmp;
        cin >> tmp;
        ListNode* l1 = new ListNode(tmp);
        ListNode* tail1 = l1;
        for(int i = 0; i < m - 1; i++) {
            int x;
            cin >> x;
            insertAtTail(l1, tail1, x);
        }

        cin >> tmp;
        ListNode* l2 = new ListNode(tmp);
        ListNode* tail2 = l2;
        for(int i = 0; i < n - 1; i++) {
            int x;
            cin >> x;
            insertAtTail(l2, tail2, x);
        }
        
        ListNode* ans = ob.addTwoNumbers(l1, l2);
        ListNode* newNode = ans;
        while(newNode != NULL) {
            cout << newNode->val << ' ';
            newNode = newNode->next;
        }
        cout << endl;
    }
    
    return 0;
}

/* Sample Input:
3
4 3
7 2 4 3
5 6 4
3 3
2 4 3
5 6 4
1 1
0
0

Sample Output:
7 8 0 7 
8 0 7 
0 

*/