class Solution {
public:


    int dp[201][201];
    int n, m;

    int solve(int row, int col, vector<vector<int>> &grid){
        if(row>=m || col>=n ) return INT_MAX;
        if(row==m-1 && col==n-1) return grid[row][col];
        if(dp[row][col]!=-1) return dp[row][col];

        int value = grid[row][col];

        int temp=min(solve(row,col+1,grid),solve(row+1,col,grid));

        if(temp!=INT_MAX) value+=temp;

        return dp[row][col]=value;
    }
    int minPathSum(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();
        memset(dp,-1,sizeof(dp));

        return solve(0,0,grid);       
        
    }
};



// <-------------------------------------------------------------------------TABULATION--------------------------------------------------------------------------->


class Solution {
public:

    int dp[201][201];
    int n, m;
    int minPathSum(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();
        memset(dp,-1,sizeof(dp));
        dp[0][0]=grid[0][0];
        for(int i = 1; i<n; i++){
            dp[0][i]=grid[0][i]+dp[0][i-1];
        }
        for(int i = 1; i<m; i++){
            dp[i][0]=grid[i][0]+dp[i-1][0];
        }

        for(int i = 1; i<m; i++){
            for(int j = 1; j<n; j++){
                int value = grid[i][j];
                dp[i][j]=value+min(dp[i][j-1],dp[i-1][j]);;
            }
        }
        return dp[m-1][n-1];       
    }
};











