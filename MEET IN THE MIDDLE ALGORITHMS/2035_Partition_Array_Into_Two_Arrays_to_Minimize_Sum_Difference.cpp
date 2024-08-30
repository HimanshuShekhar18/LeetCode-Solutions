class Solution {
public:

/*

Meet in the Middle, Subsets Sum, Bitmask, and  STL lower_bound 
O(2^(n/2) ∗ (n/2) * log(n/2) )
SC: O( 2^(n/2) )
where  n  =  nums.length()

*/
    int minimumDifference(vector<int>& nums) {
        int n = nums.size()/2;
        int totalsum = 0;
        totalsum = accumulate(nums.begin(),nums.end(),0);
       
        vector<vector<int>> left(n+1);
        vector<vector<int>> right(n+1);

        for(int i = 0; i<(1<<n); i++){
            int l = 0;
            int r = 0;
            int size = 0;
            for(int j = 0; j<n; j++){
                if(i&(1<<j)){
                    size++;
                    l+=nums[j];
                    r+=nums[j+n];            
                }
            }

            left[size].push_back(l);
            right[size].push_back(r);
        }

        // sorting the right array
        for(int i = 0; i<=n; i++){
            sort(right[i].begin(),right[i].end());
        }

        // min(abs(totalsum-2*sum1));
        // constructing sum1 array of length 'n' by either taking fully left or right.
        int ans = min(abs(totalsum-2*left[n][0]),abs(totalsum-2*right[n][0]));

        // checking all possible combination to construct sum1 array by taking "l" elements from left and simultaneously "n-l" elements from right
        // totalsum-(2*sum1) >= 0  -->   totalsum-2*(a+b) >= 0  -->  (totalsum-2*a)/2 >= b
        for(int sz = 1; sz<n; sz++){
            for(auto a: left[sz]){
                int rightsize = n-sz;
                int b = (totalsum-2*a)/2;

                auto it = lower_bound(right[rightsize].begin(),right[rightsize].end(),b);

                if(it!=right[rightsize].end()) ans = min(ans,abs(totalsum-2*(a+*it)));
            }
        }

        return ans;
    }
};

