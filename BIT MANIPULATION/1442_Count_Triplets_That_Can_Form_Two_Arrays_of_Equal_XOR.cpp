class Solution {
public:
    int countTriplets(vector<int>& arr) {

        int n = arr.size();

        vector<int> xorcalculate(n,0);

        xorcalculate[0] = arr[0];

        for(int i = 1; i<n; i++){
            xorcalculate[i]=xorcalculate[i-1]^arr[i];
        }

        int count = 0;

        if(n==1) return 0;

        for(int i = 0; i<n-1; i++){

            for(int k = i+1; k<n; k++){

                    for(int j = i+1; j<=k; j++){

                            if(i-1>=0) {
                                if((xorcalculate[j-1]^xorcalculate[i-1]) == (xorcalculate[k]^xorcalculate[j-1])) count++;
                            }
                            else {
                                if(xorcalculate[j-1] == (xorcalculate[k]^xorcalculate[j-1])) count++;
                            }

                    }
            }

        }

        return count;
        
    }
};



// <-------------------------------------------------------------------------OPTIMIZED PREFIX XOR-------------------------------------------------------------------------------------->





class Solution {
public:

/*

Optimized Approach:

Basically find those subarray whose XOR = 0; 
These Subarray will be divided into two parts such that XOR of these two parts are equal. let the subarray length = ns  then minimum length  of one part = 1 and maximum length of other part = ns-1

Now Taking the Xor of these two parts will be equal to 0.

For Example: 2 3 1 6 7

Such two Subaray whose XOR = 0 are: 

Subarray [2 3 1]  --> (2), (3,1)  and (2,3), (1)   therefore ans = 3-1 = ns-1;

Subarray [1,6,7] --> (1), (6,7) and (1,6), (7)   therefore ans = 3-1 = ns-1;


TC: O(n*n)
SC: O(n)

*/

    int countTriplets(vector<int>& arr) {

        int n = arr.size();

        vector<int> xorcalculate(n,0);

        xorcalculate[0] = arr[0];

        for(int i = 1; i<n; i++){
            xorcalculate[i]=xorcalculate[i-1]^arr[i];
        }

        int count = 0;

        if(n==1) return 0;

        for(int i = 0; i<n-1; i++){

            for(int j = i+1; j<n; j++){

                        if(i==0){
                            if(xorcalculate[j]==0) count+=j-i;
                        }
                        else {
                            if((xorcalculate[j]^xorcalculate[i-1])==0) count+=j-i;
                        }
            }

        }

        return count;
        
    }
};




