class Solution {
public:
/*
Simple DFS on Matrix
TC: O(n*m)
SC: O(n*m)
*/
    int m;
    int n;
    bool dfs(int i, int j, vector<vector<int>> &grid1, vector<vector<int>> &grid2, vector<vector<int>> &vis){
       
        vis[i][j]=1;
        grid2[i][j]=0;
        bool up = true;
        if(i-1>=0 && vis[i-1][j]==0){
            if(grid2[i-1][j]==1){
                if(grid1[i-1][j]==1){
                    up=dfs(i-1,j,grid1,grid2,vis);
                }
                else{
                    up = false;
                    dfs(i-1,j,grid1,grid2,vis);
                }
            }
        }

        bool left = true;
        if(j-1>=0 && vis[i][j-1]==0){
            if(grid2[i][j-1]==1){
                if(grid1[i][j-1]==1){
                    left=dfs(i,j-1,grid1,grid2,vis);
                }
                else{
                    left = false;
                    dfs(i,j-1,grid1,grid2,vis);
                }
            }
        }

        bool bottom = true;
        if(i+1<m && vis[i+1][j]==0){
            if(grid2[i+1][j]==1){
                if(grid1[i+1][j]==1){
                   bottom = dfs(i+1,j,grid1,grid2,vis);
                }
                else{
                   bottom = false;
                   dfs(i+1,j,grid1,grid2,vis);
                }
            }
        }

        bool right = true;
        if(j+1<n  && vis[i][j+1]==0){
            if(grid2[i][j+1]==1){
                if(grid1[i][j+1]==1){
                    right = dfs(i,j+1,grid1,grid2,vis);
                }
                else{
                    right = false;
                    dfs(i,j+1,grid1,grid2,vis);
                }
            }
        }


        return up&left&bottom&right;

    }


    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {

        m = grid1.size();
        n = grid1[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid2[i][j] == 1 && grid1[i][j]==1) {
                    if (!vis[i][j]) {
                        
                        if(dfs(i,j,grid1,grid2,vis)){
                            count++;
                        }
                    }
                }
            }
        }

        return count;
    }
};



