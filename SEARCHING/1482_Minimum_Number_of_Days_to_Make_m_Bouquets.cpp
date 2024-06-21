class Solution {
public:

    bool check(vector<int>&bloomDay, int m, int k, int mid){
        int count = 0;
        int adjacent = 0;

        for(int i = 0; i<bloomDay.size(); i++){

            if(bloomDay[i]<=mid){

                 adjacent++;

                    if(adjacent==k){
                        adjacent=0;
                        count++;
                    }
            }
            else{
                adjacent = 0;
            }
        }

        return count>=m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        if(m*1LL*k>bloomDay.size()) return -1;

        int left = *min_element(bloomDay.begin(),bloomDay.end());
        int right = *max_element(bloomDay.begin(),bloomDay.end());

        int ans = 0;

        while(left<=right){

            int mid = right-(right-left)/2;

            if(check(bloomDay,m,k,mid)){
                ans=mid;
                right=mid-1;
            }
            else{
                left = mid+1;
            }
        }

        return ans;
        
    }
};

