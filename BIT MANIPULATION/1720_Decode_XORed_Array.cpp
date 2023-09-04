class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {

        vector<int> decoded;
        decoded.push_back(first);

        for(auto num: encoded){
            first = first^num;
            decoded.push_back(first);
        }
        return decoded;        
    }
};
