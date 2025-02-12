
// <----------------------------------------------------------BFS----------------------------------------------------------------------------------------->

class Solution {

     void bfs(int node, ArrayList<Integer> vis, ArrayList<ArrayList<Integer>> adj){

            Queue<Integer> q = new LinkedList<Integer> ();
            vis.set(node,1);
            q.add(node);
            while(!q.isEmpty()){

                int parent = q.poll();
            
                for(int child: adj.get(parent)){
                if(vis.get(child)==0){
                    q.add(child);
                    vis.set(child,1);
                }
            }
        } 
    }

    public int findCircleNum(int[][] isConnected) {

        int n = isConnected.length;
        ArrayList<ArrayList<Integer>> adj = new ArrayList<ArrayList<Integer>> ();

        for(int i = 0;i <=n; i++){
            adj.add(new ArrayList<Integer> ());
        }

        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(isConnected[i][j]==1){
                    adj.get(i+1).add(j+1);
                }
            }
        }

        ArrayList<Integer> vis = new ArrayList<Integer> (Collections.nCopies(n+1,0));
        
        int count = 0;
        for(int i = 1; i<=n; i++){
            if(vis.get(i)==0){
                count++;
                bfs(i,vis,adj);
            }
        }
        return count;
    }
}

    
   
// <-----------------------------------------------------------------DFS----------------------------------------------------------------------------------->


class Solution {

     void dfs(int node, ArrayList<Integer> vis, ArrayList<ArrayList<Integer>> adj){

            vis.set(node,1);
            
                for(int child: adj.get(node)){
                if(vis.get(child)==0){
                    dfs(child,vis,adj);                    
                }
            }
    }

    public int findCircleNum(int[][] isConnected) {

        int n = isConnected.length;
        ArrayList<ArrayList<Integer>> adj = new ArrayList<ArrayList<Integer>> ();

        for(int i = 0;i <=n; i++){
            adj.add(new ArrayList<Integer> ());
        }

        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(isConnected[i][j]==1){
                    adj.get(i+1).add(j+1);
                }
            }
        }

        ArrayList<Integer> vis = new ArrayList<Integer> (Collections.nCopies(n+1,0));
        
        int count = 0;
        for(int i = 1; i<=n; i++){
            if(vis.get(i)==0){
                count++;
                dfs(i,vis,adj);
            }
        }
        return count;
    }
}

    
   



