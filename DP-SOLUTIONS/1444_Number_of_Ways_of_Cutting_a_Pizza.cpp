class Solution {
public:
    int rows;
    int cols;
    const int mod = 1000000007;
    int dp[55][55][15];
    int Cutting(vector<vector<int>> &apples, int people, int i, int j ){
        // initial check, while entering any rectangle
        if(apples[i][j] < people) return 0; // i.e. sufficient apples are not available to fed required person
        if(people==1) {
            if(apples[i][j]>=1) return 1;
            return 0;
        }
        if(dp[i][j][people]!=-1) return dp[i][j][people];
        long long ans = 0;   // slight changes done here
        // Horizontal 
            for(int hcut = i+1; hcut<rows; hcut++){
                    int lower_slice = apples[hcut][j];
                    int upper_slice = apples[i][j]-lower_slice;
                    if(upper_slice >=1 && lower_slice >= people-1) ans+=Cutting(apples, people-1, hcut, j);
            }
        // Vertical 
            for(int vcut = j+1; vcut<cols; vcut++){
                    int right_slice = apples[i][vcut];
                    int left_slice = apples[i][j]-right_slice;
                    if(left_slice >=1 && right_slice >= people-1) ans+=Cutting(apples, people-1, i, vcut);
            }

            return dp[i][j][people]=ans%mod;
    }
    int ways(vector<string>& pizza, int k) {
    rows = pizza.size();
    cols = pizza[0].size();
    vector<vector<int>> apples(rows+1,vector<int> (cols+1,0));
    // storing how many apples available at any row and column
    // starting from bottom-right
    for(int i = rows-1; i>=0; i--){
        for(int j = cols-1; j>=0; j--){
            apples[i][j]=apples[i][j+1]+apples[i+1][j]-apples[i+1][j+1];
            if(pizza[i][j]=='A') apples[i][j]++;
        }
    }
    memset(dp,-1,sizeof(dp));
    return Cutting(apples,k,0,0);    
    }
};



// <-------------------------------------------------------------TABULATION------------------------------------------------------------------------------------------->



