class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> ans(rowIndex+1);
        ans[0].push_back(1);
        if(rowIndex==0){
        return ans[rowIndex];
        }
        ans[1].push_back(1);
        ans[1].push_back(1);
        if(rowIndex==1){
            return ans[rowIndex];
        }
        for(int i = 2; i<=rowIndex; i++){
            ans[i].push_back(1);
            for(int j = 0; j<ans[i-1].size()-1; j++){
                ans[i].push_back(ans[i-1][j]+ans[i-1][j+1]);
            }
            ans[i].push_back(1);
        }
        return ans[rowIndex];
    }
};
