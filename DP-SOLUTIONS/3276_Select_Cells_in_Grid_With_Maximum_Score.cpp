class Solution {
public:

/*

Sorting each Row in Descending Order and DP BITMASK and unordered_map<int, unordered_map<int, int>> tracking the counts of elements taken for each mask.
TC: O( 2^(n) * n * n )
SC: O( 2^(n) )

*/

    int maxScore(vector<vector<int>>& grid) {
        int row = grid.size();
        int column = grid[0].size();
        vector<int> dp((1<<row),0);
        unordered_map<int,unordered_map<int,int>> mp; // [mask][element] = count;  tracking the counts of elements taken for each mask   

        // Sort all the cells in the grid by their values in descending order
        for(auto &rowsy: grid){
            sort(rowsy.rbegin(),rowsy.rend());
        }

        for (int mask = 0; mask < (1 << row); mask++) {

            int currcount1 = __builtin_popcount(mask);
            if(currcount1==row) continue;

            for(int i = 0; i<row; i++){
                if(!(mask&(1<<i))){
                    for(int j = 0; j<column; j++){
                            int currmask = mask | (1<<i); 

                            // check if grid[i][j] element had been privously takin in mask
                            if(mp[mask].count(grid[i][j]) == 0){
                                if(dp[currmask]<=dp[mask]+grid[i][j]){
                                    dp[currmask] = dp[mask]+grid[i][j];
                                    mp[currmask][grid[i][j]]++;  // update count of grid[i][j] for currentmask 
                                }
                            } 
                            else {
                                dp[currmask] = max(dp[currmask],dp[mask]+0);
                                mp[currmask][grid[i][j]]++; // update count of grid[i][j] for currentmask
                            }
                    }
                }
            }
        }

        return dp[(1<<row)-1];
    }
};


