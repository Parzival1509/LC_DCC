// LC DCC 2023/09/05
// 138. Copy List with Random Pointer
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertAtTail(Node* &head, Node* &tail, int d) {
        Node* newNode = new Node(d);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    Node *copyRandomList(Node *head) {
        // Step 1: Create a clone list
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        Node* tmp = head;
        
        while(tmp) {
            insertAtTail(cloneHead, cloneTail, tmp->val);
            tmp = tmp->next;
        }
        
        // // Approach 1: Using Map, T.C. = O(N), S.C. = O(N)
        
        // // Step 2: Create a map
        // unordered_map<Node*, Node*> oldToNewNode;
        // Node* originalNode = head;
        // Node* cloneNode = cloneHead;
        
        // while(originalNode) {
        //     oldToNewNode[originalNode] = cloneNode;
        //     originalNode = originalNode->next;
        //     cloneNode = cloneNode->next;
        // }
        
        // // Step 3: Map the random nodes
        // originalNode = head;
        // cloneNode = cloneHead;
        
        // while(originalNode) {
        //     cloneNode->random = oldToNewNode[originalNode->random];
        //     originalNode = originalNode->next;
        //     cloneNode = cloneNode->next;
        // }
        
        // Approach 2: Without using map, Changing Links, T.C. = O(N), S.C. = O(1)
        
        // Step 2: Change the Links
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        
        while(originalNode) {
            Node* forward = originalNode->next;
            originalNode->next = cloneNode;
            originalNode = forward;
            
            forward = cloneNode->next;
            cloneNode->next = originalNode;
            cloneNode = forward;
        }
        
        // Step 3: Add the Random pointers in the clone list
        tmp = head;
        
        while(tmp) {
            if(tmp->next)
                tmp->next->random = tmp->random? tmp->random->next: NULL;
            tmp = tmp->next->next;
        }
        
        //Step 4: Return the links back to normal
        originalNode = head;
        cloneNode = cloneHead;
        
        while(originalNode) {
            originalNode->next = cloneNode->next;
            originalNode = originalNode->next;
            
            if(originalNode)
                cloneNode->next = originalNode->next;
            cloneNode = cloneNode->next;
        }
        
        return cloneHead;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        
    }

    return 0;
}

/* Sample Input:
2
4 1
3 2 0 -4
2 0
1 2
1 -1
1

Sample Output:
true
true
false

*/