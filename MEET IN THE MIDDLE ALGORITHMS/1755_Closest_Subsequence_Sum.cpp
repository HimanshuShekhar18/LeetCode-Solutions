class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {

        vector<long long> left;
        vector<long long> right;

        int nleft;
        int nright;

        if(nums.size()%2==0){
            nleft = nright = nums.size()/2;
        }
        else{
            nleft = nums.size()/2;
            nright = nleft+1;
        }

        for(int i = 0; i<(1<<nleft); i++){
            
            long long lsum = 0;
            for(int j=0; j<nleft; j++){
                if(i&(1<<j)){
                   
                    lsum+=nums[j];
                }
            }
            left.push_back(lsum);
        }

        for(int i = 0; i<(1<<nright); i++){
            long long rsum = 0;
            for(int j=0; j<nright; j++){
                if(i&(1<<j)){
                    rsum+=nums[j+nleft];
                }
            }
            right.push_back(rsum);
        }
        sort(right.begin(),right.end());

        long long ans = INT_MAX;

        for(auto x: left){

            // get the nearest possible value to goal - x in the right vector
            long long to_find = goal-x;

            auto it = lower_bound(right.begin(),right.end(),to_find);

            // checking closest value to goal-x in right side of right vector
            if(it!=right.end()){
                
                ans=min(ans,abs((x+*it)-goal));

            }

            // checking closest value to goal-x in left side of right vector
            if(it!=right.begin()){
                auto itleft = it;
                itleft--;
                ans=min(ans,abs(goal-(x+*itleft)));
            }
        } 
        return ans;   
    }
};

