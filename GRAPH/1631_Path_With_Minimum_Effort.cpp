class Solution {
public:

/*

Minimizing the Maximum
Dijksta's Algortihm on 2D Matrix using Priority Queue with Visited Array

TC: O(n^2 * log(n))
SC: O(n^2)

*/

    int vis[100][100];

    vector<pair<int,int>> movements = {{0,-1},{0,1},{-1,0},{1,0}};

    int minimumEffortPath(vector<vector<int>>& heights) {

        memset(vis,0,sizeof(vis));

        int n = heights.size();
        int m = heights[0].size();

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

        pq.push({0,{0,0}});
    
        while(!pq.empty()){

                pair<int,pair<int,int>> p = pq.top();
                pq.pop();

                int dist = p.first;
                int x = p.second.first;
                int y = p.second.second;

               

                if(vis[x][y]) continue;
                vis[x][y] = 1;

                

                if(x == n-1 && y == m-1) return dist;

                

                for(auto movement: movements){

                 

                        int childx = x + movement.first;
                        int childy = y + movement.second;

                        if(childx<0 || childx >=n || childy < 0 || childy>=m || vis[childx][childy] == 1) continue;
                           
                        pq.push({max(dist,abs(heights[x][y]-heights[childx][childy])),{childx,childy}});  
                        
                        
                }
        } 
        
        return 0;
    }
};



// <--------------------------------------------------------------BINARY SEARCH-------------------------------------------------------------------------------------------->



class Solution {
public:
    /*

    i) BINARY SEARCH ON ANSWER 
    ii) Running Normal BFS using queue and visited array chechking or searching for a path for which maximum difference between each cell of that path has value less than or equal to mid.

    TC: O(n^2 * log(n))
    SC: O(n^2)

    */

    int vis[100][100];

    vector<pair<int, int>> movements = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    int minimumEffortPath(vector<vector<int>>& heights) {

        int l = 0, r = 1e6;

        int ans = 0;

        while (l <= r) {
            int mid = r - (r - l) / 2;

            if (checkforpathlessthanorequaltomid(heights, mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }


 // chechking or searching for a path for which maximum difference between each cell of that path has value less than or equal to mid.
        bool checkforpathlessthanorequaltomid(vector<vector<int>> & heights, int mid) {

            queue<pair<int, int>> q;

            q.push({0, 0});

            memset(vis, 0, sizeof(vis));

            int n = heights.size();
            int m = heights[0].size();

            vis[0][0] = 1;

           

            while (!q.empty()) {

                pair<int, int> p = q.front();
                q.pop();

                
                int x = p.first;
                int y = p.second;

               
                if (x == n - 1 && y == m - 1)
                    return true;

                for (auto movement : movements) {

                    int childx = x + movement.first;
                    int childy = y + movement.second;

                    if (childx < 0 || childx >= n || childy < 0 ||
                        childy >= m || vis[childx][childy] == 1 || vis[childx][childy] == 1)
                        continue;

                    int val = abs(heights[x][y] - heights[childx][childy]);

                    if(val<=mid) { vis[childx][childy] = 1; q.push({childx, childy});}
                }
            }

            return 0;
        }
};


