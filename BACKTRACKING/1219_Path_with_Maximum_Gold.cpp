class Solution {
public:

    int vis[20][20];

    int solve(int i, int j, vector<vector<int>> &grid ){

            int m = grid.size();
            int n = grid[0].size();

            if(grid[i][j]==0) return 0;
            if(vis[i][j]==1) return 0;

            int left = 0, right = 0, up = 0, down = 0;
            int ans = grid[i][j];
            vis[i][j]=1;

            if(j-1>=0) {
                left = solve(i,j-1,grid);
    
            }
            if(j+1<n){
                right = solve(i,j+1,grid);
                
            }
            if(i-1>=0){
                up = solve(i-1,j,grid);
              
            }
            if(i+1<m){
                down = solve(i+1,j,grid);
                
            }
            vis[i][j] = 0;
            return ans+max({left,right,up,down});

    }


    int getMaximumGold(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int ans = 0;

            for(int i = 0; i<m; i++){
                for(int j = 0; j<n; j++){
                    memset(vis,0,sizeof(vis));
                    ans=max(ans,solve(i,j,grid));
                }
            }
        return ans;
    }
};
