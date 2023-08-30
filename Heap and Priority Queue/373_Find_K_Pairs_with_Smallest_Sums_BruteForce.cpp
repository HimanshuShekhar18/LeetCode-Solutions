class Solution {
public:
/* BruteForce and Max-Heap
   here brute force chal kyuki k*log(k) wala max-heap use karna hain
   TC: time<O(m*n*log(k)) 
   SC: O(2*k)
*/
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<long long,pair<int,int>>> pq;      
        for(int i = 0; i<nums1.size();i++){
            for(int j = 0; j<nums2.size(); j++){
                long long sum = nums1[i]+nums2[j];
                if(pq.size()<k){
                    pq.push({sum,{i,j}});
                }
                else{
                    if(pq.top().first>sum){
                        pq.pop();
                        pq.push({sum,{i,j}});
                    }
                    else {
                        break;
                    }
                }
            }
        }

        vector<vector<int>> vect;

        while(!pq.empty()){
            int index1 = pq.top().second.first;
            int index2 = pq.top().second.second;
            vect.push_back({nums1[index1],nums2[index2]});
            pq.pop();
        }
        return vect;
    }
};
