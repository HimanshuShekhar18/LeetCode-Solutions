class Solution {
public:


/*
2D-DP Recursion and Memoization Top Down 
TC: O(m*n) 
SC: O(m*n) 
*/

    int solve(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<int>> &dp){
        if(i<0 || i>m || j>n ) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans1 = 0, ans2 = 0, ans3 = 0;
        if(i-1>=0 && j+1<n && grid[i-1][j+1]>grid[i][j]) ans1 = ans1 + 1 + solve(i-1,j+1,n,m,grid,dp);
        if( j+1<n && grid[i][j+1]>grid[i][j]) ans2 = ans2 + 1 + solve(i,j+1,n,m,grid,dp);
        if(i+1<m && j+1<n && grid[i+1][j+1]>grid[i][j]) ans3 = ans3 + 1 + solve(i+1,j+1,n,m,grid,dp);

        return dp[i][j]=max({dp[i][j],ans1,ans2,ans3});

    }

    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int> (n, -1));
        int ans = 0;
        for(int i = 0; i<m; i++){
            ans = max(ans, solve(i, 0, n, m, grid,dp));
        }
        return ans;
    }
};



// <------------------------------------------------------------------------TABULATION-------------------------------------------------------------------------------------------------->



class Solution {
public:

/*
Bottom-Up DP Tabulation (i-1,j-1), (i,j-1) and (i+1,j-1)
TC: O( m*n)
SC: O(m*n)
*/

    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0; i<m; i++){
            dp[i][0]=1;
        }
        int ans = 0;
        for (int j = 1; j <n; j++) {
            for (int i = 0; i <m; i++) {
                int ans1 = 0, ans2 = 0, ans3 = 0;
                if (i - 1 >= 0 && j - 1 >= 0 && grid[i - 1][j - 1] < grid[i][j] && dp[i-1][j-1]!=0)
                    ans1 = ans1 + 1 + dp[i - 1][j - 1];
                if (j - 1 >= 0 && grid[i][j - 1] < grid[i][j] && dp[i][j-1]!=0)
                    ans2 = ans2 + 1 + dp[i][j - 1];
                if (i + 1 < m && j - 1 >=  0 && grid[i + 1][j - 1] < grid[i][j] && dp[i+1][j-1]!=0)
                    ans3 = ans3 + 1 + dp[i + 1][j - 1];
                dp[i][j] = max({dp[i][j], ans1, ans2, ans3});
                ans=max(ans,dp[i][j]-1);
            }
        }
        return ans;
    }
};



// <------------------------------------------------------------------------------SPACE OPTIMIZED---------------------------------------------------------------------------------------------->


class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> prev(m, 1);
        vector<int> curr(m, 0);
        int ans = 0;
        for (int j = 1; j <n; j++) {
            for (int i = 0; i <m; i++) {
                int ans1 = 0, ans2 = 0, ans3 = 0;
                if (i - 1 >= 0 && j - 1 >= 0 && grid[i - 1][j - 1] < grid[i][j] && prev[i-1]!=0)
                    ans1 = ans1 + 1 + prev[i - 1];
                if (j - 1 >= 0 && grid[i][j - 1] < grid[i][j] && prev[i]!=0)
                    ans2 = ans2 + 1 + prev[i];
                if (i + 1 < m && j - 1 >=  0 && grid[i + 1][j - 1] < grid[i][j] && prev[i+1]!=0)
                    ans3 = ans3 + 1 + prev[i + 1];
                curr[i] = max({ans1, ans2, ans3});
                ans=max(ans,curr[i]-1);
            }
            prev=curr;
        }
        return ans;
    }
};






