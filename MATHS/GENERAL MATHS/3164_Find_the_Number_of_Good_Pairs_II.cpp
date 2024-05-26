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


class FenwickTree {
public:
    vector<long long> bit;
    int n;
    
    FenwickTree(int size) : n(size) {
        bit.resize(n + 1, 0);
    }
    
    void update(int index, long long val) {
        for (; index <= n; index += index & -index) {
            bit[index] += val;
        }
    }
    
    long long query(int index) {
        long long sum = 0;
        for (; index > 0; index -= index & -index) {
            sum += bit[index];
        }
        return sum;
    }
};

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        int maxVal = *max_element(nums1.begin(), nums1.end());
        
        // Multiply nums2 elements by k
        for (int& num : nums2) {
            num *= k;
        }
        
        // Create a Fenwick Tree of appropriate size
        FenwickTree fenwick(maxVal);
        
        // Populate the Fenwick Tree with counts from nums2
        for (int num : nums2) {
            if (num <= maxVal) {
                fenwick.update(num, 1);
            }
        }
        
        long long count = 0;
        
        // For each number in nums1, find divisors and query counts
        for (int num : nums1) {
            for (int d = 1; d * d <= num; ++d) {
                if (num % d == 0) {
                    // Query count of d
                    if (d <= maxVal) {
                        count += fenwick.query(d) - fenwick.query(d - 1);
                    }
                    // If d is not the square root, query count of num / d
                    int otherDiv = num / d;
                    if (otherDiv != d && otherDiv <= maxVal) {
                        count += fenwick.query(otherDiv) - fenwick.query(otherDiv - 1);
                    }
                }
            }
        }
        
        return count;
    }
};




