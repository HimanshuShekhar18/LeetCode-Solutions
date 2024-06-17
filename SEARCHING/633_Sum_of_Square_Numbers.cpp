class Solution {
public:
    bool judgeSquareSum(int c) {

        int left = 0;
        int right = sqrt(c);

        while(left<=right){

            int mid = right-(right-left)/2;

            int val  = mid*1LL*mid;

            if(left*1LL*left+right*1LL*right==c) return true;

            if(left*1LL*left+val==c || val+right*1LL*right==c){
                return true;
            }

            if(val+right*1LL*right<c){
               left=mid+1; 
               continue;
            }
            else if(val+left*1LL*left>c){
                right=mid-1;
                continue;
            }
            
            if(left*1LL*left+right*1LL*right<c) left++;
            else right--;
        }

        return false;
    }
};
