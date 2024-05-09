class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {

        int ans = 0;

        int start = 1, end = *max_element(candies.begin(), candies.end());

        sort(candies.begin(),candies.end());

        int mid = 0;

        while(start<=end){

            mid = (start+end)/2;

            auto lower = lower_bound(candies.begin(),candies.end(),mid);

            if(lower==candies.end()){
                end = mid-1;
            }
            else{

                int position = lower-candies.begin();

                long long count = 0;
                for(int i = position; i<candies.size(); i++){
                    count+=candies[i]/mid;
                }

                if(count>=k) {
                    start = mid+1;
                    ans = mid;
                }
                else end = mid-1;                
            }
        }
        return ans;
    }
};
