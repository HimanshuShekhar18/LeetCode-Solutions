class Solution {
public:
int dp[102][102];
    int uniquePaths(int m, int n) {
        memset(dp,0,sizeof(dp));
        for(int col = 0; col<n; col++){
            dp[0][col]=1;
        }
        for(int row = 0; row<m; row++){
            dp[row][0]=1;
        }
        for(int row = 1; row<m; row++){
            for(int col=1; col<n; col++){
               dp[row][col]=dp[row][col-1]+dp[row-1][col];
            }
        }
        return dp[m-1][n-1];
    }
};

        
