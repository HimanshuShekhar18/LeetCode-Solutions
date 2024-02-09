class Solution {
public:

// LIS VARIANT
// TC: O(n^2)
// sc: o(n)

    vector<int> LIS(vector<int> &nums){

        int n = nums.size();
        vector<int> dp(n,1), hash(n,0);
        int lastindex = 0;
        int maxi = 1;

        sort(nums.begin(),nums.end());

        for(int ind = 0; ind<n; ind++){
            hash[ind]=ind;
            for(int prev_ind = 0; prev_ind<ind; prev_ind++){

                if(nums[ind]%nums[prev_ind]==0 && dp[prev_ind]+1>dp[ind])
                {
                    hash[ind]=prev_ind;
                    dp[ind]=1+dp[prev_ind];
                }
            }

            if(dp[ind]>maxi){
                lastindex = ind;
                maxi = dp[ind];
            }
        }

        vector<int> ans;
        ans.push_back(nums[lastindex]);

        while(hash[lastindex]!=lastindex){
            lastindex=hash[lastindex];
            ans.push_back(nums[lastindex]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        return LIS(nums);
    }
};




// <----------------------------------------------------------TOPOLOGICAL SORTING--------------------------------------------------------------------------->


class Solution {
public:

/* TOPOLOGICAL SORTING - Finding the longest chain in the graph
For eg: [1,2,4,8]
                                        1  
                                      / |
                                     /  |\
                                    /   | \
                                   2────4  \
                                    \    \  \
                                     \    \  \
                                      \   |  |
                                       \  |  |
                                        \ | /
                                          8

The longest Chain in graph is: 1-->2-->4-->8

*/

// TC: O(n^2)
// sc: o(n)

    vector<int> LIS(vector<int> &nums){

        int n = nums.size();
        vector<int> hash(n,-1);
        int lastindex = 0;
        
        vector<vector<int>> graph(n+1);
        vector<int> indeg(n+1,0);

        sort(nums.begin(),nums.end());

        //Build adjacent list
        for(int ind = 0; ind<n; ind++){
            for(int prev_ind = ind+1; prev_ind<n; prev_ind++){
                if(nums[prev_ind]%nums[ind]==0)
                {
                    graph[ind].push_back(prev_ind);
                    indeg[prev_ind]++; //indegree
                }
            }
        }

        queue<int> q;

        for(int i = 0; i<n; i++){
            if(indeg[i]==0) q.push(i);
        }

        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto child: graph[node]){
                indeg[child]--;
                if(indeg[child]==0){
                q.push(child);
                hash[child]=node;
              }
            }
          lastindex = node;
        }

        vector<int> ans;
        ans.push_back(nums[lastindex]);

        while(hash[lastindex]!=-1){
            lastindex=hash[lastindex];
            ans.push_back(nums[lastindex]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        return LIS(nums);
    }
};
















































