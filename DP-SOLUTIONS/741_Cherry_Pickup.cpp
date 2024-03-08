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
