class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {


        int n = arr.size();

        if(n==1) return arr[0];
        if(n==2) return arr[0]+arr[1];
        if(n==3) return (arr[0]+arr[1]+arr[2])*2;

        long long sum = 0;
        
        for(int i = 0; i<n; i++){
                int occurence = (i/2+1)*((n-i-1)/2+1)+(((i+1)/2)*((n-i)/2));
                sum+=arr[i]*occurence;
        }
        return sum;
    }
};
