class Solution {
public:

/*
Greedy(sabse pass wala perfect square) won't work 
12 --> 9,3
3 --> 1,2
2--> 1,1
Therefore, 12 = 9+1+1+1 i.e. 4 Perfect Squares
*/

/*
DP Approach:
                            12
                        1 /  |\
                         /  4| \ 9
                        /    |  \
                      11     8   3
                   1/ | \9   |\
                   / 4|  \  1| \4
                  /   |   \  |  \
                10   7    2  7  4
                                |\
                               1| \4
                                |  \
                                3   0
    Path: 12->8->4->0

*/

// Recursion and Memoization
// TC: O(n*sqrt(n))
// SC: O(n)

int dp[100005];

    int perfect(int num){
        if(num==0) return 0;
        if(dp[num]!=-1) return dp[num];

        int ans = INT_MAX;
        for(int i = 1; i*i<=num; i++){
            ans=min(ans,perfect(num-i*i)+1);
        }
        return dp[num]=ans;
    }

    int numSquares(int n) {
        memset(dp,-1,sizeof(dp));
        return perfect(n);
    }
};



// <------------------------------------------------------------TABULATION----------------------------------------------------------------------------------->


class Solution {
public:

// TABULATION
// TC: O(n*sqrt(n))
// SC: O(n)

long long dp[100005];

    int numSquares(int n) {
        for(int i = 1; i<=n; i++) dp[i]=INT_MAX;
        dp[0]=0;
        for(int i = 1; i<=n; i++){
        for(int j = 1; j*j<=i; j++){
            if(dp[i-j*j>=0]){
                dp[i]=min(dp[i],dp[i-j*j]+1);
            }
        }
    }
        return dp[n];
    }
};





