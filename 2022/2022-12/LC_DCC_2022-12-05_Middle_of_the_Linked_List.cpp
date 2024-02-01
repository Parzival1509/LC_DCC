// LC DCC 2022/12/05
// 876. Middle of the Linked List
// Easy

#include<bits/stdc++.h>
using namespace std;

int start_up(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
int static r = start_up();

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
    ListNode* middleNode(ListNode* head) {
        ListNode *hare, *tortoise;
        hare=tortoise=head;
        while(hare && hare->next){
            hare = hare->next->next;
            tortoise = tortoise->next;
        }
        return tortoise;
    }
};

int main(){
    Solution ob;
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        cout<<ob.frequencySort(s)<<endl;
    }
    return 0;
}

/* Sample Input
3
tree
cccaaa
Aabb

Sample Output
eert
aaaccc
bbaA

*/