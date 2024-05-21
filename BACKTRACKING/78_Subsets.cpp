class Solution {
public:

    vector<vector<int>> ans;

    void solve(int index, vector<int>&nums, vector<int>&vect){
            if(index<0){
                ans.push_back(vect);
                return;
            }

            vect.push_back(nums[index]);

            solve(index-1,nums,vect);

            if(!vect.empty()) vect.pop_back();

            solve(index-1,nums,vect);

            return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {

            vector<int> vect;           

            solve(nums.size()-1,nums,vect);

            return ans;
        
    }
};


// <------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------>


class Solution {
public:

    vector<vector<int>> ans;

    void solve(int index, vector<int>&nums, vector<int>&vect){
        
            ans.push_back(vect);

            for(int i = index; i<nums.size(); i++){
                vect.push_back(nums[i]);  // pick
                solve(i+1,nums,vect);
                vect.pop_back();   // not-pick
            }

            return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {

            vector<int> vect;           

            solve(0,nums,vect);

            return ans;
        
    }
};



// <------------------------------------------------------------------BIT-MASKING--------------------------------------------------------------------------------------------------------->



class Solution {
public:

    

    vector<vector<int>> subsets(vector<int>& nums) {

            vector<int> vect;  

            int n = nums.size();

            int M = 1<<n;

            vector<vector<int>> ans(M);

            for(int m = 0; m<M; m++){
                for(int i = 0; i<n; i++){
                    if(m & 1<<i) ans[m].push_back(nums[i]);
                }
            }        

            return ans;
        
    }
};


