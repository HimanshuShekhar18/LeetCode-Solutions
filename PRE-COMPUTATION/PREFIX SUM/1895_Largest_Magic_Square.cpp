class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {

        int row = grid.size();
        int col = grid[0].size();

        int rowsum[51][51];
        int colsum[51][51];

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


        int rightdiagonal[51][51];
        int leftdiagonal[51][51];

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

        


        int size = 1;


        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){

                    for(int k = 0; k<min(row,col); k++){

                        if(i+k<row && j+k<col){

                        bool flag = true;
                        // column checkings    
                        int temp = -1;                      
                        for(int l = 0; l<=k; l++){
                              
                              int column = colsum[i+k][j+l]-(((i-1)<0)?0:colsum[i-1][j+l]);
                              
                              if(temp==-1) temp = column;
                              if(temp!=column) {
                                flag = false;
                                break;
                              }
                        }

                        if(flag == false) continue;

                        flag = true;

                        // row checkings                         
                        for(int l = 0; l<=k; l++){
                            
                            int row = rowsum[i+l][j+k]-(((j-1)<0)?0:rowsum[i+l][j-1]); 
        
                              if(temp!=row) {
                                flag = false;
                                break;
                              }
                        }

                        if(flag == false) continue;


                        flag = true;

                        // right diagonal checking              
                        for(int l = 0; l<=k; l++){

                    
                            int right  = rightdiagonal[i+k][j];
                              if((i-1>=0) && (j+k+1)<=col-1) {right-=rightdiagonal[i-1][j+k+1];} 
                              if(temp!=right) {
                                flag = false;
                                break;
                              }
                        }

                        if(flag == false) continue;

                        flag = true;

                        // left diagonal checking                   
                        for(int l = 0; l<=k; l++){ 
                            int left = leftdiagonal[i+k][j+k];
                              if((i-1)>=0 && (j-1)>=0) left-= leftdiagonal[i-1][j-1];
                              if(temp!=left) {
                                 flag = false;
                                break;
                              }
                        }

                        if(flag == false) continue;
                        size=max(size,k+1);
  
                    }
                }             
            }
        }

        return size;
    }
};
