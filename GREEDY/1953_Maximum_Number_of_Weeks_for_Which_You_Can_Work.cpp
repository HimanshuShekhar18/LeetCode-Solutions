class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {

/*

TLE Approach 

Priority Queue Approach Exactly Same as 621. Task Scheduler
but TLE due to large constraint  1 <= milestones[i] <= 109


        long long ans = 0;
        if(milestones.size()==1) return 1;

        priority_queue<long long> pq;


        for(int i = 0; i<milestones.size(); i++){
            pq.push(milestones[i]);
        }


            while(!pq.empty()){

                if(pq.size()==1) {
                    ans+=1;
                    break;
                }

                vector<long long> temp;

                for(int i = 0; i<2; i++){
                    temp.push_back(pq.top());
                    pq.pop();
                }

                for(int i = 0; i<temp.size(); i++){

                        if(--temp[i]>0) pq.push(temp[i]);

                }

                
                
                    ans+=2;
                

            }

            return ans;

*/


// sum including all other elements excluding only single occurence of  maxi elements
long long othersum = 0;

long long sum = 0;

long long maxi = *max_element(milestones.begin(),milestones.end());

        for(int i = 0; i<milestones.size(); i++){

                sum+=milestones[i];

        }

        othersum = sum-maxi; // excluding only single occurence of maxi

        if(maxi<=othersum) return othersum+maxi;
        else return 2*othersum+1;
    }
};
