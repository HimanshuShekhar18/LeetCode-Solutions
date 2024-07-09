#include <bits/stdc++.h>

struct Node
{
public:
      Node *letters[26];
      bool flag = false;

      bool ispresent(char ch) { return letters[ch - 'a'] != NULL; }

      void create(char ch, Node *node) { letters[ch - 'a'] = node; }

      Node *next(char ch) { return letters[ch - 'a']; }

      void setEnd() { flag = true; }

      bool isEnd() { return flag; }
};

class Trie
{

private:
      Node *root;

public:
      Trie() { root = new Node(); }

      void insert(string word)
      {
            Node *node = root;
            for (int i = 0; i < word.length(); i++)
            {
                  if (!node->ispresent(word[i]))
                  {
                        node->create(word[i], new Node());
                  }
                  node = node->next(word[i]);
            }
            node->setEnd();
      }

      bool checkallprefixexist(string word)
      {

            Node *node = root;
            for (int i = 0; i < word.length(); i++)
            {

                  if (node->ispresent(word[i]))
                  {
                        node = node->next(word[i]);
                        if (node->isEnd() == false)
                              return false;
                  }
                  else
                        return false;
            }
            return true;
      }
};

string completeString(int n, vector<string> &a)
{
      // Write your code here.

      Trie trie;

      for (auto it : a)
      {
            trie.insert(it);
      }

      string longest = "";
      for (auto it : a)
      {
            if (trie.checkallprefixexist(it))
            {
                  if (it.length() > longest.length())
                  {
                        longest = it;
                  }
                  else if (it.length() == longest.length())
                  {
                        if (it < longest)
                        {
                              longest = it;
                        }
                  }
            }
      }

      if (longest.length() == 0)
      {
            return "None";
      }
      else
      {
            return longest;
      }
}
