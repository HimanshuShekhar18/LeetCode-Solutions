class Solution {
public:

/*

Sorting and Generate all the Subsequences using BIT Manipulation Power Set using find()
Removed abs() 
TC: O(n * n *  2^n) 
SC: O(n) 

*/

    int beautifulSubsets(vector<int>& nums, int k) {

        int n = nums.size();

        int M = 1<<n;

        sort(nums.begin(), nums.end());
        int count = 0;

        
        vector<int> vect;
       

        for(int m = 0; m<M; m++){
            vect.resize(0);
            bool flag = true;

            for(int i = 0; i<n; i++){
                if(m & 1<<i){
                    if(std::find(vect.begin(),vect.end(), nums[i]-k) != vect.end() ){
                            flag = false;
                            break;
                    } 

                    vect.push_back(nums[i]);
                }
            }

            if(flag) count++;
          
        }

        return count-1;        
    }
};



// <------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------>



class Solution {
public:

/*

Khandani Recursion and Backtracking pick and non-pick with conditions while picking 

TC: O(2^n)
SC: O(n)

*/

int count = 0;
int n;

void solve(int index, vector<int>&nums, int k, unordered_map<int,int> &mp){

    if(index==n){
        count++;
        return;
    }

    // not-pick
    solve(index+1,nums,k,mp);

    // pick
    if(mp[nums[index]-k]==0){

            mp[nums[index]]++;  // do 
            solve(index+1,nums,k,mp);
            mp[nums[index]]--;  // backtrack and undo
    }

}
    int beautifulSubsets(vector<int>& nums, int k) {

        n = nums.size();

        sort(nums.begin(),nums.end());

        unordered_map<int,int> mp;

        solve(0,nums,k,mp);

        return count-1;        
    }
};



