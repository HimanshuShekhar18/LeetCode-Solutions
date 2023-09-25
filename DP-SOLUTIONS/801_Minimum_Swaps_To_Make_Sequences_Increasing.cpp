class Solution {
    public:
    // RECURSION + MEMOIZATION
    // TC: O(n+n)
    // SC: O(N+N+N)
    // So it's simple problem just like take and not_take.
    int dp[100010][2];
    int solve(vector<int> &num1, vector<int> &num2, int index, int swapped){
        if(index==num1.size()) return 0;
        if(dp[index][swapped]!=-1) return dp[index][swapped];

        int ans = INT_MAX;

        int prev1 = num1[index-1];
        int prev2 = num2[index-1];


        // catch --> kyuki swap ko to hum vector mein nahi kar sakte but uska track jaroor rakh sakte
        // ki swap kiya ya nahi taki uss hisab se swapped vector mane !!!!!
        if(swapped){
            swap(prev1,prev2);
        }

        // non-swap
        if(prev1<num1[index]&&prev2<num2[index]) ans = min(ans,solve(num1,num2,index+1,0));

        // swap --> hum swap kar rahe hain strictly increasing banane ke liye
        if(prev1<num2[index] && prev2<num1[index]) ans = min(ans,1+solve(num1,num2,index+1,1));     // changes done here

        return dp[index][swapped] = ans;

    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        //  0 <= nums1[i], nums2[i] <= 2 * 10^5
        int n = nums1.size();
        vector<int> num1;
        num1.push_back(-1);
        vector<int> num2;
        num2.push_back(-1);
        num1.insert(num1.end(),nums1.begin(),nums1.end());
        num2.insert(num2.end(),nums2.begin(),nums2.end());
        memset(dp,-1,sizeof(dp));
        return solve(num1,num2,1,0);
    }
};


