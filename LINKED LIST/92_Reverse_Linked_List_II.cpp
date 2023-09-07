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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head->next==NULL) return head;
        if(left==right) return head;
        int cnt = 0;
        ListNode* curr = head;
        while(curr!=NULL){
            curr=curr->next;
            cnt++;
        }

        // case 1
        if(left==1 && right==cnt){
        ListNode* prev = NULL;
        curr = head;
        while(curr!=NULL){
            ListNode* forward = curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev; 
        }

        curr=head;
        ListNode* prev = NULL;
        while(left!=1){
            prev=curr;
            curr=curr->next;
            left--;
            right--;
        }
        ListNode* prevstart = prev;
        ListNode* start = curr;
        while(right--){
            ListNode* forward = curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
    
        if (prevstart != NULL) {
            prevstart->next=prev;
        } else {
            head = prev;
        }
        start->next=curr;
        return head;
    }
};
