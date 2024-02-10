class Solution {
public:

/*
Reverse the string treat it as second string and 
find the lcs b/w original string and reversed string
*/

// TC: O(n*m)
// SC: O(n*m)

    int lps(string s, string str){
        int n = s.size();
        int m = str.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));

        for(int i = 0; i<n; i++){
            dp[i][0] = 0;
        }


        for(int i = 0; i<m; i++){
            dp[0][i] = 0;
        }

        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(s[i-1]==str[j-1]) {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }

    int longestPalindromeSubseq(string s) {
        string str = s;
        reverse(str.begin(),str.end());
        return lps(s,str);
    }
};
