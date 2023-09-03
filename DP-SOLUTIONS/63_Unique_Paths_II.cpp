class Solution {
public:

// TABULATION APPROACH
// TC: O(n^2)
// SC: O(n^2)

int m,n;
int dp[102][102];

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m=obstacleGrid.size();
        n=obstacleGrid[0].size();
        memset(dp,0,sizeof(dp));
        if(obstacleGrid[0][0]==1) return 0;
        if(obstacleGrid[m-1][n-1]==1) return 0;

        dp[0][0]=1;

        for(int row=1; row<m; row++){
            if(obstacleGrid[row][0]!=1){
                dp[row][0]=dp[row][0]+dp[row-1][0];
            }
        }

         for(int col=1; col<n; col++){
            if(obstacleGrid[0][col]!=1){
                dp[0][col]=dp[0][col]+dp[0][col-1];
            }
        }

        for(int row = 1; row<m; row++){
            for(int col=1; col<n; col++){
                 
                if(obstacleGrid[row][col]==1) dp[row][col]=0;
                else dp[row][col]=dp[row-1][col]+dp[row][col-1];
            }
        }

        return dp[m-1][n-1];
        
    }
};
