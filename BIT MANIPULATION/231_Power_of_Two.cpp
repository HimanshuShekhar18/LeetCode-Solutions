
class Solution {
public:
    bool isPowerOfTwo(int n) {

        if(n<=0) return false;

        int base = log2(n);

            if(n==pow(2,base)) return true;
            else return false;
    }
};



// <----------------------------------------------------------BIT MANIPULATION----------------------------------------------------------------------------->





class Solution {
public:
    bool isPowerOfTwo(int n) {

        if(n<=0) return false;

        if(n&(n-1)) return false;
        else return true;
    }
};
