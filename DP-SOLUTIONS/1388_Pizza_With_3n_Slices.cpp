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
