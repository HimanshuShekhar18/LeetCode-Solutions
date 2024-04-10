class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {

        int row = grid.size();
        int col = grid[0].size();

        if(row<3 && col<3) return 0;

        int rowsum[12][12];
        int colsum[12][12];

        for(int i = 0; i<row; i++){
           rowsum[i][0] = grid[i][0];
        }

        for(int j = 0; j<col; j++){
           colsum[0][j] = grid[0][j];
        }

        // rowsum
        for(int i = 0; i<row; i++){
            for(int j = 1; j<col; j++){
                rowsum[i][j]=rowsum[i][j-1]+grid[i][j];
            }
        }

        // colsum
        for(int j = 0; j<col; j++){
            for(int i = 1; i<row; i++){
                colsum[i][j]=colsum[i-1][j]+grid[i][j];
            }
        }



        int rightdiagonal[12][12];
        int leftdiagonal[12][12];

        for(int j = 0; j<col; j++){
            leftdiagonal[0][j] = grid[0][j];
        }

        for(int i = 1; i<row; i++){
            leftdiagonal[i][0] = grid[i][0];
        }

        for(int j = col-1; j>=0; j--){
            rightdiagonal[0][j] = grid[0][j];
        }
    
        for(int i = 1; i<row; i++){
            rightdiagonal[i][col-1] = grid[i][col-1];
        }

        

        
        // leftdiagonal
        for(int i = 1; i<row; i++){
            for(int j = 1; j<col; j++){
                leftdiagonal[i][j]=leftdiagonal[i-1][j-1]+grid[i][j];
                // cout << leftdiagonal[i][j] << ' ' << leftdiagonal[i-1][j-1] << " " << i << " " << j << endl;

            }
        }

        // rightdiagonal
        for(int i = 1; i<row; i++){
            for(int j = col-2; j>=0; j--){
                rightdiagonal[i][j]=rightdiagonal[i-1][j+1]+grid[i][j];
                // cout << rightdiagonal[i][j] << ' ' << rightdiagonal[i-1][j+1] << " " << i << " " << j << endl;
            }
        }

        


        int count = 0;


        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                    if(i+2<row && j+2<col){

                            int col1 = colsum[i+2][j]-(((i-1)<0)?0:colsum[i-1][j]);
                            int col2  = colsum[i+2][j+1]-(((i-1)<0)?0:colsum[i-1][j+1]);
                            int col3 = colsum[i+2][j+2]-(((i-1)<0)?0:colsum[i-1][j+2]);
                            int row1 = rowsum[i][j+2]-(((j-1)<0)?0:rowsum[i][j-1]);
                            int row2  = rowsum[i+1][j+2]-(((j-1)<0)?0:rowsum[i+1][j-1]);
                            int row3 = rowsum[i+2][j+2]-(((j-1)<0)?0:rowsum[i+2][j-1]);
                            int left = leftdiagonal[i+2][j+2];
                            if((i-1)>=0 && (j-1)>=0) left-= leftdiagonal[i-1][j-1];
                            int right  = rightdiagonal[i+2][j];

                            
                            
                           
                            if((i-1>=0) && (j+3)<=col-1) {right-=rightdiagonal[i-1][j+3];}
                            
                            // cout << col1 << col2 << col3 << row1 << row2 << row3 << left << right << endl;                             
                            if(col1!=col2 || col1!=col3 || col1!=row1 || col1!=row2 || col1!=row3 || col1!=left || col1!=right) continue;
                            
                            /* WA
                            // int sum = grid[i][j]+grid[i][j+1]+grid[i][j+2]+grid[i+1][j]+grid[i+1][j+1]+grid[i+1][j+2]+grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2];
                            // // sum = n*(n+1)/2;
                            // if(sum!=45) continue;
                            */

                            map<int,int> mp;
                            bool flag = true;
                            // sum se nahi karna hain 
                            for(int k = 0; k<=2; k++){
                                for(int l = 0; l<=2; l++){
                                    if(grid[i+k][j+l]>9 || grid[i+k][j+l]<=0) {flag = false; break;}
                                    mp[grid[i+k][j+l]]++;
                                }
                                if(flag == false) break;
                            }

                            if(flag==false) continue;
                            
                            if(mp.size()!=9) continue;

                            count++;
                    }
            }
        }
        return count;
    }
};
