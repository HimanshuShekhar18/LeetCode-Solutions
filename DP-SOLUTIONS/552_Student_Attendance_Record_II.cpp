class Solution {
public:

/*
   Simple Recursion 
*/
    const int MOD = 1e9+7;

    int solve(int index, int countabsent, int countlate){
        
        if(countabsent>=2 || countlate >2){
            return 0;
        }

        if(index<0){
            return 1;
        }

        // freah state 
        int ans = 0;        

        ans = solve(index-1,countabsent,0);

        ans+= solve(index-1,countabsent+1,0);

        ans+= solve(index-1,countabsent,countlate+1);

        return ans%MOD;
    }

    int checkRecord(int n) {

        return solve(n-1,0,0)%MOD;
        
    }
};



// <----------------------------------------------------------------RECURSION AND MEMOIZATION--------------------------------------------------------------------------------------------->



class Solution {
public:

/*

   Simple Recursion and Memoization 
   3D DP
   TC: O(n*2*3)
   SC: O(n*2*3)

*/
    const int MOD = 1e9+7;
    long long dp[100005][3][4];

    int solve(int index, int countabsent, int countlate){
        
        if(countabsent>=2 || countlate >2){
            return 0;
        }

        if(index<0){
            return 1;
        }

        if(dp[index][countabsent][countlate]!=-1) return dp[index][countabsent][countlate];

        // freah state 
        long long ans = 0;        

        ans = solve(index-1,countabsent,0);

        ans+= solve(index-1,countabsent+1,0);

        ans+= solve(index-1,countabsent,countlate+1);

        return dp[index][countabsent][countlate] = ans%MOD;
    }

    int checkRecord(int n) {

        memset(dp,-1,sizeof(dp));
        return solve(n-1,0,0)%MOD;
        
    }
};



// <---------------------------------------------------------------TABULATION------------------------------------------------------------------------------------------------------>



class Solution {
public:
    /*

       Simple BOTTOM UP TABULATION
       3D DP
       TC: O(n*2*3)
       SC: O(n*2*3)

    */
    const int MOD = 1e9 + 7;
    long long dp[100005][3][4];

    int checkRecord(int n) {

        memset(dp, 0, sizeof(dp));

        dp[0][0][0] = 1;

    

        for (int index = 0; index < n; index++) {
            for (int countabsent = 0; countabsent < 2; countabsent++) {
                for (int countlate = 0; countlate <= 2; countlate++) {
                        dp[index+1][countabsent][0] = (dp[index+1][countabsent][0] + dp[index][countabsent][countlate])%MOD;
                        if (countabsent < 2) dp[index+1][countabsent+1][0]= (dp[index+1][countabsent+1][0] + dp[index][countabsent][countlate])%MOD;
                        if (countlate  <= 2 ) dp[index+1][countabsent][countlate+1] = (dp[index+1][countabsent][countlate+1] + dp[index][countabsent][countlate])%MOD;
                    }
                }
        }

        long long count = 0;

        
            for (int countabsent = 0; countabsent < 2; countabsent++) {
                for (int countlate = 0; countlate <= 2; countlate++) {
                        count+=dp[n][countabsent][countlate];
                    }
            }

        return count%MOD;
    }
};



// <--------------------------------------------------------SPACE OPTIMIZATION TABULATION---------------------------------------------------------------------------------------------->



class Solution {
public:
    /*

       SPACE OTIMIZED TABULATION

       TC: O(n*2*3)
       SC: O(1)

    */
    const int MOD = 1e9 + 7;
    

    int checkRecord(int n) {

        
        vector<vector<long long>> prev(3,vector<long long> (4,0));
         vector<vector<long long>> curr(3,vector<long long> (4,0));
        
       
        prev[0][0] = 1;

        for (int index = 0; index < n; index++) {
            
            
            for (int countabsent = 0; countabsent < 2; countabsent++) {
                for (int countlate = 0; countlate <= 2; countlate++) {
                        curr[countabsent][0] = (curr[countabsent][0] + prev[countabsent][countlate])%MOD;
                        if (countabsent < 2) curr[countabsent+1][0]= (curr[countabsent+1][0] + prev[countabsent][countlate])%MOD;
                        if (countlate  <= 2 ) curr[countabsent][countlate+1] = (curr[countabsent][countlate+1] + prev[countabsent][countlate])%MOD;
                    }
                }
            prev = curr;
            // for every new length new curr vector is required in which all values are ZERO
            for(int i = 0; i<3; i++){
                for(int j = 0; j<4; j++){
                    curr[i][j]=0;
                }
            }
        }

        long long count = 0;

            for (int countabsent = 0; countabsent < 2; countabsent++) {
                for (int countlate = 0; countlate <= 2; countlate++) {
                        count+=prev[countabsent][countlate];
                    }
            }

        return count%MOD;
    }
};


