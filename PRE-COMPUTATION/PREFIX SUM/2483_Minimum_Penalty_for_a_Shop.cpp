class Solution {
public:

    /* APPROACH:
    standing at any index i;
     we will check the no. of 'N' present in [0, i)  and the no. of 'Y' present in [i,n];
     TC: O(n)
     SC: O(1) 
    */ 
    int bestClosingTime(string customers) {
        int currpenality = count(customers.begin(),customers.end(),'Y') ;
        int minpenality = currpenality;
        int indexstop = 0;
        for(int i = 0; i<customers.size(); i++){
            if(customers[i]=='Y'){
                currpenality--;
            }
            if(customers[i]=='N') {
                currpenality++;
            }
            if(currpenality<minpenality){
                indexstop=i+1;
                minpenality = currpenality;
            }
        }
        return indexstop;
    }
};



// <-------------------------------------------------------------no base value------------------------------------------------------------------>
class Solution {
public:

    // Same Approach but without considering any base value;
    // let base value = 0;
    // TC: O(n)
    // SC: O(1)

    int bestClosingTime(string customers) {
        int currpenality = 0;
        int minpenality = 0;
        int indexstop = 0;
        for(int i = 0; i<customers.size(); i++){
            if(customers[i]=='Y'){
                currpenality--;
            }
            if(customers[i]=='N') {
                currpenality++;
            }
            if(currpenality<minpenality){
                indexstop=i+1;
                minpenality = currpenality;
            }
        }
        return indexstop;
    }
};

