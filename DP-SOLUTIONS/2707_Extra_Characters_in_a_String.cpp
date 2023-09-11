class Solution {
public:
    /* Recursion+Memoization
    TC: O(n^2) = O(dp_states*for_loop)
    SC: O(n(dp)+dictionary.length()+n(stack space))
    */
    int n;
    unordered_set<string> words;
    int dp[51];
    int solve(int ind, string &s){
        if(ind>=n){
            return 0;
        }
        if(dp[ind]!=-1) return dp[ind];        
        int minextra = n;
        string temp = "";
        for(int i = ind; i<n; i++){
            temp.push_back(s[i]);    // O(1)
            int currextra = 0;
            if(words.find(temp)==words.end()) currextra = temp.length();
            int totalextra = currextra+solve(i+1,s);
            minextra = min(minextra,totalextra);
        }
        return dp[ind]=minextra;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        n = s.length();
        words.clear();
        memset(dp,-1,sizeof(dp));
        words.insert(dictionary.begin(), dictionary.end());  // for comparison
        return solve(0,s);
    }
};

