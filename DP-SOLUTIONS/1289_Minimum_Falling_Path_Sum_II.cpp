class Solution {
public:

/*

Read Question Carefully 
In each row, you have to check for all other columns ( 0 to m-1 ) expect for current column

In 931. Minimum Falling Path Sum 
we have to just check for j-1, j and j+1 column

TC: O(n*m*m) + O(m)
SC: O(n*m)


*/

    int n , m;
    int solve(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(row>=n) return 0;
        if(dp[row][col]!=-1e9) return dp[row][col];

        int value = grid[row][col];
        int res = INT_MAX;
        for(int i = 0; i<m; i++){

            // don't select the current column
            if(i!=col) res=min(res,solve(row+1,i,grid,dp)); 
        }       

        return dp[row][col]= ((res==INT_MAX)?0:res) + value;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1e9));
        int ans = INT_MAX;
        for(int i = 0; i<m; i++){
            ans = min(ans,solve(0,i,grid,dp));
        }
        return ans;
    }
};



// <------------------------------------------------------------------------------------------------------------------------------------------------------------>



class Solution {
public:

/*

TABULATION
TC: O(n*m*m) + O(m)
SC: O(n*m)


*/

    int n , m;
    
    int minFallingPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

        for(int i = 0; i<m; i++) dp[0][i] = grid[0][i];

        for(int i = 1; i<n; i++){
            for(int j = 0; j<m; j++){
                 int value = grid[i][j];
                 int res = INT_MAX;
                 for(int k = 0; k<m; k++){
                    if(k!=j) res=min(res,dp[i-1][k]);
                 }
                dp[i][j]= ((res==INT_MAX)?0:res) + value;
            }
        }

        int ans = INT_MAX;
        for(int i = 0; i<m; i++){
            ans = min(ans,dp[n-1][i]);
        }
        return ans;
    }
};

























