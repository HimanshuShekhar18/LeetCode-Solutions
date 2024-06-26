class Solution {
public:

    vector<vector<int>> ans;

    void solve(int index, vector<int> &nums, vector<int> &vect){
        if(index<0){
            ans.push_back(vect);
            return;
        }

        //not pick
        solve(index-1,nums,vect);

        // pick
        vect.push_back(nums[index]);
        
        solve(index-1,nums,vect);

        vect.pop_back();

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

            vector<int> vect;

            sort(nums.begin(),nums.end());

            solve(nums.size()-1,nums,vect);

            sort(ans.begin(),ans.end());

            ans.erase(unique(ans.begin(),ans.end()), ans.end());

            return ans;
    }
};


// <--------------------------------------------------------------------------------------------------------------------------------------------------------------------------->



class Solution {
public:

    vector<vector<int>> ans;

    void solve(int index, vector<int> &nums, vector<int> &vect){

            ans.push_back(vect);

            for(int i = index; i<nums.size(); i++){
                if(i!=index && nums[i]==nums[i-1]) continue;
                vect.push_back(nums[i]);
                solve(i+1,nums,vect);
                vect.pop_back();
            }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

            vector<int> vect;
            sort(nums.begin(),nums.end());
            solve(0,nums,vect);

            return ans;
    }
};



// <---------------------------------------------------------------BIT MANIPULATION----------------------------------------------------------------------------------------------------->


class Solution {
public:

    vector<vector<int>> ans;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

            sort(nums.begin(),nums.end());

            int n = nums.size();

            int M = 1<<n;

            vector<vector<int>> ans(M);

            for(int m = 0; m<M; m++){
                for(int i = 0; i<n; i++){
                    if(m & 1<<i) ans[m].push_back(nums[i]);
                }
            }     

            sort(ans.begin(),ans.end());

            ans.erase(std::unique(ans.begin(),ans.end()), ans.end());

            return ans;
    }
};



