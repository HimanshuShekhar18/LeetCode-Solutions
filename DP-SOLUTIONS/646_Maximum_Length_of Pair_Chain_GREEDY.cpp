class Solution {
public:

    static bool comparator(vector<int> &a, vector<int> &b){
        if(a[1]<b[1]) {
             return true;
        }
        else return false;
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),comparator);
        
        int ans = 0;
        int prev = -1100;
        
	for (int i = 0; i < pairs.size(); ++i)
	{
        if(pairs[i][0]>prev){
            prev=pairs[i][1];
            ans++;
        }
	}
        return ans;   
    }
};
