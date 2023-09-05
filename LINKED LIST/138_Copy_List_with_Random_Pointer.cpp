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

