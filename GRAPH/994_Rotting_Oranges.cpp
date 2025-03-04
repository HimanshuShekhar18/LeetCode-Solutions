class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,pair<int,int>>> q;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]==2){
                    q.push({i,{j,0}});
                }
            }
        }

        vector<pair<int,int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        int ans = 0;
        while(!q.empty()){
                int currow = q.front().first;
                int curcol = q.front().second.first;
                int currentlevel = q.front().second.second;
                ans = currentlevel;
                q.pop();

                for(auto dir: directions){
                    int row = currow+dir.first;
                    int col = curcol+dir.second;

                    if(row>=0 && col>=0 && row<m && col<n && grid[row][col]==1){
                        q.push({row,{col,currentlevel+1}});
                        grid[row][col]=2;
                    }
                }
        }

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return ans;
    }
};
