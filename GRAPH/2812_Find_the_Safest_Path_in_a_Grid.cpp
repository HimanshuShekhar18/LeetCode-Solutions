class Solution {
public:

int lev[401][401];
int vis[401][401];
int n;

vector<pair<int,int>> movements = {{-1,0}, {1,0}, {0,-1}, {0,1}};

int msbfs(vector<vector<int>> &grid){

    queue<pair<int,int>> q;

    for(int i = 0; i<grid.size(); i++){
        for(int j = 0; j<grid.size(); j++){
            if(grid[i][j]==1){ 
                q.push({i,j});
                vis[i][j] = 1;
            }
        }
    }

    int n = grid.size();

    while(!q.empty()){

        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(auto movement: movements){

                int childx = x + movement.first;
                int childy = y + movement.second;

                if(childx<0 || childx >=n || childy<0 || childy >=n ) continue;

                if(!vis[childx][childy]){
                    lev[childx][childy]=lev[x][y]+1;
                    vis[childx][childy]=1;
                    q.push({childx,childy});
                }
        }
    }

    int maxi = 0;
    for(int i = 0; i<grid.size(); i++){
        for(int j = 0; j<grid.size(); j++){
            maxi=max(maxi,lev[i][j]);
        }
    }

    return maxi;

}



    int maximumSafenessFactor(vector<vector<int>>& grid) {
      
        n = grid.size();
        if(grid[0][0] || grid[n-1][n-1]) return 0;
        memset(vis,0,sizeof(vis));
        memset(lev,0,sizeof(lev));

        msbfs(grid);

        // Now i have got Minimum Manhattan Distance for each cell 

        // now i will greedly move for those direction having maximum manhattan distance and getting minimum of them using MAX-Heap

        
        priority_queue<pair<int,pair<int,int>>> q;

        memset(vis,0,sizeof(vis));

        q.push({lev[0][0],{0,0}});

        while(!q.empty()){
           pair<int,pair<int,int>> p = q.top();
           
           int dist = p.first;
           int x = p.second.first;
           int y = p.second.second;

            if(x==n-1 && y==n-1) return dist;

            q.pop();

            for(auto movement: movements){

                int childx = x + movement.first;
                int childy = y + movement.second;

                if(childx<0 || childx>=n || childy<0 || childy>=n || vis[childx][childy] == 1 ) continue;

                q.push({min(dist,lev[childx][childy]),{childx,childy}});
                vis[childx][childy] = 1;
            }
        }

        return 0;

    }
};

