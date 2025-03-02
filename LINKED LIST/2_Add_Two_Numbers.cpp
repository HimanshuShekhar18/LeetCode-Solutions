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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int carry = 0;
        ListNode* dummynode = new ListNode(-1);
        ListNode* curr = dummynode;
        while(l1!=NULL || l2!=NULL){
                
                int sum = 0;
                if(l1!=NULL){
                    sum = l1->val;
                    l1=l1->next;
                }
                if(l2!=NULL){
                    sum = sum + l2->val;
                    l2=l2->next;
                }
                sum = sum+carry;
                curr->next = new ListNode(sum%10);
                curr = curr->next;
                carry = sum/10;
        }
        if(carry!=0) {
            curr->next = new ListNode(carry);
            curr = curr->next;
        }
        return dummynode->next;
    }
};
