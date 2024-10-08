/*
less_equal ordered_set Approach 
To find element in less_equal ordered_set use upper_bound()  
TC: O(n*log(k))  SC: O(n) 
*/

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<long long, null_type, less_equal<long long>, rb_tree_tag,tree_order_statistics_node_update>

class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {

        long long ans = nums[0];

        int n = nums.size();

        ordered_set st;

        // for the first window
        for (int i = 1; i <= dist + 1; i++) {
            st.insert(nums[i]);
        }

        // for smaller 'k-2' values
        for (int i = 0; i < k - 1; i++) {
            ans += *(st.find_by_order(i));
        }

        long long sum = ans;

        // for the other windows
        for (int i = dist + 1; i < n - 1; i++) {
            if (st.order_of_key(nums[i - dist]) <= k - 2) {
                ans -= nums[i - dist];
                ans += *(st.find_by_order(k - 1));
            }

            st.insert(nums[i + 1]);
            // In less_equal ordered_set, use upper_bound(x)  
            st.erase(st.upper_bound(nums[i - dist]));

            if (st.order_of_key(nums[i + 1]) <= k - 2) {
                ans += nums[i + 1];

                ans -= *(st.find_by_order(k - 1));
            }
            sum = min(sum, ans);
        }
        return sum;
    }
};



// <----------------------------------------------------------------TWO MULTISETS--------------------------------------------------------------------------------------------------------->

/*
Two Multiset and Sliding Window
TC: O(n*log(k))
SC: O(n)
*/

class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {

        long long ans = nums[0];

        int n = nums.size();

        multiset<int> st1;
        multiset<int> st2;

        // for the first window Add the first 'dist + 1' elements to the left multiset
        for (int i = 1; i <= dist + 1; i++) {
            st1.insert(nums[i]);
        }

        // for smaller 'k-1' values
        auto it = st1.begin();
        for (int i = 0; i < k - 1; i++) {
            ans += *(it);
            ++it;
        }

        // Deleting access elements in st1 and saving those in st2
        while(st1.size()>k-1){
            st2.insert(*(st1.rbegin()));
            st1.erase(st1.find(*(st1.rbegin())));
        }

   
        long long sum = ans;

        // for the other windows
        for (int i = dist + 1; i < n - 1; i++) {

            int to_delete = nums[i-dist];

            if(st1.find(to_delete)!=st1.end()){
                sum-=to_delete;
                st1.erase(st1.find(to_delete));
            }
            else{
                st2.erase(st2.find(to_delete));
            }

            int to_add = nums[i+1];

            if( to_add <= *st1.rbegin()){
                sum+=to_add;
                st1.insert(to_add);
            }
            else{
                st2.insert(to_add);
            }

            // if st1 contains less elements than k-1
            while(st1.size()<k-1){
                
                sum+= *st2.begin();
                st1.insert(*(st2.begin()));
                st2.erase(st2.find(*st2.begin()));
            }

            // if st1 contains more elements than k-1
            while(st1.size()>k-1){
                sum-=*(st1.rbegin());
                st2.insert(*(st1.rbegin()));
                st1.erase(st1.find(*st1.rbegin()));
            }
        
            ans = min(ans, sum);
        }
        
        return ans;
    }
};



