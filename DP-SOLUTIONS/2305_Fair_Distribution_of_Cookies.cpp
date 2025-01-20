class Solution {
public:

/*

Iterating through all masks with their submasks Complexity  O(3^n)  
2D-DP BitMasking Recursion and Memoization ( dp[child][mask] )  
TC: O( k * 3^n )  
SC: O ( k * 2^n )
Function Starting from (k=0, Mask = (1<<n)-1)

*/

/*

Articles Link:  https://cp-algorithms.com/algebra/all-submasks.html#enumerating-all-submasks-of-a-given-mask

Counting Submasks Across All Masks:
To calculate the total number of submask iterations:
• Each mask contributes 2^popcount(\U0001d45a\U0001d44e\U0001d460\U0001d458) submasks, where popcount(mask) is the number of 1 bits in the mask.
• If we sum this over all 2^\U0001d45b masks:
              Total Submask Iterations = ∑(\U0001d45bC\U0001d458)* 2^\U0001d458 
      • (\U0001d45bC\U0001d458): Number of masks with exactly \U0001d458 k bits set.
      • 2^\U0001d458: Number of submasks for each mask. 
Using the binomial theorem: ∑ ( \U0001d45bC\U0001d458 ) ⋅ 2^\U0001d458 = ( 1 + 2  )^\U0001d45b = 3^\U0001d45b 
    Final Time Complexity: The total time complexity is dominated by the total number of submask iterations across all masks: \U0001d442( 3^\U0001d45b )

*/
    int solve(vector<int>& cookies, int k, int n, int child_index, int child_cookie_mask,
               vector<vector<int>>& dp) {

        if (child_index == k) {
            if(child_cookie_mask==0) return 0;
            else return INT_MAX;
        }

        if(dp[child_index][child_cookie_mask]!=-1) return dp[child_index][child_cookie_mask];

        int ans = INT_MAX;
        for (int submask = child_cookie_mask; submask>0; submask=(submask-1)&child_cookie_mask) {
            // calculate the sum of cookies in the current mask/subset
            int sum1 = 0;
            for(int i = 0; i<n; i++){
                if(submask & (1<<i)){
                    sum1+=cookies[i];
                }
            }
            // recursively solve the subproblem for the remaining cookies-bag
            int sum2 = solve(cookies,k,n,child_index+1,child_cookie_mask^submask,dp); 
            ans=min(ans,max(sum1,sum2));
        }

        return dp[child_index][child_cookie_mask]=ans;
    }

    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        vector<vector<int>> dp(k, vector<int>(1 << n, -1));
        solve(cookies, k, n, 0, (1 << n)-1, dp);
        return dp[0][(1 << n)-1];
    }
};



class Solution {
public:

/*

Iterating through all masks with their submasks Complexity  O(3^n)  
2D-DP BitMasking Recursion and Memoization ( dp[child][mask] )  
TC: O( k * 3^n )  
SC: O ( k * 2^n )
Function Starting from (k=k, Mask = (1<<n)-1)

*/


/*

Articles Link:  https://cp-algorithms.com/algebra/all-submasks.html#enumerating-all-submasks-of-a-given-mask

Counting Submasks Across All Masks:
To calculate the total number of submask iterations:
• Each mask contributes 2^popcount(\U0001d45a\U0001d44e\U0001d460\U0001d458) submasks, where popcount(mask) is the number of 1 bits in the mask.
• If we sum this over all 2^\U0001d45b masks:
              Total Submask Iterations = ∑(\U0001d45bC\U0001d458)* 2^\U0001d458 
      • (\U0001d45bC\U0001d458): Number of masks with exactly \U0001d458 k bits set.
      • 2^\U0001d458: Number of submasks for each mask. 
Using the binomial theorem: ∑ ( \U0001d45bC\U0001d458 ) ⋅ 2^\U0001d458 = ( 1 + 2  )^\U0001d45b = 3^\U0001d45b 
    Final Time Complexity: The total time complexity is dominated by the total number of submask iterations across all masks: \U0001d442( 3^\U0001d45b )

*/
    int solve(vector<int>& cookies, int k, int n, int child_index, int child_cookie_mask,
               vector<vector<int>>& dp) {

        if (child_index == 1) {
            int sum = 0;
            for(int i = 0; i<n; i++){
                if(child_cookie_mask & (1<<i)){
                    sum+=cookies[i];
                }
            }
            return sum;
        }

        if(dp[child_index][child_cookie_mask]!=-1) return dp[child_index][child_cookie_mask];

        int ans = INT_MAX;
        for (int submask = child_cookie_mask; submask>0; submask=(submask-1)&child_cookie_mask) {
            // calculate the sum of cookies in the current mask/subset
            int sum1 = 0;
            for(int i = 0; i<n; i++){
                if(submask & (1<<i)){
                    sum1+=cookies[i];
                }
            }
            // recursively solve the subproblem for the remaining cookies-bag
            int sum2 = solve(cookies,k,n,child_index-1,child_cookie_mask^submask,dp); 
            ans=min(ans,max(sum1,sum2));
        }

        return dp[child_index][child_cookie_mask]=ans;
    }

    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        vector<vector<int>> dp(k+1, vector<int>(1 << n, -1));
        solve(cookies, k, n, k, (1 << n)-1, dp);
        return dp[k][(1 << n)-1];
    }
};


// <------------------------------------------------------------------2D-DP BITAMSKING TABULATION---------------------------------------------------------------------------------------->

class Solution {
public:

    /*
    Same Approach but 2D-DP BitMasking Tabulation  ( dp[child][mask] )  
    TC: O( k * 3^n )  
    SC: O ( k * 2^n )
    */

    /*

    Articles Link:
    https://cp-algorithms.com/algebra/all-submasks.html#enumerating-all-submasks-of-a-given-mask

    Counting Submasks Across All Masks:
    To calculate the total number of submask iterations:
    • Each mask contributes 2^popcount(𝑚𝑎𝑠𝑘) submasks, where popcount(mask
     is the number of 1 bits in the m • If we sum this over all 2^𝑛 masks
                  Total Submask Iterations = ∑(𝑛C𝑘)* 2
          • (𝑛C𝑘): Number of masks with exactly 𝑘 k bits s
          • 2^𝑘: Number of submasks for each mask
    Using the binomial theorem: ∑ ( 𝑛C𝑘 ) ⋅ 2^𝑘 = ( 1 + 2  )^𝑛 =
        Final Time Complexity: The total time complexity is dominated by the
    total number of submask iterations across all masks: 𝑂( 3^𝑛 )

    */

    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        vector<vector<int>> dp(k + 1, vector<int>(1 << n, INT_MAX));
        dp[0][0]=0;
        for (int i = 1; i <= k; i++) {
            for (int mask=(1<<n)-1; mask>=0; --mask) {
                for (int submask = mask; submask > 0; submask = (submask - 1) & mask) {
                    // calculate the sum of cookies in the current mask/subset
                    int sum1 = 0;
                    for (int i = 0; i < n; i++) {
                        if (submask & (1 << i)) {
                            sum1 += cookies[i];
                        }
                    }
                    dp[i][mask] = min(dp[i][mask], max(sum1, dp[i-1][mask ^ submask]));
                }
            }
        }

        return dp[k][(1 << n) - 1];
    }
};













