class Solution {
public:
    int dp[1010];
    // solved in 22 minutes --> recursion 
    int lis(int i,vector<vector<int>>&pairs ){
	int ans = 1;
    if(dp[i]!=-1) return dp[i];
	for (int j = 0; j < i; ++j)
	{
		if(pairs[i][0]>pairs[j][1]){
			ans = max(ans,lis(j,pairs)+1);
		}
	}
	return dp[i] = ans;
}

    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        for(auto i: pairs){
            cout << i[0] << " " << i[1] << endl;
        }
        int ans = 0;
        memset(dp,-1,sizeof(dp)); // changes done here, shifted from below for loop to here --> ye memset upar honga for each test case   
	for (int i = 0; i < pairs.size(); ++i)
	{
        // memset(dp,-1,sizeof(dp)); --> yaha thodi honga pagal 
		ans = max(ans,lis(i,pairs));
	}
        return ans;   
    }
};
