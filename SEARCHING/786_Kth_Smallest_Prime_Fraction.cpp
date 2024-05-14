class Solution {
public:

/*

Line of Thought: Generate all Subsets and using Max Priotity Queue get the K-th Smallest Prime Fraction 
TC: O(n*n*log(k))  TLE !!

Here it is Subset/Subsequence Generation which takes O(n^2) time Complexity

How to reduce it to O(n)?

Double + BS on Answer(Similar to LeetCode 378 Kth Element in a Sorted Matrix) + Two Pointers

*/


vector<int> numberlessthanorequalto(vector<int> &arr, double mid){

    int j = 1;
    int i = 0;

    int count = 0;

    int ansi = 0;
    int ansj = 0;

    int n = arr.size();

    double max_ratio = 0.0;
    double curr_ratio = 0.0;

        // using two pointers and logic
        while(i<arr.size()-1){

                while(j<n && arr[i]>arr[j]*mid){
                    j++;
                }

                if(j==n) break;

                count+=n-j;

                curr_ratio = (double) arr[i]/arr[j];

                // for saving ansi and ansj
                if(curr_ratio>max_ratio){   // not equal to bcoz jo pehle aaya honga wo na ho sakta hain kth smallest fraction ho
                    max_ratio = curr_ratio;
                    ansi = i;
                    ansj = j;
                }

                i++;
        }

        return {count,arr[ansi],arr[ansj]};


}

    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        

            double left = 0.0,   right = 1.0;

            int ansi = 0, ansj = 0;

            // in Doubles it's very less chance that left == right due to high precision and double calculation

            while(left < right){
                double mid = right - (double)(right-left)/2;

                // here we have to return index i and j not actual value of arr[i]/arr[j]  
                // so at the time we get count == k we return the ansi and ansj

                vector<int> count = numberlessthanorequalto(arr,mid);

                if(count[0]==k){

                    ansi = count[1];
                    ansj = count[2];
                    break;

                }
                else if(count[0]<k){
                    left = mid; // in doubles due to high precision 
                    // or left = mid + 0.000000001
                }
                else {
                    right = mid;
                    // or right = mid-0.000000001
                }


            }

            return {ansi,ansj};          

    }
};
