class Solution {
public:

    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int start = 0;
        int end = people.size()-1;
        int count = 0;
        while(start<=end){
            
            if(start==end){
                count++;
                break;
            }
            else{
                
                if((people[start]+people[end])<=limit){
                    count++;
                    start++;
                    end--;
                }
                else{
                    count++;
                    end--;
                }
            }            
        }
        return count;
    }
};
