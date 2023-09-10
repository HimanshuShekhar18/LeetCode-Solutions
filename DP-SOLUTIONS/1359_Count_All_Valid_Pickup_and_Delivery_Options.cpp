
// <-----------------------------------------------------------------------RECURSION+MEMOIZATION--------------------------------------------------------------------------------->

class Solution {
public:
    const int mod = 1000000007;
    int dp[501];
    int nums;
    int f(int num){
        if(num==nums) return 1;
        if(dp[num]!=-1) return dp[num];
        int ans = (num+1)*1LL*(2*num+1)*f(num+1)%mod;
        return dp[num]=ans;
    }
    int countOrders(int n) {
        nums = n;
        memset(dp,-1,sizeof(dp));
        return f(1);
    }
};





// <-----------------------------------------------------------TABULATION------------------------------------------------------------------------------------------------->


class Solution {
public:
    const int mod = 1000000007;
    int countOrders(int n) {
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[n]=1;
        for(int i = n-1; i>=1; i--){
            dp[i] = (i+1)*1LL*(2*i+1)*dp[i+1]%mod;
        }
        return dp[1];
    }
};



// <-----------------------------------------------------SPACE OPTIMIZED-------------------------------------------------------------------------------------------->



class Solution {
public:
    const int mod = 1000000007;
    int countOrders(int n) {
        int curr , next;
        next = 1;
        for(int i = n-1; i>=1; i--){
            curr = (i+1)*1LL*(2*i+1)*next%mod;
            next = curr;
        }
        return next;
    }
};



