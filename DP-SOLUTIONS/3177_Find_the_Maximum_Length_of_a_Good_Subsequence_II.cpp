class Solution {
public:

/*
DP on LIS Variant Optimization, HashMap, and Multiset
TC: O(n*k*log(n) 
SC: O(n*k)
*/

    int maximumLength(vector<int>& nums, int k) {

        unordered_map<int,unordered_map<int,int>> mp;
        vector<multiset<int>> st(k+1);

        vector<vector<int>> dp(nums.size()+1, vector<int> (k+1,0));

        for(int i = 0; i<nums.size(); i++){
            for(int j = 0; j<=k; j++){

                // equal
                if(mp[j].count(nums[i])) dp[i][j] = mp[j][nums[i]]+1;
                
                // not equal
                int notequal = 0;

                if(j!=0){
                    int currentnumnotinclude = 0;

                    int maximumamongothers = 0;

                    if(mp[j-1].count(nums[i])){

                         int currentnumnotinclude = mp[j-1][nums[i]];

                         int sizey = st[j-1].size();

                         if(sizey>=2){
                              auto it = st[j-1].end();
                            --it;
                            maximumamongothers = (*it);
                            if(maximumamongothers==currentnumnotinclude) {
                                --it;
                                maximumamongothers = (*it);
                            }

                            notequal = maximumamongothers;

                         }
                    }
                    else{
                            int sizey = st[j-1].size();
                            auto it = st[j-1].end();
                            --it;
                            maximumamongothers = (*it);
                            notequal = maximumamongothers;
                    }
                }


                dp[i][j]=max(dp[i][j],notequal+1);  // +1 for single charater length should be counted at starting

                mp[j][nums[i]] = dp[i][j];
                st[j].insert(dp[i][j]);
            }
        }

        int ans = 0;
        for(int i = 0; i<nums.size(); i++){
            ans = max(ans,dp[i][k]);
        }

       return ans;
        
    }
};
