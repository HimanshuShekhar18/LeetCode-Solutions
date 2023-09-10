const int N = 1e5+10;

class Solution {
public:

int dp[N];

int lis(int i, vector<int> &a ){

	if(dp[i]!=-1) return dp[i];
	int ans = 1;

	for (int j = 0; j < i; ++j)
	{
		if(a[i]>a[j]){
			ans = max(ans,lis(j,a)+1);
		}
	}

	return dp[i] = ans;
}

    // time complexity: O(n^2)

    int lengthOfLIS(vector<int>& nums) {

			memset(dp,-1,sizeof(dp));
	int ans = 0;

	for (int i = 0; i < nums.size(); ++i)
	{
		ans = max(ans,lis(i,nums));
	}
	
	return ans;
}

};





// <----------------------------------------------------------------RECURSION+MEMOIZATION----------------------------------------------------------------------->





class Solution {
public:
// TC: O(n^2)
// SC: O(n^2)
    int f(int curr, int prev, vector<int>&nums, int n, vector<vector<int>> &dp){
        if(curr==n) return 0;
        if(dp[curr][prev+1]!=-1) return dp[curr][prev+1];

        int not_take = 0 + f(curr+1,prev,nums,n,dp);
        int take = 0;
        if(prev==-1 || nums[curr]>nums[prev]) take = 1+f(curr+1,curr,nums,n,dp);
        return dp[curr][prev+1]=max(take,not_take);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1,-1));
        return f(0,-1,nums,n,dp); 
    }
};




// <-------------------------------------------------------------TABULATION---------------------------------------------------------------------------------->


class Solution {
public:
// TABULATION
// TC: O(n^2)
// SC: O(n^2)
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1,0));

        for(int curr = n-1; curr>=0; curr--){
            for(int prev = curr-1; prev>=-1; prev--){
        int take = 0;
        if(prev==-1 || nums[curr]>nums[prev]) take = 1+dp[curr+1][curr+1];
        int not_take = 0 + dp[curr+1][prev+1];
        dp[curr][prev+1]=max(take,not_take);
            }
        }
        return dp[0][-1+1];  
    }
};



// <--------------------------------------------------------------TABULATION+SPACE-OPTIMIZATIN--------------------------------------------------------------->



class Solution {
public:
// TABULATION+SPACE-OPTIMIZATION
// TC: O(n^2)
// SC: O(n)
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> currrow(n+1,0);
        vector<int> nextrow(n+1,0);

        for(int curr = n-1; curr>=0; curr--){
        for(int prev = curr-1; prev>=-1; prev--){
        int take = 0;
        if(prev==-1 || nums[curr]>nums[prev]) take = 1+nextrow[curr+1];
        int not_take = 0 + nextrow[prev+1];
        currrow[prev+1]=max(take,not_take);
        }
            nextrow = currrow;
        }
        return nextrow[-1+1];  
    }
};



// <-------------------------------------------------------------BINARY SEARCH------------------------------------------------------------------------------------->

class Solution {
public:
// LIS + BINARY SEARCH 
// TC: O(n*log(n))
// SC: O(n)
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
      for (int i = 1; i < n; i++)
      {
            if (nums[i] > temp.back())
                  temp.push_back(nums[i]);
            else
            {
                  // binary search  --> log(n)
                  int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                  temp[ind] = nums[i];
            }
      }
      return temp.size();  
    }
};







