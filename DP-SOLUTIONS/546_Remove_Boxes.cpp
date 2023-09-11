class Solution {
public:
// RANGE and PARTITION DP
// TC: O(n^3)
// Space complexity: O(n^3+2n) --> n^3 = dp array and 2*n = groups vector 
    int dp[101][101][101];
    int removeboxes(int i, int j, int extra, vector<pair<int,int>> &groups){
        if(i>j) return 0;
        if(dp[i][j][extra]!=-1) return dp[i][j][extra];

        int ans = (groups[i].second+extra)*(groups[i].second+extra)+removeboxes(i+1,j,0,groups);

        for(int start = i+2; start<=j; start++){
                if(groups[i].first==groups[start].first){
                    ans = max(ans,removeboxes(i+1,start-1,0,groups)+removeboxes(start,j,extra+groups[i].second,groups));
                }
        }
        return dp[i][j][extra]=ans;
    }
    int removeBoxes(vector<int>& boxes) {
      
      int n = boxes.size();

      vector<pair<int,int>> groups;

      for(int i = 0; i<n; i++){
          int j = i;
          while(i+1<n && boxes[i+1]==boxes[j]) i++;
          groups.push_back({boxes[j],i-j+1});
      }
      memset(dp,-1,sizeof(dp));
      return removeboxes(0,groups.size()-1,0,groups);
    }
};


