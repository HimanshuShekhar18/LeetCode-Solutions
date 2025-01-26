class Solution {
public:

/*
DP BitMasking Recursion and Memoization
Iterating Through all Masks and Their Submasks
TC: O( 3^n)
SC: O(2^n)
*/
    int solve(vector<int>& tasks, int sessionTime, int mask, vector<int>&dp) {

        if(mask==((1<<tasks.size())-1)) return 0;

        if(dp[mask]!=-1) return dp[mask];

        vector<int> left_mask;
        for (int i = 0; i < tasks.size(); i++) {
            if (!(mask & (1 << i)))
                left_mask.push_back(i);
        }
        
        int left_mask_size = left_mask.size();
        int ans = INT_MAX;

        for (int submask = 1; submask < (1 << left_mask_size); submask++) {

            int task_assign_sum = 0;
            int task_taken_mask = 0;

            for (int i = 0; i < left_mask_size; i++) {

                if (submask & (1 << i)) {
                    task_assign_sum += tasks[left_mask[i]];
                    task_taken_mask |= (1 << left_mask[i]);
                }
            }
            if(task_assign_sum<=sessionTime){
                ans = min(ans, 1+solve(tasks, sessionTime, mask | task_taken_mask, dp));
            }
        }

        return dp[mask]=ans;
    }

        int minSessions(vector<int> & tasks, int sessionTime) {
            vector<int> dp(1<<tasks.size(), -1);
            return solve(tasks,sessionTime, 0, dp);
        } 
    };



