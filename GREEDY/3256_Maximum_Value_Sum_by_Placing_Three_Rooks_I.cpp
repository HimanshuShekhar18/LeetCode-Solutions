/*
Greedy on Matrix
Firstly save row-wise in each row Max Three Values among all columns then Try all possible 3 valid Combinations and Calculate Max Value.
Secondly, save column-wise in each column Max Three Values among all rows then Try all possible 3 valid Combinations and Calculate Max Value.

TC: O((3*m)^3 + (3*n)^3)
SC: O(n*m)
*/

class Solution {
public:
    long long maximumValueSum(vector<vector<int>>& board) {

        vector<vector<int>> matrix;

        // firstly save row-wise in each row Max Three Values among all columns.
        for(int i = 0; i<board.size(); i++){

            vector<pair<int,int>> temp;
            for(int j = 0; j<board[0].size(); j++){
                temp.push_back({board[i][j],j});
            }
            sort(temp.rbegin(),temp.rend());
            for(int k = 0; k<3; k++){
                matrix.push_back({temp[k].first,i,temp[k].second});
            }
        }

        // sort(matrix.begin(),matrix.end());
        long long sum = LLONG_MIN;

        // Now Check all 3 Rooks possible Combination
        for(int i = 0; i<matrix.size(); i++){
            for(int j = i+1; j<matrix.size(); j++){
                if(matrix[i][1]==matrix[j][1] || matrix[i][2]==matrix[j][2]) continue;
                for(int k = j+1; k<matrix.size(); k++){
                    if(matrix[i][1]==matrix[k][1] || matrix[i][2]==matrix[k][2] || matrix[j][1]==matrix[k][1] || matrix[j][2]==matrix[k][2]) continue;
                    sum=max(sum, (matrix[i][0]*1LL+matrix[j][0]*1LL+matrix[k][0]*1LL));
                }
            }
        }

        matrix.clear();

        // // secondly save column-wise in each column Max Three Values among all rows.
        for(int j = 0; j<board[0].size(); j++){

            vector<pair<int,int>> temp;
            for(int i = 0; i<board.size(); i++){
                temp.push_back({board[i][j],i});
            }
            sort(temp.rbegin(),temp.rend());
            for(int k = 0; k<3; k++){
                matrix.push_back({temp[k].first,temp[k].second,j});
            }
        }

        // Now Check all 3 Rooks possible Combination
        for(int i = 0; i<matrix.size(); i++){
            for(int j = i+1; j<matrix.size(); j++){
                if(matrix[i][1]==matrix[j][1] || matrix[i][2]==matrix[j][2]) continue;
                for(int k = j+1; k<matrix.size(); k++){
                    if(matrix[i][1]==matrix[k][1] || matrix[i][2]==matrix[k][2] || matrix[j][1]==matrix[k][1] || matrix[j][2]==matrix[k][2]) continue;
                    sum=max(sum, (matrix[i][0]*1LL+matrix[j][0]*1LL+matrix[k][0]*1LL));
                }
            }
        }
        return sum;        
    }
};


