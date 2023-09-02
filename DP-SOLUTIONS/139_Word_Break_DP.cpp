class Solution {
public:
   /* Recursion+Memoization
      Since we will visit each n states only once (size of dp) we also find substr which takes O(n) for each loop run takes O(n)
      T.C. Reduced to O(n^3) 
      SC: O(s.length*wordDict.length)
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


// <---------------------------------------------------O(n^2)----------------------------------------------------------------------------->

class Solution {
public:
    /*
    TC: O(n^2) 
    SC: O(s.length*wordDict.length)
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



