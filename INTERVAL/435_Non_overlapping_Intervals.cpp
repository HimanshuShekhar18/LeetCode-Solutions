class Solution {
public:

static bool compare(vector<int>&a, vector<int>&b){
    return a[1] < b[1];
}
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
      
        int ans = 0;

        sort(intervals.begin(),intervals.end(), compare);

          int k = intervals[0][1];

        for(int i = 1; i<intervals.size(); i++){
                int x = intervals[i][0];
                int y = intervals[i][1];

                if(x>=k) {
                    k = y;
                    continue;
                } 

                ans++;
        }

        return ans;

    }
};
