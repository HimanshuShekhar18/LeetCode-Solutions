class Solution {
public:
    // SORTING + GREEDY + MAX-HEAP
    // TC: O(n)+O(n)+O(k)
    // SC: O(2*n)+O(n)
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        priority_queue<int> pq;    // max-heap
        vector<pair<int,int>> vect;
        
        for(int i = 0; i<n; i++){
            vect.push_back({capital[i],profits[i]});
        }
        // will sort in ascending order of capital and profit ka maximum value lete hue 
        sort(vect.begin(),vect.end());
        long long sum = w;
        long long maxi = 0;
        int i = 0;
         while(k){
             while(i<n && sum>=vect[i].first){
                 pq.push(vect[i].second);
                 i++;
             }
             if(!pq.empty()){
                 sum+=pq.top();
                 pq.pop();
             }
            k--;
         }
        return sum;
    }
};

