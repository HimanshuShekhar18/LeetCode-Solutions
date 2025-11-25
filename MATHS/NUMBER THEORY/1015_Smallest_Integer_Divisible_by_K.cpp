class Solution {
public:
    int smallestRepunitDivByK(int k) {
        // base case
        if(k%2==0 || k%5==0) return -1;
        int num = 1;
        int count = 1;
        while(num%k!=0){
            num=num*10+1;
            num=num%k; // mod by k, to avoid extra multiples of k
            ++count;
        }
        return count;
    }
};
