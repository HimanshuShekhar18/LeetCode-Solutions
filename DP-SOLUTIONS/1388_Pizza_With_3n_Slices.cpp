class Solution {
public:
/*
Similar to House Robber 2
TC: O(slices.lenght()*slices.length()/3)
SC: O(slices.lenght()*slices.length()/3)
*/
    int n;
    int dp[510][180];
    int slice(vector<int>&slices,int index, int endindex, int quantity){
        if(index>=endindex || quantity == 0) return 0;
        if(dp[index][quantity]!=-1) return dp[index][quantity];

        int pick=slices[index]+slice(slices,index+2,endindex,quantity-1);
        int non_pick = 0+slice(slices,index+1,endindex,quantity);

        return dp[index][quantity]=max(pick,non_pick);
    }
    int maxSizeSlices(vector<int>& slices) {
        n = slices.size();
        if(n==1) return slices[0];
        memset(dp,-1,sizeof(dp));
        int case1 = slice(slices,0,n-1,n/3);
        memset(dp,-1,sizeof(dp));
        return max(case1,slice(slices,1,n,n/3));
    }
};




class Solution {
public:
/*
TABULATION 
TC: O(slices.lenght()*slices.length()/3)
SC: O(slices.lenght()*slices.length()/3)
*/
    int n;
    int dp[510][180];
    int maxSizeSlices(vector<int>& slices) {
        n = slices.size();
        if(n==1) return slices[0];
        memset(dp,0,sizeof(dp));

        for(int index = n-2; index>=0; index--){
        for(int quantity = 1; quantity<=n/3; quantity++){
        int pick=slices[index]+dp[index+2][quantity-1];
        int non_pick = 0+dp[index+1][quantity];
        dp[index][quantity]=max(pick,non_pick);
            }
        }
        int case1 = dp[0][n/3];

        memset(dp,0,sizeof(dp));

        for(int index = n-1; index>=1; index--){
            for(int quantity = 1; quantity<=n/3; quantity++){
        int pick=slices[index]+dp[index+2][quantity-1];
        int non_pick = 0+dp[index+1][quantity];
        dp[index][quantity]=max(pick,non_pick);
            }
        }
        int case2 = dp[1][n/3];
        return max(case1,case2);
    }
};



// <-----------------------------------------------------------------SPACE OPTIMIZED ------------------------------------------------------------------------------------>

class Solution {
public:
/*
TABULATION 
TC: O(slices.lenght()*slices.length()/3)
SC: O(slices.lenght()*slices.length()/3)
*/
    int n;
    int maxSizeSlices(vector<int>& slices) {
        n = slices.size();
        if(n==1) return slices[0];

        vector<int> curr(n+5,0), prev(n+5,0), prev2(n+5,0);

        for(int index = n-2; index>=0; index--){
        for(int quantity = 1; quantity<=n/3; quantity++){
        int pick=slices[index]+prev2[quantity-1];
        int non_pick = 0+prev[quantity];
        curr[quantity]=max(pick,non_pick);
            }
            prev2=prev;
            prev=curr;
        }
        int case1 = prev[n/3];

       fill(curr.begin(),curr.end(),0);
       fill(prev.begin(),prev.end(),0);
       fill(prev2.begin(),prev2.end(),0);

        for(int index = n-1; index>=1; index--){
            for(int quantity = 1; quantity<=n/3; quantity++){
        int pick=slices[index]+prev2[quantity-1];
        int non_pick = 0+prev[quantity];
        curr[quantity]=max(pick,non_pick);
            }
            prev2=prev;
            prev=curr;
        }
        int case2 = prev[n/3];
        return max(case1,case2);
    }
};



