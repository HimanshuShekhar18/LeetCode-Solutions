class Solution {
public:
   /*
   Recursion+Memoization Top Down
   T.C. Reduced to O(n^2) 
   SC: O(s.length+wordDict.length)
   */
    int n;
    unordered_set<string> words;
    int dp[301];
    bool solve(int ind, string &s){
        if(ind==n){
            return true;
        }

        if(dp[ind]!=-1) return dp[ind];

        if(words.find(s.substr(ind,n-ind)) != words.end()) return true;

        for(int l = 1; l<=n-ind; l++){
            string temp = s.substr(ind,l);
            if(words.find(temp)!=words.end() && solve(ind+l,s)) return dp[ind]=true;
        }
        return dp[ind]=false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length();
        memset(dp,-1,sizeof(dp));
        words.insert(wordDict.begin(), wordDict.end());  // for comparison
        return solve(0,s);
    }
};


// <--------------------------------------------------------------------------------------------------------- without using substr() ----------------------------------------------------------------------------------------------------------------------------->

class Solution {
public:
    /*
       Recursion+Memoization without using "substr" instead use push_back()
      TC: O(n^2) 
      SC: O(s.length+wordDict.length)
    */
    int n;
    unordered_set<string> words;
    int dp[301];
    bool solve(int ind, string &s){
        if(ind==n){
            return true;
        }

        if(dp[ind]!=-1) return dp[ind];

        if(words.find(s.substr(ind,n-ind)) != words.end()) return true;
        string temp = "";
        for(int i = ind; i<n; i++){
            temp.push_back(s[i]);
            if(words.find(temp)!=words.end() && solve(i+1,s)) return dp[ind]=true;
        }
        return dp[ind]=false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length();
        memset(dp,-1,sizeof(dp));
        words.insert(wordDict.begin(), wordDict.end());  // for comparison
        return solve(0,s);
    }
};



// <-----------------------------------------------------------------------------------------------------DP ON TRIE ( STRING ) --------------------------------------------------------------------------------------------------------->

/*
DP on TRIE ( STRING )
TC: O(n + wordDict.length()*wordDict[i]) 
SC: O(n + wordDict.length()*wordDict[i]) 
*/

struct Node {
    Node* letter[26];
    bool flag = false;

    bool ispresent(char ch) { return letter[ch - 'a'] != NULL; }

    void create(char ch, Node* node) { letter[ch - 'a'] = node; }

    Node* next(char ch) { return letter[ch - 'a']; }

    void setEnd() { flag = true; }

    bool isEnd() { return flag; }
};

class Solution {
private:
    Node* root = new Node();

public:
    bool wordBreak(string s, vector<string>& wordDict) {

        for (auto word : wordDict) {
            Node* node = root;
            for (int i = 0; i < word.length(); i++) {
                if (!node->ispresent(word[i])) {

                    node->create(word[i], new Node());
                }
                node = node->next(word[i]);
            }
            node->setEnd();
        }

        vector<bool> dp(s.length(), 0);

        for (int i = 0; i < s.length(); i++) {
            if (i == 0 || dp[i - 1] == 1) {
                Node* node = root;
                for (int j = i; j < s.length(); j++) {
                    if(!node->ispresent(s[j])) break;
                    node=node->next(s[j]);
                    if(node->isEnd()) dp[j]=true;
                }
            }
        }

        return dp[s.length()-1];
    }
};


