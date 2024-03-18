class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        cout << intervals[0][0] << intervals[0][1] << endl;
        vector<vector<int>> ans;
        ans.push_back({intervals[0][0],intervals[0][1]});
        int k = intervals[0][1];
        int start = intervals[0][0];
        for(int i = 1; i<intervals.size(); i++){

            int x = intervals[i][0];
            int y = intervals[i][1];

            if(x<=k){
                ans.pop_back();
                cout << start << y << endl;
                if(k>=y) ans.push_back({start,k});
                else{
                    ans.push_back({start,y});
                    k = y;
                } 
            }
            else {
                   start = x;
                   k = y;
                   ans.push_back({start,y});
            }
        }

        return ans;
    }
};

