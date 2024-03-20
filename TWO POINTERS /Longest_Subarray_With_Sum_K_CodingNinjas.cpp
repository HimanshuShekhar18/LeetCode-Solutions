#include<bits/stdc++.h>
int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    
        long long sum = a[0];
        int maxlength = 0;
        int left = 0, right = 0;

        while(right<a.size()){
            while(left<=right && sum>k){
                sum-=a[left];
                left++;
            }
            if(sum==k) maxlength=max(maxlength,right-left+1);
            right++;
            if(right<a.size()) sum+=a[right];
        }
        return maxlength;
}
