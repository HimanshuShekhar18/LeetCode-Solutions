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


// <--------------------------------------------------------------------------Binary Search ----------------------------------------------------->

class Solution {
public:

    // BINARY SEARCH
    // TC: O(n*log(n))
    // SC: O(1)

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();

        int low = matrix[0][0];
        int high = matrix[n-1][n-1];

        while(low<=high){   
            int mid = high-(high-low)/2;
            int count = 0;

            for(int i = 0; i<n; i++){
                count+=upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
            }
            if(count<k){
                low = mid+1;
            }
            else if(count>=k){    // changes done here
                high=mid-1;
            }
        }    
        return low;   // changes done here 
    }
};

