class Solution {
public:
/* Optimal Solution and Min-Heap
    
                                    (i,j)
                                   `    `
                                  `      `
                                 `        `
                             (i+1,j)     (i,j+1)
   TC: O(k) 
   SC: O(3*k)
*/

// ALERT !!!!!!!!!!!!!!!!!!!!!!!!
// MISTAKE DONE: Duplicate ka bhi track rakhna hain
// hence use a "set" data structure

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<long long,pair<int,int>>,vector<pair<long long,pair<int,int>>>, greater<pair<long long,pair<int,int>>>> pq; 
        pq.push({nums1[0]+nums2[0],{0,0}});
        vector<vector<int>> vect;
        set<pair<int,int>> st;
        st.insert({0,0});
        while(k--){
            if(pq.empty()) break;
            int index1 = pq.top().second.first;
            int index2 = pq.top().second.second;
            vect.push_back({nums1[index1],nums2[index2]});
            pq.pop();
            if(index1+1<nums1.size() && st.find({index1+1,index2})==st.end()) {
                pq.push({nums1[index1+1]+nums2[index2],{index1+1,index2}});
                st.insert({index1+1,index2});
            }
            if(index2+1<nums2.size() && st.find({index1,index2+1})==st.end()) {
                pq.push({nums1[index1]+nums2[index2+1],{index1,index2+1}});
                st.insert({index1,index2+1});
            }
        }  
        return vect;
    }
};
