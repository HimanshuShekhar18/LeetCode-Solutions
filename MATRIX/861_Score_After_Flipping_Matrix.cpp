class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i<m; i++){
            
            if(grid[i][0]==0){
                for(int j = 0; j<n; j++){
                    grid[i][j]=1-grid[i][j];
                }
            }

        }

        for(int j = 1; j<n; j++){

                int count0 = 0;
                int count1 = 0;
                for(int i = 0; i<m; i++){
                    if(grid[i][j]==0) count0++;
                    else count1++;
                }

                if(count1<count0){
                    for(int k = 0; k<m; k++){
                    grid[k][j]=1-grid[k][j];
                    }
                }
        }

        long long sum = 0;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                sum+=grid[i][n-j-1]*pow(2,j);
            }
        }

        return sum;
        
    }
};

