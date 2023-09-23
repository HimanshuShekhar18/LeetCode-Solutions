class Solution {
public:

// TRIE IMPLEMENTATION
// TC: O(n*32)+O(n*32)
// SC: O(n*32)+O(n*32)

    struct Node {
    Node* links[2];

    bool containsKey(int bit){
        return (links[bit]!=NULL);
    }

    Node* get(int bit){
        return links[bit];
    }

    void create(int bit, Node* node){
        links[bit] = node;
    }
};


// with respect to node you need a TRIE

class Trie{

    private: Node* root;

    public:

    Trie(){
        root = new Node();
    }


    void insert(int num){
        Node* node = root;
        for(int i = 31; i>=0; i--){
            int bit = (num>>i)&1;
            if(!(node->containsKey(bit))){
                node->create(bit,new Node());
            }
            node = node->get(bit);
        }
    }

    int getMax(int num){
         Node* node = root;
            int maxNum = 0;
         for(int i = 31; i>=0; i--){
                int bit = (num>>i)&1;
                if((node->containsKey(1-bit))){
                    maxNum = maxNum | (1<<i);
                    node = node->get(1-bit);
                }
                else {
                    node = node->get(bit);
                }
         }
         return maxNum;
    }    
};

    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
    for(int i = 0; i<nums.size(); i++){
        trie.insert(nums[i]);
    } 
    int maxi = 0;
    for(int i = 0; i<nums.size(); i++){
        maxi=max(maxi,trie.getMax(nums[i]));
    } 

    return maxi;
    }
};
