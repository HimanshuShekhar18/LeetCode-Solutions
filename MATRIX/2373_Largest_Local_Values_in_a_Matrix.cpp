class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {

        int n = grid.size();

        vector<vector<int>> ans(n-2, vector<int>(n-2,0));

        for(int i = 0; i+2<grid.size(); i++){
            for(int j = 0; j+2<grid[0].size(); j++){

                int maxi = -1;

                    for(int k = 0; k<3; k++){
                        for(int l = 0; l<3; l++){

                            maxi = max(maxi,grid[i+k][j+l]);

                        }
                    }

                    ans[i][j]=maxi;

            }
        }

        return ans;
        
    }
};



// <--------------------------------------------------------------------------------------------------------------------------------------------------------------------------->




class Solution {
public:

/*

What if  k >>> 3  From Approach 1  TC: O(n*n*k)  TLE, So will follow this  Optimized Approach  Explanation in Code  TC: O(n*(n-k))   SC: O(n*(n-k)) uses the concept of Sliding Window Maximum

Optimized Approach if k >> 3:

When working with matrices, it's often necessary to efficiently find the maximum value within subarrays of a certain length (k). This task becomes more challenging as the size of the matrix increases or when the value of k becomes larger. Here, we'll explore an optimized approach for efficiently finding the maximum of k-length subarrays in a matrix.

The optimized approach involves precalculating the maximum value of each k-length subarray for rows and then using these precalculated values to find the maximum of each k-length subarray for columns. This significantly reduces redundant calculations and improves efficiency.

Step 1: Calculate Max of Each k-Length Subarray for Rows:
i. Iterate through each row of the matrix.
ii. For each row, calculate the maximum of every k-length subarray.
iii. Store these maximum values in a new array representing rows.
Step 2: Calculate Max of Each k-Length Subarray for Columns:
i. Iterate through each column of the matrix.
ii. For each column, calculate the maximum of every k-length subarray using the previously
calculated row-wise maximums.
iii. Store these maximum values in a new array representing columns.

Example:
Consider the following matrix and k = 3:
[9 9 8 1
5 6 2 6
8 2 6 4
6 2 2 2]

Step 1: Calculating Max of Each k-Length Subarray for Rows:
[9 9 (max(9,9,8), max(9,8,1))
6 6 (max(5,6,2), max(6,2,6))
8 2 (max(8,2,6), max(2,6,4))
6 2 ](max(6,2,2), max(2,2,2))

Step 2: Calculating Max of Each k-Length Subarray for Columns:
Using the previously calculated row-wise maximums:
[9 9 (max(9,6,8), max(9,6,2))
8 6 ](max(6,8,6), max(6,2,2))

Visit this problem to check out how to find maximum of each k length subarray in O(n) time -> https://leetcode.com/problems/sliding-window-maximum/description/

*/

    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {

        int n = grid.size();

          int k = 3;

        vector<vector<int>> ans(n-k+1, vector<int>(n-k+1,0));

        vector<vector<int>> row(n);

        // Step 1: Calculate Max of Each k-Length Subarray for Rows:
        for(int i = 0; i<n; i++){

            deque<int> deq;
            
            for(int j = 0; j<n; j++){

                while(!deq.empty() && deq.front() <= j-k) deq.pop_front();

                while(!deq.empty() && grid[i][deq.back()] < grid[i][j]) deq.pop_back();

                deq.push_back(j);

                    if(j>=k-1) {
                        row[i].push_back(grid[i][deq.front()]);
                    }
            }
        }

        int m = row[0].size();

        vector<vector<int>> col(n-k+1);

        // Step 2: Calculating Max of Each k-Length Subarray for Columns:
        // Using the previously calculated row-wise maximums:

        for(int j = 0; j<m; j++){

             deque<int> deq;

            for(int i = 0; i<n; i++){

                    
                while(!deq.empty() && deq.front() <= i-k) deq.pop_front();

                while(!deq.empty() && row[deq.back()][j] < row[i][j]) deq.pop_back();

                deq.push_back(i);

                    if(i>=k-1) {
                        col[j].push_back(row[deq.front()][j]);
                    }
            }

        }


        for(int i = 0; i<n-k+1; i++){
            for(int j = 0; j<n-k+1; j++){   
                ans[j][i]=col[i][j];
            }
        }

        return ans;
        
    }
};


