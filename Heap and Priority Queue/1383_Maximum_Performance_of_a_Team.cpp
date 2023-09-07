class Solution {
public:
    // SORTING+GREEDY+MIN-HEAP;
    // TC: O(n*log(n))
    // SC: O(2*n)

    const int mod = 1000000007;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        vector<pair<int,int>> vect;
        for(int i = 0; i<n; i++){
            vect.push_back({efficiency[i],speed[i]});
        }
        sort(vect.begin(),vect.end());
        reverse(vect.begin(),vect.end());
        long long sum = 0;
        long long maxi = 0;
        for(int i = 0; i<n; i++){
            // just like Maximum Subsequence Sum, the main work starts after k-1 i.e. from k.
            // Choose at most k different engineers
            if(pq.size()>k-1){
            sum-=pq.top();
            pq.pop();
            }
            // Choose at most k different engineers
            pq.push(vect[i].second);
            sum+=vect[i].second;
            maxi = max(maxi,sum*vect[i].first);
        }
        return maxi%mod;
    }
};
