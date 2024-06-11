class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {

        vector<int> notpresent;

        unordered_map<int,int> mp;


        for(int i = 0; i<arr2.size(); i++){
            mp[arr2[i]]++;
        }

        for(int i = 0; i<arr1.size(); i++){

                if(mp[arr1[i]]){
                    mp[arr1[i]]++;
                }
                else{
                    notpresent.push_back(arr1[i]);
                }
        }

        vector<int> ans;

        for(int i = 0; i<arr2.size(); i++){
            mp[arr2[i]]--;
            ans.insert(ans.end(),mp[arr2[i]],arr2[i]);
        }

        int k = -1;
        if(notpresent.size()) k = *max_element(notpresent.begin(),notpresent.end());
        else return ans;

        vector<int> count(k+1,0);

        for(int i = 0; i<notpresent.size(); i++){
            count[notpresent[i]]++;
        }

        for(int i = 1; i<=k; i++){
            count[i]+=count[i-1];
        }

        vector<int> sortednotpresent(notpresent.size());

        for(int i = 0; i<notpresent.size(); i++){
            sortednotpresent[--count[notpresent[i]]] = notpresent[i];
        }

        ans.insert(ans.end(),sortednotpresent.begin(),sortednotpresent.end());

        return ans;
        
    }
};
