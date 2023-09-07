class Solution {
public:
    // TLE APPROACH
    // DP-Approach
    // Here in this DP, 4-states are changing --> sum, min, index, count
    //Hence it becomes 4D-DP, so even if we try to memoize it, it will return TLE.
    // TC: O(2^n)
    // SC: O(n)+O(n^2) = priority queue + recursive stack space(each_recursive_call*call_for_priority_queue)
    int n;
    priority_queue<int,vector<int>, greater<int>> pq;
    void removefrompq(int num){
        vector<int> temp;
        while(!pq.empty()){
            int x = pq.top();
            pq.pop();
            if(x==num) break;
            temp.push_back(x);
        }
        for(auto &number: temp){
            pq.push(number);
        }
    }
    long long solvedp(vector<int>& nums1, vector<int>& nums2, long long sum, int min, int index, int count, int k){
        if(count==k) return sum*min;
        if(index>=n) return 0;
        pq.push(nums2[index]);
        long long take = solvedp(nums1,nums2,sum+nums1[index],pq.top(),index+1, count+1, k);
        removefrompq(nums2[index]);
        long long nottake = solvedp(nums1,nums2,sum,min,index+1, count, k);
        return max(take,nottake);
    }
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        while(!pq.empty()){
            pq.pop();
        }
        n = nums1.size();
        return solvedp(nums1,nums2,0,0,0,0,k);
    }
};



// <--------------------------------------------------------------------Optimal Priority Queue Solution ------------------------------------------------------------------>

// SORTING+GREEDY+MIN-HEAP;
// TC: O(n*log(n))
// SC: O(2*n)

int n;
long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        n = nums1.size();
        priority_queue<int,vector<int>,greater<int>> pq;
        vector<pair<int,int>> vect;
        for(int i = 0; i<n; i++){
            vect.push_back({nums2[i],nums1[i]});
        }
        sort(vect.begin(),vect.end());
        reverse(vect.begin(),vect.end());
        long long sum = 0;
        for(int i = 0; i<=k-1; i++){
            pq.push(vect[i].second);
            sum+=vect[i].second;
        }
        long long maxi = sum*(vect[k-1].first);
        for(int i = k; i<n; i++){
            sum+=vect[i].second-pq.top();
            maxi = max(maxi,sum*vect[i].first);
            pq.pop();
            pq.push(vect[i].second);
        }
        return maxi;
    }
};

