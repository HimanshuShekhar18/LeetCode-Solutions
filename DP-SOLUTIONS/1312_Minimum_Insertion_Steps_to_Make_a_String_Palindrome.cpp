class Solution {
public:

    int solve(string str, string s){
        int n = str.length();
        int m = s.length();

        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

        for(int i = 0; i<m; i++){
            dp[0][i] = 0;
        }
        for(int j = 0; j<n; j++){
            dp[j][0] = 0;
        }

        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){

                if(str[i-1]==s[j-1]) dp[i][j] = 1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

            }
        }

        return dp[n][m];
    }

    int lps(string s){
        string str = s;
        reverse(str.begin(),str.end());
        cout << solve(str,s) << endl;
        return solve(str,s);
    }

    int minInsertions(string s) {

        return s.length()-lps(s);
        
    }
};



<--------------------------------------------------------------SPACE OPTIMIZATION---------------------------------------------------------------------------->


class Solution {
public:

    int solve(string str, string s){
        int n = str.length();
        int m = s.length();

        vector<int> prev(n+1,0);
        vector<int> curr(n+1,0);

        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){

                if(str[i-1]==s[j-1]) curr[j] = 1+prev[j-1];
                else curr[j]=max(prev[j],curr[j-1]);

            }
            prev = curr;
        }

        return prev[m];
    }

    int lps(string s){
        string str = s;
        reverse(str.begin(),str.end());
    
        return solve(str,s);
    }

    int minInsertions(string s) {

        return s.length()-lps(s);
        
    }
};


