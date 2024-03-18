class Solution {
public:
   vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>> dummy = intervals;
        dummy.push_back(newInterval);
        sort(dummy.begin(), dummy.end());
        
        vector<vector<int>> ans;
        ans.push_back({dummy[0][0],dummy[0][1]});
        int k = dummy[0][1];
        int start = dummy[0][0];
        for(int i = 1; i<dummy.size(); i++){

            int x = dummy[i][0];
            int y = dummy[i][1];

            if(x<=k){
                ans.pop_back();
                
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
