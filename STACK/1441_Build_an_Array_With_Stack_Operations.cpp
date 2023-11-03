class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> s;
        vector<int> ans;
        int j = 0;
        for(int i = 1; i<=n; i++){
            if(ans==target) break;
            if(target[j]==i){
                s.push_back("Push");
                ans.push_back(target[j]);
                j++;
            }
            else {
                s.push_back("Push");
                s.push_back("Pop");
            }
        }
        return s;
    }
};
