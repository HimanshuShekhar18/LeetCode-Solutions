class Solution {
public:

/*
Coding Mohan BitMasking 2D-DP Recursion and Memoization Approach
TC: O(K ∗ 2^N ∗ 2^N)
SC: O( K ∗ 2^N )
*/

int solve(vector<int>&jobs, int k, int worker_index, int mask, vector<vector<int>> &dp  ){
    
    if(worker_index==k){
        if(((1<<(jobs.size()))-1) == mask ) return 0;
        else return INT_MAX;
    }

    if(dp[worker_index][mask]!=-1) return dp[worker_index][mask];

    vector<int> left_mask;
    for(int i = 0; i<jobs.size(); i++){
        if(!(mask&(1<<i))) left_mask.push_back(i);
    }
    int left_mask_size = left_mask.size();
    int ans = INT_MAX;
    for(int submask = 1; submask<(1<<left_mask_size); submask++){

        int job_assign_sum = 0;
        int job_taken_mask = 0;

        for(int i = 0; i<left_mask_size; i++){

            if(submask&(1<<i)){
                job_assign_sum+=jobs[left_mask[i]];
                job_taken_mask |= (1<<left_mask[i]);
            }

        }
        ans = min (ans, max(solve(jobs,k,worker_index+1, mask|job_taken_mask, dp),job_assign_sum));
    }

    return dp[worker_index][mask] = ans;

}

    int minimumTimeRequired(vector<int>& jobs, int k) {
        vector<vector<int>> dp(k+1, vector<int> ((1<<(jobs.size())), -1));
        return solve(jobs,k,0,0,dp);
    } 
};



// <-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------->

class Solution {
public:


/*
Iterating through all masks with their submasks Complexity  O(3^n)  
2D-DP BitMasking Recursion and Memoization ( dp[child][mask] )  
TC: O( k * 3^n )  
SC: O ( k * 2^n ) 

*/

int solve(vector<int>&jobs, int k, int worker_index, int mask, vector<vector<int>> &dp  ){
    
    if(worker_index==k){
        if(mask==0) return 0;
        else return INT_MAX;
    }

    if(dp[worker_index][mask]!=-1) return dp[worker_index][mask];

    int ans = INT_MAX;
    for(int submask = mask; submask>0; submask=(submask-1)&mask){

        int job_assign_sum = 0;
        // job assigned for current subset
        for(int i = 0; i<jobs.size(); i++){

            if(submask&(1<<i)){
                job_assign_sum+=jobs[i];
            }

        }
        ans = min (ans, max(solve(jobs,k,worker_index+1, mask^submask, dp),job_assign_sum));
    }

    return dp[worker_index][mask] = ans;

}

    int minimumTimeRequired(vector<int>& jobs, int k) {
        vector<vector<int>> dp(k+1, vector<int> ((1<<(jobs.size())), -1));
        return solve(jobs,k,0,(1<<jobs.size())-1,dp);
    } 
};



// <---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------->


class Solution {
public:

/*
Same Approach but 2D-DP BitMasking Tabulation  ( dp[child][mask] )  
TC: O( k * 3^n )  
SC: O ( k * 2^n ) 
*/
    int minimumTimeRequired(vector<int>& jobs, int k) {
        vector<vector<int>> dp(k + 1, vector<int>((1 << (jobs.size())), INT_MAX));
        vector<int> job_sum(1 << jobs.size());
        for (int mask = 1; mask < (1 << (jobs.size())); mask++) {
            int job_assign_sum = 0;
            for (int i = 0; i < jobs.size(); i++) {
                if (mask & (1 << i)) {
                    job_assign_sum += jobs[i];
                }
            }
            job_sum[mask] = job_assign_sum;
        }
        dp[0][0] = 0;
        for (int person = 1; person <= k; person++) {
            for (int mask = 1; mask < (1 << (jobs.size())); mask++) {
                for (int submask = mask; submask > 0; submask = (submask - 1) & mask) {
                    dp[person][mask] = min(dp[person][mask],max(dp[person - 1][submask ^ mask], job_sum[submask]));
                }
            }
        }
        return dp[k][(1 << jobs.size()) - 1];
    }
};






