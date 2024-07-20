
/*

String Hashing using Trie and 0/1 Knapsack DP ( Recursion and Memoization i.e. DFS ) --> TLE
TC: O(n*n) in worst case eg: target = "aaaaa"  and words = ["a", "aa", "aaa","aaaa","aaaaa"] type 
SC: O(n)
where n = 5*10^4

*/

struct Node {
    Node* letter[26];
    bool flag = false;
    int cost = INT_MAX;

    bool ispresent(char ch) { return letter[ch - 'a'] != NULL; }

    void create(char ch, Node* node) { letter[ch - 'a'] = node; }

    Node* next(char ch) { return letter[ch - 'a']; }

    void setEnd() { flag = true; }

    bool isEnd() { return flag; }
};

class Solution {

public:
    Node* root = new Node();
    int dp[100050];

    int solve(int index, string &target) {

        if (index == target.length()) return 0;

        if (dp[index] != -1) return dp[index];
        
        Node* node = root;  
        int mincost = INT_MAX;
        for (int i = index; i < target.length(); i++) {
            if(!node->ispresent(target[i])){
                break;
            }
            node = node->next(target[i]);
            if(node->isEnd()){
                if(solve(i+1, target)!=INT_MAX) mincost = min(mincost, node->cost + solve(i+1, target));
            }
        }
        return dp[index] = mincost;
    }

    int minimumCost(string target, vector<string>& words, vector<int>& costs) {

        for (int i = 0; i < words.size(); i++) {
            Node* node = root;
            for (int j = 0; j < words[i].length(); j++) {
                if (!node->ispresent(words[i][j])) {
                    node->create(words[i][j], new Node());
                }
                node = node->next(words[i][j]);
            }
            
            node->setEnd();
            node->cost = min(node->cost, costs[i]);
        }
        memset(dp, -1, sizeof(dp));
        int ans = solve(0, target);
        return ans==INT_MAX?-1:ans;
    }
};

