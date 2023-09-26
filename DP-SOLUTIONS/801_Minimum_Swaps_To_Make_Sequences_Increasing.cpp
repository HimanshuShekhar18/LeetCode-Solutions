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




// <--------------------------------------------------------------------------TABULATION-------------------------------------------------------------------------------------->


class Solution {
    public:
    // TABULATION --> from num1.size()-1 to 1;
    // TC: O(n+n)
    // SC: O(N+N+N)
    // So it's simple problem just like take and not_take.
    /* Good Testcase: [0,4,4,5,9]
                      [0,1,6,8,10];    elements get swapped at 1st index.
    */
    int dp[100010][2];

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        //  0 <= nums1[i], nums2[i] <= 2 * 10^5
        int n = nums1.size();
        vector<int> num1;
        num1.push_back(-1);
        vector<int> num2;
        num2.push_back(-1);
        num1.insert(num1.end(),nums1.begin(),nums1.end());
        num2.insert(num2.end(),nums2.begin(),nums2.end());

        fill_n(&dp[0][0],(100010*2),INT_MAX);

        dp[num1.size()][0] = 0; 
        dp[num1.size()][1] = 0;

        for(int index = num1.size()-1; index>=1; index--){
             int prev1 = num1[index-1];
             int prev2 = num2[index-1];
                for(int swapped = 0; swapped<=1; swapped++){
        // catch --> kyuki swap ko to hum vector mein nahi kar sakte but uska track jaroor rakh sakte
        // ki swap kiya ya nahi taki uss hisab se swapped vector mane !!!!!
        if(swapped){
            swap(prev1,prev2);
        }

        // non-swap
        if(prev1<num1[index]&&prev2<num2[index]) dp[index][swapped]  = min(dp[index][swapped] ,dp[index+1][0]);

        // swap --> hum swap kar rahe hain strictly increasing banane ke liye
        if(prev1<num2[index] && prev2<num1[index]) dp[index][swapped]  = min(dp[index][swapped] ,1+dp[index+1][1]);
            }
        }

        return dp[1][0];
    }
};




// <--------------------------------------------------------------------Space Optimization----------------------------------------------------------------------------->


class Solution {
    public:
    // SPACE OPTIMIZATION
    // TC: O(n+n)
    // SC: O(N+N)
    // So it's simple problem just like take and not_take.
    /* Good Testcase: [0,4,4,5,9]
                      [0,1,6,8,10];    elements get swapped at 1st index.
    */
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        //  0 <= nums1[i], nums2[i] <= 2 * 10^5
        int n = nums1.size();
        vector<int> num1;
        num1.push_back(-1);
        vector<int> num2;
        num2.push_back(-1);
        num1.insert(num1.end(),nums1.begin(),nums1.end());
        num2.insert(num2.end(),nums2.begin(),nums2.end());

        vector<int> forward(2,0);
        vector<int> curr(2,0);

        for(int index = num1.size()-1; index>=1; index--){
             int prev1 = num1[index-1];
             int prev2 = num2[index-1];
             curr[0] = INT_MAX;
             curr[1] = INT_MAX;
                for(int swapped = 0; swapped<=1; swapped++){
        // catch --> kyuki swap ko to hum vector mein nahi kar sakte but uska track jaroor rakh sakte
        // ki swap kiya ya nahi taki uss hisab se swapped vector mane !!!!!
        if(swapped){
            swap(prev1,prev2);
        }

        // non-swap
        if(prev1<num1[index]&&prev2<num2[index]) curr[swapped]  = min(curr[swapped] ,forward[0]);

        // swap --> hum swap kar rahe hain strictly increasing banane ke liye
        if(prev1<num2[index] && prev2<num1[index]) curr[swapped]  = min(curr[swapped] ,1+forward[1]);
            }
            forward=curr;
        }

        return forward[0];
    }
};




class Solution {
    public:
    // MORE SPACE OPTIMIZATION
    // TC: O(n)
    // SC: O(1)
    // So it's simple problem just like take and not_take.
    /* Good Testcase: [0,4,4,5,9]
                      [0,1,6,8,10];    elements get swapped at 1st index.
    */
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        //  0 <= nums1[i], nums2[i] <= 2 * 10^5
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);

        vector<int> forward(2,0);
        vector<int> curr(2,0);

        for(int index = nums1.size()-1; index>=1; index--){
             int prev1 = nums1[index-1];
             int prev2 = nums2[index-1];
             curr[0] = INT_MAX;
             curr[1] = INT_MAX;
                for(int swapped = 0; swapped<=1; swapped++){
        // catch --> kyuki swap ko to hum vector mein nahi kar sakte but uska track jaroor rakh sakte
        // ki swap kiya ya nahi taki uss hisab se swapped vector mane !!!!!
        if(swapped){
            swap(prev1,prev2);
        }

        // non-swap
        if(prev1<nums1[index]&&prev2<nums2[index]) curr[swapped]  = min(curr[swapped] ,forward[0]);

        // swap --> hum swap kar rahe hain strictly increasing banane ke liye
        if(prev1<nums2[index] && prev2<nums1[index]) curr[swapped]  = min(curr[swapped] ,1+forward[1]);
            }
            forward=curr;
        }

        return forward[0];
    }
};



// <---------------------------------------------------------------------TABULATION--------------------------------------------------------------------------------------->


class Solution {
    public:
    // SPECIAL TABULATION from 
    // TC: O(n)
    // SC: O(n)
    // So it's simple problem just like take and not_take.
    /* Good Testcase: [0,4,4,5,9]
                      [0,1,6,8,10];    elements get swapped at 1st index.
    */
    int dp[100050][2];
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        //  0 <= nums1[i], nums2[i] <= 2 * 10^5
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        fill_n(&dp[0][0],(100050*2),INT_MAX);
        dp[0][0]=0; // base case no-swap
        dp[0][1]=1; // base case swap 
        for(int index = 1; index<nums1.size(); index++){
             int prev1 = nums1[index-1];
             int prev2 = nums2[index-1];
     
        // ye upar testcase likha hua hain uska 1st index dekho dono condition true hain
        // to no-swap karke and swap karke bhi dono dekh lo 
        if((prev1<nums1[index]&&prev2<nums2[index])  && (prev1<nums2[index] && prev2<nums1[index])){
            dp[index][0] = min(dp[index-1][0],dp[index-1][1]);  // no swap
            dp[index][1] = min(dp[index-1][0]+1,dp[index-1][1]+1);
        } 

        else if(prev1<nums1[index]&&prev2<nums2[index]){
            dp[index][0] = dp[index-1][0]; // curr not swap and previous also not swapped
            dp[index][1] = dp[index-1][1]+1; // agar curr wale ko swap karna hain to make sure previous wala swapped ho 
        } 

        // swap --> hum swap kar rahe hain strictly increasing banane ke liye
        else{
                dp[index][1]=dp[index-1][0]+1;  // agar curr wala previous se chota hain to curr wale ko swap kardo or previous as it is rahega 
                dp[index][0]=dp[index-1][1];    // agar curr wala previous se chota hain to curr wale ko mat swap karo provided previous wala pehle hi swapped hain
            }
        }

        return min(dp[nums1.size()-1][0],dp[nums1.size()-1][1]);
    }
};





