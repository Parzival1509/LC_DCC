// LC DCC 2022/12/06
// 328. Odd Even Linked List
// Medium

#include<bits/stdc++.h>
using namespace std;

int start_up(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
int static r = start_up();

// Baijnath's Sol
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head)
            for(auto odd_tail = head, curr = head->next; curr && curr->next; curr = curr->next) {
                ListNode *even_head = odd_tail->next;
                odd_tail->next = curr->next;
                odd_tail = odd_tail->next;
                curr->next = odd_tail->next;
                odd_tail->next = even_head;
            }
        return head;
    }
};

int main(){
    Solution ob;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> nums(n);
        for(int i=0; i<n; i++)
            cin>>nums[i];
        cout<<ob.minimumAverageDifference(nums)<<endl;
    }
    return 0;
}

/* Sample Input
2
5
1 2 3 4 5
7
2 1 3 5 6 4 7

Sample Output
1 3 5 2 4
2 3 6 7 1 5 4

*/