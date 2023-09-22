#include<bits/stdc++.h>
using namespace std;

/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

 struct Node{
     Node* letter[26];
     bool flag = false;

     bool ispresent(char ch){
         return letter[ch-'a']!=NULL;
     }

     //creating reference trie and attaching it to 'ch'
     void create(char ch, Node* node){
         letter[ch-'a'] = node;
     }

     //to get the next node for traversal
     Node* next(char ch){
         return letter[ch-'a'];
     }

     //setting flag to true at the end of the word
     void setEnd(){
         flag = true;
     }


     bool isEnd(){
         return flag;
     }


 };


class Trie {

    private:
    Node* root;

public:

    /** Initialize your data structure here. */
    Trie() {

        root = new Node();
    }

    /** Inserts a word into the trie. */
    // Time Complexity: O(n)
    void insert(string word) {
            Node* node = root;
            for(int i = 0; i<word.length(); i++){
                    if(!node->ispresent(word[i])){
                            // create a Trie for that letter
                            node->create(word[i],new Node());
                    }

                    //moves to reference trie
                    node = node->next(word[i]);
            }

            node->setEnd();
    }

    /** Returns if the word is in the trie. */
    // Time Complexity: O(n)
    bool search(string word) {
        Node* node = root;
        for(int i = 0; i<word.length(); i++){
                    if(!node->ispresent(word[i])){
                            return false;
                    }

                    //moves to reference trie
                    node = node->next(word[i]);
            }

            return node->isEnd();

    } 

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
         Node* node = root;
        for(int i = 0; i<prefix.length(); i++){
                    if(!node->ispresent(prefix[i])){
                            return false;
                    }

                    //moves to reference trie
                    node = node->next(prefix[i]);
            }

            return true;

    }
};


int main()
{
	int n = 5;
	vector<int>type = {1, 1, 2, 3, 2};
	vector<string>value = {"hello", "help", "help", "hel", "hel"};
	Trie trie;
	for (int i = 0; i < n; i++) {
		if (type[i] == 1) {
			trie.insert(value[i]);
		}
		else if (type[i] == 2) {
			if (trie.search(value[i])) {
				cout << "true" << "\n";
			}
			else {
				cout << "false" << "\n";
			}
		}
		else {
			if (trie.startsWith(value[i])) {
				cout << "true" << "\n";
			}
			else {
				cout << "false" << "\n";
			}
		}
	}
}
