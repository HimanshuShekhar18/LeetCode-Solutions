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
    // TC: O(n)
    // SC: O(n)
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        map<Node*,Node*> mp;   // to keep track Copy nodes of Original nodes 
        Node* obj = NULL;
        Node* temp1 = head;
        Node* tail = NULL;
        // 1) copying and connecting the next pointers
        while(temp1!=NULL){
            Node* node = new Node(temp1->val);
            mp[temp1]=node;
            if(obj==NULL){
                obj=node;
                tail=obj;
            }
            else{
            tail->next = node;
            tail=tail->next;
            }
            temp1=temp1->next;
        }
        
        // 2) copying and connecting the random pointers
        Node* temp2 = head;
        Node* tail1 = obj;
        while(temp2!=NULL){
            if(temp2->random==NULL) {
                tail1->random=NULL;
            }
            else{
            tail1->random = mp[temp2->random];
            }
            tail1=tail1->next;
            temp2=temp2->next;            
        }    
        return obj;
    }
};



// <---------------------------------------------------------- SC: O(1) and Fast ------------------------------------------------------------------->

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
    // TC: O(n)
    // SC: ans space = O(n) but extra space O(1), hence SC: O(1) (as in Space Complexity we consider extra space not the ans space)
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        Node* curr = head;

        // 1) Insert the new nodes in between the Original Linked List
        while(curr!=NULL){
            // A --> B
            Node* node = new Node(curr->val);  // x
            Node* currNext = curr->next;     // B
            curr->next = node;      // A --> x
            node->next = currNext;  // A --> x --> B
            curr = currNext;   // curr now at B
        }
        
        // 2) Deep Copy of random pointers
        curr = head;
        while(curr!=NULL && curr->next!=NULL){
            if(curr->random==NULL){
                curr->next->random = NULL;
            } 
            else {
                curr->next->random = curr->random->next;
            }
            curr=curr->next->next;      // check must be done for NULL access violation    
        }

        // 3) Separation the copied Linked List and Original Linked List
        curr = head;
        Node* newHead = head->next;
        Node* newcurr = newHead;

        while(curr!=NULL && newcurr!=NULL ){
            // first we will separate curr from newHead
            curr->next = curr->next == NULL? NULL: curr->next->next;  
            curr=curr->next;
            // then after that we will separate newHead from curr
            newcurr->next = newcurr->next == NULL? NULL: newcurr->next->next;  
            newcurr=newcurr->next;       
        }
        return newHead;
    }
};



