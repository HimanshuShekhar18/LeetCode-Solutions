class Solution {
public:
    // Complete (GREEDY) Brute Force  + Recursion  
    // Approach --> Take 1 element from nums1 and check and calculate XOR with all elements of nums2 and
    // shift the index to next element of nums1 and mark that element of nums2 as visited. Now repeat the same process for next element of nums1 and so on.

    int vis[14];
    int n;
    int help(int ind, vector<int> &v1, vector<int> &v2){
        if(ind==n) return 0;
        int ans = INT_MAX;
        for(int j = 0; j<n; j++){
            if(vis[j]==0){
                vis[j]=1;
                ans = min(ans,(v1[ind]^v2[j])+help(ind+1,v1,v2));    // changes done here "added brackets" --> (v1[ind]^v2[j])
                vis[j]=0;
            }
        }
        return ans;
    }

    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        memset(vis,0,sizeof(vis));
        return help(0,nums1,nums2);
    }
};


// <------------------------------------------------------------------------ MEMOIZATION ------------------------------------------------------------------------------>


class Solution {
public:
    // Complete (GREEDY) Brute Force  + Recursion  
    // As Expected TLE aayega so using MEMOIZATION 
    // Approach --> Take 1 element from nums1 and check and calculate XOR with all elements of nums2 and shift the index to next element of nums1 and mark that element of nums2 as visited. Now repeat the same process for next element of nums1 and so on.
    // 

    vector<int> vis;    // changes done here as array cannot be mapped 
    map<vector<int>,int> dp;  // changes done here as array cannot be mapped so we use vector --> here state which changing is "vis" vector.
    int n;
    int help(int ind, vector<int> &v1, vector<int> &v2){
        if(ind==n) return 0;
        if(dp.find(vis)!=dp.end()) return dp[vis];
        int ans = INT_MAX;
        for(int j = 0; j<n; j++){
            if(vis[j]==0){
                vis[j]=1;
                ans = min(ans,(v1[ind]^v2[j])+help(ind+1,v1,v2));    // changes done here "added brackets" --> (v1[ind]^v2[j])
                vis[j]=0;
            }
        }
        return dp[vis]=ans;
    }

    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        vis.resize(n,0);
        return help(0,nums1,nums2);
    }
};


// <-------------------------------------------------------------DP MEMOIZATION + BITMASKING-------------------------------------------------------------------------------------------->



class Solution {
public:
    // Complete (GREEDY) + RECURSION + MEMOIZATION + BITMASK   
    int n;
    int dp[14][18000];
    int help(int ind, vector<int> &v1, vector<int> &v2,int mask){
        if(ind==n) return 0;
        if(dp[ind][mask]!=-1) return dp[ind][mask];
        int ans = INT_MAX;
        for(int j = 0; j<n; j++){
            if((mask & (1<<j))==0){
                ans = min(ans,(v1[ind]^v2[j])+help(ind+1,v1,v2,mask|(1<<j))); 
            }
        }
        return dp[ind][mask]=ans;
    }

    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        memset(dp,-1,sizeof(dp));
        return help(0,nums1,nums2,0);
    }
};



// <-------------------------------------------------------------------DP TABULATION + BITMASKING ----------------------------------------------------------------------------->


class Solution {
public:
    // Complete (GREEDY) + TABULATION + BITMASK
    // TC: O(n*2^n)
    // SC: O(2^n)
    int n;
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        vector<int> dp((1<<n),INT_MAX);
        dp[0]=0;
        for(int mask = 0; mask<=(1<<n)-1; mask++){
        // We check for the i'th element of nums1
        int ind = __builtin_popcount(mask);
        for(int j = 0; j<n; j++){
            if((mask & (1<<j))==0){
                // dp[mask|(1<<j)]  --> curr
                // dp[mask] --> past
                dp[mask|(1<<j)] = min(dp[mask|(1<<j)],(nums1[ind]^nums2[j])+dp[mask]); 
            }
        }
        }
        return dp[(1<<n)-1];       
    }
};








