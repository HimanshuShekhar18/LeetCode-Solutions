class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {

        int n = nums1.size();
        int m = nums2.size();

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        for (int j = 0; j < m; j++) {
            nums2[j] = nums2[j] * k;
        }

        unordered_map<long long ,  long long> num2Count;

        for (int num : nums2) {
            num2Count[num]++;
        }

        long long count = 0;

        for (int i = 0; i < nums1.size(); i++) {
                          
                for (int j = 1; j <= sqrt(nums1[i]); j++) {

                    if (nums1[i] % j == 0) {
                        
                        if (nums1[i] / j == j){
                            count+=num2Count[j];
                        }                           

                        else {
                            count+=num2Count[j];
                            count+=num2Count[nums1[i]/j];
                        }
                            
                    }
                }
        }

        return count;
    }
};



// <--------------------------------------------------------------BIT/FENWICK TREE---------------------------------------------------------------------------------------------------->



