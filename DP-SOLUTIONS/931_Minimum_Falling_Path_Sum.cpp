class Solution {
public:

/*
2D-DP Top Down: Recursion and Memoization
TC: O(n*m) + O(m)
SC:O(n*m)
*/

    int n;
    int m;
   
    int solve(int row, int col, vector<vector<int>> &matrix, vector<vector<int>> &dp){
        if(row>=n) return 0;
        if(dp[row][col]!=-101) return dp[row][col];

        int value = matrix[row][col];

        int ans = INT_MAX;
        for(int i = -1; i<=1; i++){
            if(col+i>=0 && col+i<m) ans=min(ans,solve(row+1,col+i,matrix,dp));
        }
        
        return dp[row][col] = ans==INT_MAX?0:ans+value;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        

        n=matrix.size();
        m=matrix[0].size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, -101));
        int maxi = INT_MAX;

        for(int i = 0; i<m; i++){
            maxi=min(maxi,solve(0,i,matrix,dp));
        }

        return maxi;
    }
};



// <------------------------------------------------------------------------------------------------------------------------------------------------------------>



class Solution {
public:

/*
2D-DP Bottom-UP: Tabulation
TC: O(m*n*3) + O(m)
SC:O(n*m)
*/

    int n;
    int m;
    int minFallingPathSum(vector<vector<int>>& matrix) {
        

        n=matrix.size();
        m=matrix[0].size();
        vector<vector<int>> dp(n+1, vector<int> (m+1,0));
        
        // base cases 
        for(int j=0; j<m; j++){
            dp[0][j]=matrix[0][j];
        }

        for(int row = 1; row<n; row++){
            for(int col = 0; col<m; col++){
                    int value = matrix[row][col];

                    int ans = INT_MAX;

                    for(int i = -1; i<=1; i++){
                      if(col+i>=0 && col+i<m) ans=min(ans,dp[row-1][col+i]);
                    }
                dp[row][col] = ans==INT_MAX?0:ans+value;
            }
        }



        int maxi = INT_MAX;

        for(int i = 0; i<m; i++){
            maxi=min(maxi,dp[n-1][i]);
        }

        return maxi;
    }
};



// <------------------------------------------------------------SPACE OPTIMIAZTION------------------------------------------------------------------------->

class Solution {
public:

/*
2D-DP Bottom-UP: Tabulation Space Optimization
TC: O(m*n*3) + O(m)
SC:O(m)
*/

    int n;
    int m;
    int minFallingPathSum(vector<vector<int>>& matrix) {
        

        n=matrix.size();
        m=matrix[0].size();
        vector<int>prev(m+1,0);
        vector<int>curr(m+1,0);
        
        // base cases 
        for(int j=0; j<m; j++){
            prev[j]=matrix[0][j];
        }

        for(int row = 1; row<n; row++){
            for(int col = 0; col<m; col++){
                    int value = matrix[row][col];

                    int ans = INT_MAX;

                    for(int i = -1; i<=1; i++){
                      if(col+i>=0 && col+i<m) ans=min(ans,prev[col+i]);
                    }
                curr[col] = ans==INT_MAX?0:ans+value;
            }
            prev=curr;
        }

        int maxi = INT_MAX;

        for(int i = 0; i<m; i++){
            maxi=min(maxi,prev[i]);  // changes done here
        }

        return maxi;
    }
};







