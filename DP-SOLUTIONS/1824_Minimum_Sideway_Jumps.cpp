class Solution {
public:
    int cnt = 0;
    int dp[5*100000+5][3];
    int n;
    int jumps(int index, int lane,vector<vector<int>>&grid){
        if(index==n) return 0;
        if(dp[index][lane]!=-1) return dp[index][lane];
        int ans = 0;
        if(grid[index+1][lane]==0){
            ans+=jumps(index+1,lane,grid);
        } 
        if(grid[index+1][lane]!=0){
                /*
                _R_
                _F_
                */
                if(lane == 1){
                 if(grid[index][lane-1]==0 && grid[index][lane+1]==0) ans+=min(jumps(index+1,lane+1,grid)+1,jumps(index+1,lane-1,grid)+1);
                 else if(grid[index][lane+1]!=0) ans+=1+jumps(index+1,lane-1,grid);
                 else if(grid[index][lane-1]!=0) cnt++, ans+=1+jumps(index+1,lane+1,grid);
                }
                else if(lane==2){
                 if(grid[index][lane-1]==0 && grid[index][lane-2]==0) ans+=min(jumps(index+1,lane-1,grid)+1,jumps(index+1,lane-2,grid)+1);
                 else if(grid[index][lane-1]!=0) ans+=1+jumps(index+1,lane-2,grid);
                 else if(grid[index][lane-2]!=0) cnt++, ans+=1+jumps(index+1,lane-1,grid); 

                }
                else if(lane == 0){
                 if(grid[index][lane+1]==0 && grid[index][lane+2]==0) ans+=min(jumps(index+1,lane+1,grid)+1,jumps(index+1,lane+2,grid)+1);
                 else if(grid[index][lane+1]!=0) ans+=1+jumps(index+1,lane+2,grid);
                 else if(grid[index][lane+2]!=0) ans+=1+jumps(index+1,lane+1,grid);
                }
        }
        return dp[index][lane]=ans;
    }
    int minSideJumps(vector<int>& obstacles) {
        n = obstacles.size();
        vector<vector<int>> grid(n,vector<int>(3,0));
        memset(dp,-1,sizeof(dp));
        
        for(int i = 0; i<n; i++){
            if(obstacles[i]!=0){
                grid[i][obstacles[i]-1] = 1;
            }
        }

        //  for(int i = 0; i<n; i++){
        //     for(int j = 0; j<3; j++){
        //         cout << grid[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        n--;

        
        return jumps(0,1,grid);
    }
};
