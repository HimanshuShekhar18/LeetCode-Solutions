class Solution {
public:

/*

 3D-DP 

 Left and Up is equivalent to Right and Bottom

 So Two Time Recursion will start from (0,0)

 So for that we use 2 persons

 (r1-0)+(c1-0)=(r2-0)+(c2-0)

 r2 = r1+(c1-c2)

 -->   -->
 -->    ↓
  ↓     ↓
  ↓    -->

 Recursion and Memoization
 TC: O(n^3)*4
 SC: O(n^3)*4

*/
    int n;
    long long dp[51][51][51];

    int solve(int r1, int c1, int c2, vector<vector<int>> &grid){
        int r2 = r1+(c1-c2);
        if(r1>=n || r2>=n || c1>=n || c2>=n || grid[r1][c1]==-1 || grid[r2][c2]==-1 ) return INT_MIN;
        if(dp[r1][c1][c2]!=-1) return dp[r1][c1][c2];
        if(r1==n-1 && c1 == n-1) return grid[r1][c1];
        long long value = grid[r1][c1];
        if(c1!=c2) value+=grid[r2][c2];

        value+= max({solve(r1,c1+1,c2+1,grid),solve(r1,c1+1,c2,grid),solve(r1+1,c1,c2,grid),solve(r1+1,c1,c2+1,grid)});
        
        return dp[r1][c1][c2]=value;        
    }

    int cherryPickup(vector<vector<int>>& grid) {
        n=grid.size();
        memset(dp,-1,sizeof(dp));
        return max(0,solve(0,0,0,grid));
    }   
};



// <---------------------------------------------------------------BOTTOM-UP TABULATION-------------------------------------------------------------------------->



class Solution {
public:

/*

 3D-DP 
 BOTTOM - UP TABULATION

 TC: O(n^3)
 SC: O(n^3)

 In Top-Down we started from Top-Leftmost cell,
 In Bottom-Up, From Bottom-Right cell we  Starts and looks for Right and Down

 (r1-0)+(c1-0)=(r2-0)+(c2-0)

 r2 = r1+(c1-c2)

 -->   -->
 -->    ↓
  ↓     ↓
  ↓    -->

*/
    int n;
    int dp[51][51][51];   

    int cherryPickup(vector<vector<int>>& grid) {
        n=grid.size();
        int r2;
        memset(dp,0,sizeof(dp));

        dp[n-1][n-1][n-1]=grid[n-1][n-1];

        for(int r1 = n-1; r1>=0; r1--){
            for(int c1 = n-1; c1>=0; c1--){
                for(int c2 = n-1; c2>=0; c2--){

                    r2 = r1+(c1-c2);

                    if( r2<0 || r2>=n || grid[r1][c1]==-1 || grid[r2][c2]==-1 ) {
                        dp[r1][c1][c2]=INT_MIN;
                        continue;
                    }
                    
                    int value = grid[r1][c1];
                    if(c1!=c2) value+=grid[r2][c2];

                    int cheerypick = INT_MIN;

                    if(r1+1<n) cheerypick = max(cheerypick,dp[r1+1][c1][c2]);
                    if(r1+1<n && c2+1<n) cheerypick = max(cheerypick,dp[r1+1][c1][c2+1]);
                    if(c1+1<n) cheerypick = max(cheerypick,dp[r1][c1+1][c2]);
                    if(c1+1<n && c2+1<n) cheerypick = max(cheerypick,dp[r1][c1+1][c2+1]);


                    // no paths possible
                    if(cheerypick==INT_MIN ) {
                        // Neglecting the bottom right cell dp[n-1][n-1][n-1]=grid[n-1][n-1];
                        if(r1!=n-1 || c1!=n-1 || c2!=n-1)  dp[r1][c1][c2] = INT_MIN; 
                    }
                    // path possible 
                    else
                    {
                        value+=cheerypick;
                        dp[r1][c1][c2]=value;
                    }
                }
            }
        }
        return max(0,dp[0][0][0]);
    }   
};



