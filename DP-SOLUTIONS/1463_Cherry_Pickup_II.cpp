class Solution {
public:

/*
3D-DP: Recurison and Memoization
TC: O(n*m*m*9)
SC: O(n*m**m)
*/


int dp[72][72][72];
vector<vector<int>> movements = {{1,-1},{1,0,},{1,1,}};

    int solve(int n, int m, int row, int col1, int col2, vector<vector<int>> &grid){
        if(row>=n) return 0;
        if(dp[row][col1][col2]!=-1) return dp[row][col1][col2];

        int cheery=0;
        if(col1==col2) cheery+=grid[row][col1];
        else cheery+=grid[row][col1]+grid[row][col2];
        int ans = 0;
        for(auto movement: movements){
            for(auto movement1: movements){
            if(col1+movement[1]>=0 && col1+movement[1]<m && col2+movement1[1]>=0 && col2+movement1[1]<m)
            ans=max(ans,solve(n,m,row+1,col1+movement[1],col2+movement1[1],grid));
           }
        }
          return dp[row][col1][col2]=ans+cheery;
        }


    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int n = grid.size();
        int m = grid[0].size();
        return solve(n,m,0,0,m-1,grid);
    }
};


// <-------------------------------------------------------------------------------------------------------------------------------------------------------->

class Solution {
public:

/*
3D-DP: Bottom-Up Tabulation
TC: O(n*m*m*9)
SC: O(n*m**m)
*/


int dp[72][72][72];
vector<vector<int>> movements = {{-1,-1},{-1,0,},{-1,1,}};

   int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,0,sizeof(dp));
        int n = grid.size();
        int m = grid[0].size();

        for(int row = 0; row<n; row++){
            for( int col1 = 0; col1<=min(row,m-1); col1++){
                for(int col2 = max(0,m-row-1); col2<m; col2++){

                    int maxPrevrow = 0;

                   for(auto movement: movements){
                      for(auto movement1: movements){
                         if(row>0 && col1+movement[1]>=0 && col1+movement[1]<m && col2+movement1[1]>=0 && col2+movement1[1]<m)
                          maxPrevrow=max(maxPrevrow,dp[row-1][col1+movement[1]][col2+movement1[1]]);
                        }
                    }

                    if(col1!=col2){
                        dp[row][col1][col2]+=maxPrevrow+grid[row][col1]+grid[row][col2];
                    }
                    else{
                        dp[row][col1][col2]+=maxPrevrow+grid[row][col1];
                    }
                }
            }
        }

        int result = 0;

        
        for(int i = 0; i<m; i++ ){
            for( int j = 0; j<m; j++){
                result = max(result,dp[n-1][i][j]);
            }
        }
        return result;
    }
};




// <----------------------------------------------------------------------------------------------------------------------------------------------------------->


class Solution {
public:

/*
2D-DP: Bottom-Up Tabulation Space Optimization
TC: O(n*m*m*9)
SC: O(m**m)
*/



vector<vector<int>> movements = {{-1,-1},{-1,0,},{-1,1,}};

   int cherryPickup(vector<vector<int>>& grid) {
    
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> prev (m+1, vector<int> (m+1,0));
        vector<vector<int>> curr (m+1, vector<int> (m+1,0));


        for(int row = 0; row<n; row++){
            for( int col1 = 0; col1<=min(row,m-1); col1++){
                for(int col2 = max(0,m-row-1); col2<m; col2++){

                    int maxPrevrow = 0;

                   for(auto movement: movements){
                      for(auto movement1: movements){
                         if(row>0 && col1+movement[1]>=0 && col1+movement[1]<m && col2+movement1[1]>=0 && col2+movement1[1]<m)
                          maxPrevrow=max(maxPrevrow,prev[col1+movement[1]][col2+movement1[1]]);
                        }
                    }

                    if(col1!=col2){
                        curr[col1][col2]=maxPrevrow+grid[row][col1]+grid[row][col2];
                    }
                    else{
                        curr[col1][col2]=maxPrevrow+grid[row][col1];
                    }
                }
            }
            prev=curr;
        }

        int result = 0;


        for(int i = 0; i<m; i++ ){
            for( int j = 0; j<m; j++){
                result = max(result,curr[i][j]);
            }
        }
        return result;
    }
};






