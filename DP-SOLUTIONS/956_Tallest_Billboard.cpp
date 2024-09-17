class Solution {
public:

/*

0/1 Knapsack 3D-DP ( states are LeftPick, RightPick, and NotPick) 
TLE
TC: O(n*(5000)*(5000))
SC: O(n*(5000)*(5000))

*/

    unordered_map<int,unordered_map<int,unordered_map<int,int>>> dp;
    int solve(int index,int picksum1, int picksum2, vector<int>& rods){
      
        if(index==rods.size()){
                if(picksum1==picksum2) return picksum1;
                else return INT_MIN;
        }

        if(dp.find(index)!=dp.end() && dp[index].find(picksum1) !=dp[index].end() && dp[index][picksum1].find(picksum2)!= dp[index][picksum1].end()) return dp[index][picksum1][picksum2];

        return dp[index][picksum1][picksum2] = max({solve(index+1,picksum1+rods[index],picksum2,rods),solve(index+1,picksum1,picksum2+rods[index],rods), solve(index+1,picksum1,picksum2,rods)});
    }

    int tallestBillboard(vector<int>& rods) {
        
        int ans = solve(0,0,0,rods);
        return ans==INT_MIN?0:ans;
    }
};



// <-----------------------------------------------------------------2D-DP and DP OPTIMIZATION---------------------------------------------------------------------------------------------->

class Solution {
public:

/*
0/1 Knapsack 2D-DP and Single DP Optimization
TC: O(n*(10000))
SC: O(n*(10000))
*/
    int dp[25][10005];
    int solve(int index,int diff, vector<int>& rods){
      
        if(index==rods.size()){
                if(diff==0) return 0;
                else return INT_MIN;
        }

        if(dp[index][diff+5000]!=-1) return dp[index][diff+5000];

        int pickleft = rods[index]+solve(index+1,diff+rods[index],rods);

        int pickright = rods[index]+solve(index+1,diff-rods[index],rods);

        int notpick = solve(index+1,diff,rods);

        return dp[index][diff+5000] = max({pickright,pickleft,notpick});
    }

    int tallestBillboard(vector<int>& rods) {

        memset(dp,-1,sizeof(dp));
        int ans = solve(0,0,rods);
        return ans==INT_MIN?0:ans/2;

    }
};



