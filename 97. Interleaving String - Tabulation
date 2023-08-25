class Solution {
public:
    int dp[101][101];
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length()+s2.length()!=s3.length()) return false;
        

        dp[0][0]=1;

        for(int i = 0; i<=s1.length(); i++){
            for(int j=0; j<=s2.length(); j++){
                    if(i==0&&j==0) continue;
                    else if(i>0 && s1[i-1]==s3[i+j-1] && j>0 &&s2[j-1]==s3[i+j-1]) dp[i][j] = dp[i-1][j] or dp[i][j-1];
                    else if(i>0 && s1[i-1]==s3[i+j-1]) dp[i][j]=dp[i-1][j];
                    else if(j>0 && s2[j-1]==s3[i+j-1]) dp[i][j]=dp[i][j-1];
                    else dp[i][j]=0;
            }
        }
        return dp[s1.length()][s2.length()];
    }
};
