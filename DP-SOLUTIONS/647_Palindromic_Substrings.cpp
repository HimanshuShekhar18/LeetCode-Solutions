// <-------------------------------------------------------------NAIVE APPROACH------------------------------------------------------------------------->
// TC: O(n^3)
// SC: O(n) in substr() and O(1) in two-pointer



class Solution {
public:

    bool solve(int i, int j, string &s){
        string str = s.substr(i,j-i+1);
        string strr = str;
        reverse(strr.begin(),strr.end());
        if(str==strr) return true;
        else return false;
    }

    int countSubstrings(string s) {
        int count = s.size();
        for(int i = 0; i<s.size(); i++){
            for(int j = i+1; j<s.size(); j++){
                if(solve(i,j,s)) count++;
            }
        }
        return count;
    }
};


// <--------------------------------------------------------------------DP--------------------------------------------------------------------------------------->


class Solution {
public:

// TOP-DOWN DP: RECURSION and MEMOIZATION 
// TC: O(n^2)
// SC: O(n^2)

    bool solve(int i, int j, string &s,vector<vector<int>> &dp){
       if(i>=j) return 1;
       if(dp[i][j]!=-1) return dp[i][j];

       int ans=0;
       if(s[i]==s[j]) ans = solve(i+1,j-1,s,dp);

       return dp[i][j]=ans;
    }

    int countSubstrings(string s) {
        vector<vector<int>> dp(s.size()+1,vector<int> (s.size()+1,-1));
        int count = s.size();
        for(int i = 0; i<s.size(); i++){
            for(int j = i+1; j<s.size(); j++){
                if(solve(i,j,s,dp)) count++;
            }
        }
        return count;
    }
};



// <--------------------------------------------------------------BOTTOM-UP: TABULATION--------------------------------------------------------------------------------->


class Solution {
public:

/* Bottom-Up: Tabulation 

Make a 2-D Matrix and start from bottom s.size()-1
i) for i>j dp[i][j] --> nothing neglect
ii) for i==j dp[i][j]=1 --> base case
iii) for i<j compute dp[i][j]

    for ag: ababa,
    the corresponding 2-D Matrix

                         0 1 2 3 4
                         a b a b a
                    0  a T _ _ _ _
                    1  b * T _ _ _
                    2  a * * T _ _
                    3  b * * * T _
                    4  a * * * * T

*/

// TC: O(n^2)
// SC: O(n^2) 

    int countSubstrings(string s) {
        vector<vector<int>> dp(s.size()+1,vector<int> (s.size()+1,-1));
        int count = 0;
        for(int i = s.size()-1; i>=0; i--){
            for(int j = i; j<s.size(); j++){
                if(i==j) dp[i][j]=1;
                else if(i+1==j){
                    dp[i][j] = s[i]==s[j]?1:0;
                }
                else {
                    dp[i][j] = s[i]==s[j]?dp[i+1][j-1]:0;
                }
                count+=dp[i][j];
            }
        }
        return count;
    }
};



























