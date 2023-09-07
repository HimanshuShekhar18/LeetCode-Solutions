class Solution {
public:
    // Binary Search
    int mySqrt(int x) {
        int start = 0;
        int end = x;
        long long sqaure;
        int ans;
        while(start<=end){
            int mid = start+(end-start)/2;
            sqaure = mid*1LL*mid; // changes done here to have long long
            if(sqaure==x) return mid;
            else if(sqaure<x) ans=mid,start=++mid;
            else end=--mid;
        }
        return ans;
    }
};
