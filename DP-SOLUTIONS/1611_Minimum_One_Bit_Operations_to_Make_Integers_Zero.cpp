class Solution {
public:

/*
DP with Bit Manipulation and Maths
TC: O(log(n)) or O(log(32))
SC: O(1)
*/

    int dp[33];

    int minimumOneBitOperations(int n) {

        dp[0] = 1;

        for(int i = 1; i<31; i++){
            dp[i]=dp[i-1]*2 + 1;
        }

        int ans = 0;
        int multiply = 1;
        int num1 = -1, num2 = -1;
        for(int i = 30; i>=0; i--){
            if((n>>i)&1) {
                ans=ans+multiply*dp[i];
                multiply*=-1;
            }
        }

        return ans;
    }
};
