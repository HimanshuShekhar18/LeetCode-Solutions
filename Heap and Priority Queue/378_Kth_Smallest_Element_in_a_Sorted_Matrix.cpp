class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
       
       // WRONG APPROACH: 
       
        // k--;
        // int n = matrix[0].size();
        // int col = k%n;
        // int row = k/n;
        // if(col==n-1){
        //     if(row+1<n){
        //       if(matrix[row][col] > matrix[row+1][0]) row = row+1, col = 0;
        //     }
        // }
        // else if(col==0){
        //     if(row-1>=0){
        //       if(matrix[row][col] < matrix[row-1][n-1]) row = row-1, col = n-1;
        //     }
        // }
        // return matrix[row][col]; 


        // CORRECT APPROACH: MAX-HEAP

        int n = matrix[0].size();
        priority_queue<int> pq;      
        for(int i = 0; i<n;i++){
            for(int j = 0; j<n; j++){
    
                if(pq.size()<k){
                    pq.push(matrix[i][j]);
                }
                else{
                    if(pq.top()>matrix[i][j]){
                        pq.pop();
                        pq.push(matrix[i][j]);
                    }
                    else {
                        break;
                    }
                }
            }
        }
        return pq.top();

    }
};

