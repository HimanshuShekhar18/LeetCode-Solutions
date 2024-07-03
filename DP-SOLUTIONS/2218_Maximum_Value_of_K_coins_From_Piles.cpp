// <------------------------------------------------------------------------------------------RECURSION AND MEMOIZATION----------------------------------------------------------------------------------------------------------------------------------------->

class Solution {
public:

    int dp[1010][2010];

    int solve(vector<vector<int>> &piles, int index, int coins){
        if(coins==0 || index>=piles.size()) return 0;

        if(dp[index][coins]!=-1) return dp[index][coins];

        // not pick anything from current index 
        int not_pick = 0 + solve(piles,index+1,coins);

        int pick = 0;
        int sum = 0;
        // picking atleast one(upto current pile size allows and left coins allows) from current index;
        for(int i = 0; i<min(coins,(static_cast<int>(piles[index].size()))); i++){
            sum+=piles[index][i];
            pick = max(pick,sum+solve(piles,index+1,coins-i-1));
        }

        return dp[index][coins] = max(pick,not_pick);
    }

    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(piles,0,k);
    }
};


// <------------------------------------------------------------------------------------------TABULATION------------------------------------------------------------------------------------------------------------------------------>


/*

Tabulation from '1' to 'n'
TC: O(n*k)
SC: O(n*k)

*/

class Solution {
public:
    long long dp[1010][2010];
    // const int MOD = 1e9+7;
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        memset(dp, 0, sizeof(dp));
        int n = piles.size();

        long long ans = 0;
        for (int index = 1; index <=n; index++) {
            for (int coins = 0; coins <= k; coins++) {

                long long not_pick = 0;
                // not pick anything from current index
                not_pick += dp[index - 1][coins];

                long long pick = 0;
                long long sum = 0;
                // picking atleast one(upto current pile size allows and left
                // coins allows) from current index;
                for (int i = 0;
                     i < min(coins, (static_cast<int>(piles[index-1].size())));
                     i++) {
                    sum += piles[index-1][i];
                    if ((coins - i - 1) >= 0)
                        pick = max(pick, sum + dp[index - 1][coins - i - 1]);
                }

                dp[index][coins] = max(pick, not_pick);
            }
        }

        return dp[n][k];
    }
};


/*

Tabulation from 'n-1' to '0'
TC: O(n*k)
SC: O(n*k)


  */

class Solution {
public:
    long long dp[1010][2010];
    // const int MOD = 1e9+7;
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        memset(dp, 0, sizeof(dp));
        int n = piles.size();

        long long ans = 0;
        for (int index = n - 1; index >= 0; index--) {
            for (int coins = 0; coins <= k; coins++) {

                long long not_pick = 0;
                // not pick anything from current index
                not_pick += dp[index + 1][coins];

                long long pick = 0;
                long long sum = 0;
                // picking atleast one(upto current pile size allows and left
                // coins allows) from current index;
                for (int i = 0;
                     i < min(coins, (static_cast<int>(piles[index].size())));
                     i++) {
                    sum += piles[index][i];
                    if ((coins - i - 1) >= 0)
                        pick = max(pick, sum + dp[index + 1][coins - i - 1]);
                }

                dp[index][coins] = max(pick, not_pick);
            }
        }

        return dp[0][k];
    }
};




