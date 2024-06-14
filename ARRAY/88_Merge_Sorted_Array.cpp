class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i = 0, j = 0;

        vector<int> vect = nums1;

        while(i<m && j<n){

            if(vect[i]<=nums2[j]){
                nums1[i+j]=vect[i];
                i++;
            }
            else{
                nums1[i+j] = nums2[j];
                j++;
            }
        }

        if(i<m){
            for(int index = i; index<m; index++){
                nums1[index+j]=vect[index];
            }
        }
        else{
           for(int index = j; index<n; index++){
                nums1[index+i]=nums2[index];
            }
        }      
    }
};


// <-----------------------------------------------------------------------------------Space Optimization Two-Pointer Traversing in Right to Left Direction ------------------------------------------------------------->

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        /*
        How can we space Optimized it??

        Here the usage of extra 'n' zeroes present in nums1;

        So we will traverse in right to left direction and fill up those 0's position

        TC: O(n+m)
        SC: O(1)

        */

        int i = m-1, j = n-1;
        int k = m+n-1;

        while(i>=0 && j>=0){
            if(nums1[i]<=nums2[j]){
                nums1[k]=nums2[j];
                j--;
                k--;
            }
            else{
                nums1[k] = nums1[i];
                i--;
                k--;
            }
        }

        while(j>=0){
            nums1[k]=nums2[j];
            j--;
            k--;
        }     
    }
};
