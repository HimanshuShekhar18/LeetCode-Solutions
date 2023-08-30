class Solution {
public:
/*
For those who like me thought oh this is a repeat DP problem i.e. I use DP to find the path maximizing robot 1's score and then use DP to help find robot 2's maximum score path. Then I'm done. Well not exactly... 

Can consider this testcase:

10 50 50 30
50 50 10 10

If you find the maximum path for Robot 1 and set those cells into 0, then the path became:

00 00 00 00
50 50 10 00

The Robot 2 can get a maximum of 110 points

But if Robot 1 goes by:

00 00 50 30
50 00 00 00

Then Robot 2 can get a maximum of 80 points.
*/

/*

The first robot wants to minimize the number of points collected by the second robot; though the first robot have to take less value;
In contrast, the second robot wants to maximize the number of points it collects. If both robots play optimally, return the number of points collected by the second robot.

*/
    long long gridGame(vector<vector<int>>& grid) {

        int col = grid[0].size();
        
        vector<long long> prefix0(col,0);   // changes done here 'long long' instead of 'int'
        vector<long long> prefix1(col,0);   // changes done here 'long long' instead of 'int'

        prefix0[0]=grid[0][0];
        prefix1[0]=grid[1][0];

        for(int i = 1; i<col; i++){
            prefix0[i]=grid[0][i]+prefix0[i-1];
            prefix1[i]=grid[1][i]+prefix1[i-1];
        }

        long long ans = LLONG_MAX;

        for(int i = 0; i<col; i++){
            long long first = prefix0[col-1]-prefix0[i];
            long long second = i>0?prefix1[i-1]:0;
            ans=min(ans,max(first,second));
        }
        return ans;
    }
};
