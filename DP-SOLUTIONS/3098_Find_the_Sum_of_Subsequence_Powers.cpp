class Solution {
public:

/*

TLE

Sorting and Starting from "n-1"  and using only "int"
4D-DP  and unordered_map ( states are index, lastindex, k, mindiff )
TC: O(n*n*n*(n*n)) + O(n*log(n))
SC: O(n*n*n*(n*n)) 
where n ϵ [0,50]

*/
 
    const int mod = 1e9+7;

    // since size of elements goes upto upto 2*10^8, hence normal vector DP cannot be used hence we use unordered_map which takes O(n) time complexity due to large inputs
    unordered_map<int,unordered_map<int,unordered_map<int,unordered_map<int,int>>>> dp;

    int solve(int index, int lastindex, vector<int> &nums,int k, long long diff ){
        if(k==0)
        { 
          return  diff;
        }

        if(index<0) return 0;

        // using count() instead of find() --> time efficient
        if(dp.count(index) && dp[index].count(lastindex) && dp[index][lastindex].count(k) && dp[index][lastindex][k].count(diff)) {
           
            return dp[index][lastindex][k][diff];
        }

        // long long mindiff = lastindex==-1 ? INT_MAX : min(diff,(long long)(nums[index]-nums[lastindex])%mod); 
        int mindiff = diff;
        if(lastindex!=-1){
            int temp = abs(nums[index]-nums[lastindex]);
            if(temp<diff){
                mindiff = temp;
            }
        }

        // take
        long long sum1 = solve(index-1,index,nums,k-1,mindiff);
  
        // non-take
        long long sum2 = solve(index-1,lastindex,nums,k,diff);
    
        
        return dp[index][lastindex][k][diff]=(sum1+sum2)%mod;
    }

    int sumOfPowers(vector<int>& nums, int k) {

        sort(nums.begin(),nums.end());
        
        // start from 0, it doesn't matter whether you start from 0 or n-1;
        return solve(nums.size()-1,-1,nums,k,INT_MAX)%mod;
    }
};


// <------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------>



class Solution {
public:

/*

Sorting and Starting from "0" or "n-1"
3D-DP  Removing "lastindex" state and unordered_map ( states are index, k, mindiff )
TC: O(n*n*n*(n*n)) + O(n*log(n))
SC: O(n*n*(n*n)) 
where n ϵ [0,50]  


*/
 
    const int mod = 1e9+7;
    int n;
    // since size of elements goes upto upto 2*10^8, hence normal vector DP cannot be used hence we use unordered_map which takes O(n) time complexity due to large inputs
    unordered_map<int,unordered_map<int,unordered_map<int,int>>> dp;

    int solve(int index, vector<int> &nums,int k, int diff ){
        if(k==0)
        { 
          return  diff;
        }

        if(index==n) return 0;

        // using count() instead of find() --> time efficient
        if(dp.count(index) && dp[index].count(k) && dp[index][k].count(diff)) {
            return dp[index][k][diff];
        }

        long long ans = 0;
        for(int j = index; j<n; j++){

            int mindiff = diff;
            if(index>0) mindiff = min(mindiff,abs(nums[j]-nums[index-1]));
            ans+=solve(j+1,nums,k-1,mindiff);
        }
    
        return dp[index][k][diff]=(ans)%mod;
    }

    int sumOfPowers(vector<int>& nums, int k) {

        n = nums.size();
        // we are going to sort the array so that consecutive elements give the least absolute difference in the sequence.
        sort(nums.begin(),nums.end());
        
        return solve(0,nums,k,INT_MAX)%mod;
    }
};




// <-------------------------------------------------------------------------- SINGLE DP OPTIMIZATION-------------------------------------------------------------------------------------->


class Solution {
public:

/*

3D-DP and DP OPTIMIZATION

i) Generate all unique difference and store all them into diffs vectors in ascending order

ii) Starting from the back( largest difference ) calculate the count of subsequence  of length 'k' having differences >= d, for each difference 'd'

iii) To ensure the participation of only "d" atleast once in the subsequence subtract the count subsequence of smaller difference - count subsequence of larger differences.

eg: {},4,7}  and d = 2

abs(1-4) = 3 >= 2
abs(1-7) = 6 >= 2
abs(4-7) = 3 >= 2

but here the difference is not = 2 (at least once); hence this subsequence should not be counted !!

iv) To avoid TLE, precompute for each index next[index][d]  i.e. next position/element such that difference is >= d.

TC: O(n*n*(n*n))
SC: O(n*(n*n))

*/
 
    const int mod = 1e9+7;
    int n;
    // since size of elements goes upto upto 2*10^8, hence normal vector DP cannot be used hence we use unordered_map which takes O(n) time complexity due to large inputs
    unordered_map<int,unordered_map<int,unordered_map<int,int>>> dp;

    int solve(int index, int k, int d, vector<vector<int>> &next ){

        if(k==0) return  1;

        if(index==n) return 0;

        // using count() instead of find() --> time efficient
        if(dp.count(index) && dp[index].count(k) && dp[index][k].count(d)) {
            return dp[index][k][d];
        }

        long long ans = 0;
        
        ans+=(solve(index+1,k,d,next)+solve(next[index][d],k-1,d,next))%mod;
        
    
        return dp[index][k][d]=ans;

}

    int sumOfPowers(vector<int>& nums, int k) {

        n = nums.size();
        // we are going to sort the array so that consecutive elements give the least absolute difference in the sequence.
        sort(nums.begin(),nums.end());

        set<int> unique_diff;

        // i)
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                unique_diff.insert(abs(nums[i]-nums[j]));
            }
        }

        vector<int> diffs(unique_diff.begin(),unique_diff.end());
        vector<vector<int>> next(n, vector<int> (diffs.size(), 0));

        // iv) 
        for(int d = 0; d<diffs.size(); d++){

            for(int i = 0; i<n; i++){
                next[i][d] = n;
                for(int j = i+1; j<n; j++){
                    if(abs(nums[i]-nums[j])>=diffs[d]){
                        next[i][d] = j;
                        break;
                    } 
                }
            }
        }

        long long prev_cnt = 0;
        long long ans = 0;

        // ii) 
        for(int d = diffs.size()-1; d>=0; d--){

            long long diff = diffs[d];
            long long curr_cnt = solve(0,k,d,next);
            ans=(ans+(diff*(curr_cnt-prev_cnt))%mod)%mod;  // iii)
            prev_cnt=curr_cnt;

        }
        
        return ans;

    }
};

