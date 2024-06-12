
// >-----------------------------------------------------------------------BRUTE FORCE------------------------------------------------------------------------------------------->

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
    ListNode* sortList(ListNode* head) {

        if(head==nullptr || head->next==nullptr)  return head;
        ListNode* temp  =  head;

        vector<int> arr;

            while(temp){
                   
                    arr.push_back(temp->val);
                    temp = temp->next;
            }

            sort(arr.begin(),arr.end());

            temp = head;
            int i = 0;

            while(temp){
                temp->val = arr[i++];
                temp=temp->next;
            }

            return head;        
    }
};






// <------------------------------------------------------------------DIVIDE AND COQUER, MERGE SORT, TORTOISE AND HARE ---------------------------------------------------------------------->





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

    ListNode* findmiddle_tortoise_and_hare(ListNode* head){
        ListNode* tortoise = head;
        ListNode* hare = head->next; // slight modification usually hare = head; but to get the 1st middle we have to slight modification

        while(hare!=nullptr && hare->next!=nullptr){

                tortoise = tortoise->next;
                hare = hare->next->next;
        }

        return tortoise;
    }

    ListNode* mergetwosortedlist(ListNode* list1, ListNode* list2){

            ListNode* Dummy = new ListNode(-1);
            ListNode* temp = Dummy;

            while(list1!=nullptr && list2!=nullptr){

                    if(list1->val<list2->val){
                        temp->next = list1;
                        temp=list1;
                        list1 = list1->next;
                    }
                    else{
                        temp->next = list2;
                        temp=list2;
                        list2 = list2->next;
                    }
            }

            if(list1!=nullptr) temp->next = list1;
            else temp->next = list2;

            return Dummy->next;
    }
    

    ListNode* sortList(ListNode* head) {

        if(head==nullptr || head->next==nullptr)  return head;
        
        ListNode* middle = findmiddle_tortoise_and_hare(head);
        ListNode* left = head;
        ListNode* right = middle->next;
        middle->next=nullptr;

        ListNode* leftlist = sortList(left);
        ListNode* rightlist = sortList(right);

        return mergetwosortedlist(leftlist,rightlist);      
    }
};


