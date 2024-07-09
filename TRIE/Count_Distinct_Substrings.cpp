class Node {
  Node *letter[26];

public:
  bool ispresent(char ch) { return letter[ch - 'a'] != NULL; }

  // creating reference trie and attaching it to 'ch'
  void create(char ch, Node *node) { letter[ch - 'a'] = node; }

  // to get the next node for traversal
  Node *next(char ch) { return letter[ch - 'a']; }
};

int count = 0;

class Trie {
private:
  Node *root;

public:
  Trie() { root = new Node(); }

  void insert(string word, int index) {
    Node *node = root;
    for (int i = index; i < word.length(); i++) {
      if (!node->ispresent(word[i])) {
        // create a Trie for that letter
        node->create(word[i], new Node());
        count++;
      }

      // moves to reference trie
      node = node->next(word[i]);
    }
  }
};

int countDistinctSubstrings(string &s) {
  //    Write your code here.
  Trie trie;
  count = 0;
  for (int i = 0; i < s.length(); i++) {
    trie.insert(s, i);
  }
  return count + 1;
}
