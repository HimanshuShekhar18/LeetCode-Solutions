// <--------------------------------------------------------------------DFS--------------------------------------------------------------------------->
/*
TC: O(V+2E)
SC: O(2E)
*/

class Solution {
public:
    
    void dfs(int node, vector<int>&vis, vector<vector<int>>&adj){
            vis[node]=1;

            for(int child: adj[node]){
                if(!vis[child]){
                    dfs(child,vis,adj);
                }
            }
        return;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n+1, vector<int> ());

        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(isConnected[i][j]==1){
                    adj[i+1].push_back(j+1);
                }
            }
        }

        vector<int> vis;
        vis.resize(n+1,0);
        int count = 0;
        for(int i = 1; i<=n; i++){
            if(!vis[i]){
                count++;
                dfs(i,vis,adj);
            }
        }
        return count;
    }
};



// <-------------------------------------------------------------BFS--------------------------------------------------------------------------------------->

/*
BFS 
TC: O(V+2E)
SC: O(2E)
  */


class Solution {
public:
    
    void bfs(int node, vector<int>&vis, vector<vector<int>>&adj, queue<int>&q){

            vis[node]=1;
            q.push(node);
            while(!q.empty()){

                int node = q.front();
                q.pop();

                for(int child: adj[node]){
                if(!vis[child]){
                    q.push(child);
                    vis[child]=1;
                }
            }
        } 
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n+1, vector<int> ());

        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(isConnected[i][j]==1){
                    adj[i+1].push_back(j+1);
                }
            }
        }

        queue<int> q;
        vector<int> vis;
        vis.resize(n+1,0);
        int count = 0;
        for(int i = 1; i<=n; i++){
            if(!vis[i]){
                count++;
                bfs(i,vis,adj,q);
            }
        }
        return count;
    }
};



