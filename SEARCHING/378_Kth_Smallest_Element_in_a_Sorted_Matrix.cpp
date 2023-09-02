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

