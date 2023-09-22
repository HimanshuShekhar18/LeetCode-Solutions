
#include <bits/stdc++.h> 

struct Node{
    Node* links[26];
    int cntEndwith = 0;
    int cntPrefix = 0;

    // check whether that character is already present or not;
    bool containKey(char ch){
        return (links[ch-'a']!=NULL);
    }

    //to get the next node for traversal
    Node* get(char ch){
        return links[ch-'a'];
    }

    //creating reference trie and attaching it to 'ch'
    void create(char ch, Node* node){
         links[ch-'a'] = node;
    }

    void increaseEnd(){
        cntEndwith++;
    }

    void increasePrefix(){
        cntPrefix++;     
    }


    void deleteEnd(){
        cntEndwith--;
    }

    void reducePrefix(){
        cntPrefix--;
    }

    int getEnd(){
        return cntEndwith;
    }

    int getPrefix(){
        return cntPrefix;
    }

};

class Trie{
    private: Node* root;
    public:

    Trie(){
        // Write your code here.
        root = new Node();
    }

    void insert(string &word){
        // Write your code here.
        Node* node = root;
        for(int i = 0; i<word.length(); i++){
          if (!(node->containKey(word[i]))) {
            node->create(word[i], new Node());
          }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node* node = root;
        for(int i = 0; i<word.length(); i++){
                    if(!(node->containKey(word[i]))){
                            return 0;
                    }

                    //moves to reference trie
                    node = node->get(word[i]);
            }
       return node->getEnd();
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Node* node = root;
        for(int i = 0; i<word.length(); i++){
                    if(!(node->containKey(word[i]))){
                           return 0;
                    }

                    //moves to reference trie
                    node = node->get(word[i]);
            }
       return node->getPrefix();
    }

    void erase(string &word){
        // I am assuming that this word exist
        Node* node = root;
        for(int i = 0; i<word.length(); i++){    
                    node->reducePrefix();
                    //moves to reference trie
                    node = node->get(word[i]);
            }
       node->reducePrefix();
       node->deleteEnd();
    }
};


