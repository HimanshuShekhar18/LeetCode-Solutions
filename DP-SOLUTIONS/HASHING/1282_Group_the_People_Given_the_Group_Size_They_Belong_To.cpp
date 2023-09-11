class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        map<int,vector<int>> mp;
        for(int i = 0; i<n; i++){
                mp[groupSizes[i]].push_back(i);
        }

        vector<vector<int>> ans;

        for(auto m: mp){
            int k = m.first;
            int size_of_vector = m.second.size();
            vector<int> element = m.second;
            int loop = size_of_vector/k;
            int start = 0;
            int end = k;
            while(loop--){
                vector<int> vect;
                vect.assign(element.begin()+start,element.begin()+end);
                ans.push_back(vect);
                start=start+k;
                end = end + k;
            }
        }
        return ans;        
    }
};
