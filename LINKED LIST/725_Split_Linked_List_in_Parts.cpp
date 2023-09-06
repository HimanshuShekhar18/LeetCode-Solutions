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

    // NOTE: BEWRAE of member access within null pointer of type 'struct ListNode'
    // TC: O(max(n,k))
    // SC: O(max(n,k))
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
       
        int cnt=0;
        ListNode* temp1 = head;

        while(temp1!=nullptr){
            temp1=temp1->next;
            cnt++;
        }

        vector<ListNode*> vect;

        int length = cnt/k;
        int extra = cnt%k;

        temp1=head;

        while(k--){
            int times = length;
            ListNode* ans = new ListNode();
            ListNode* nodes = ans;
            while(times-- && temp1!=nullptr){
               nodes=nodes->next = new ListNode(temp1->val);
               temp1=temp1->next;
            }
            if(extra!=0 && temp1!=nullptr){
               nodes=nodes->next = new ListNode(temp1->val);
               temp1=temp1->next;
               extra--;
            }
            
            vect.push_back(ans->next);
        }
        return vect;  
    }
};

