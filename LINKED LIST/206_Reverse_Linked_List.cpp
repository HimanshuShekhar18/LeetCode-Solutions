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
    // Iterative Method
    // TC: O(n)
    // SC: O(1)
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr!=NULL){
            ListNode* forward = curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;        
    }
};

// <--------------------------------------------------------------RECURSIVE------------------------------------------------------------------->


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
    // Recursive Method
    // TC: O(n)
    // SC: O(n)
    void reverse(ListNode* &head, ListNode* curr, ListNode* prev){
        if(curr==NULL){
            head=prev;
            return;
        }
        reverse(head,curr->next,curr);
        curr->next=prev;
    }
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        reverse(head,curr,prev);
        return head;        
    }
};

