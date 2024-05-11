// <--------------------------------------------------------------BRUTE FORCE TLE ----------------------------------------------------------------------------------------------->

class Solution {
public:
/*

Brute FOrce

Algorithm:

Considering each worker as a manager while rest worker as normal worker

Maintaining the ratio

  quality of each rest worker           new wage of each rest worker 
  __________________________     =     _______________________________
      quality of manager                      wage of manager

    
    new wage of each rest worker = wage of manager *   quality of each rest worker
                                                       _____________________________
                                                          quality of manager
    
    Now check for k min wages for each manager loop

    TC: O(n*(n + n*log(k)))
    SC: O(n)
*/
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {

        double result = DBL_MAX;

        for(int manager = 0; manager<wage.size(); manager++){

            vector<double> group;

            for(int worker = 0; worker<wage.size(); worker++){

                    double worker_wage = (double) wage[manager] *  ((double) quality[worker]/(double) quality[manager]);
                
                    if(worker_wage>=wage[worker]){
                        group.push_back(worker_wage);
                    }
            }

            if(group.size()<k){
                continue;
            }

            double sum = 0;

            priority_queue<double> pq;

            for(auto g: group){

                sum+=g;
                pq.push(g);

                while(pq.size()>k){
                    sum-=pq.top();
                    pq.pop();
                }

            }

            result = min(result,sum);

        }
        
        return result;
    }
};




// <--------------------------------------------------------------OPTIMAL BRUTE FORCE----------------------------------------------------------------------------->


class Solution {
public:

/*

Optimal Brute FOrce 
This time Maintaining the Ratio and Sorting according to ascending order of Ratio

Algorithm:

Considering each worker as a manager while rest worker as normal worker

Maintaining the ratio

  quality of each rest worker           new wage of each rest worker 
  __________________________     =     _______________________________
      quality of manager                      wage of manager

    
    new wage of each rest worker = wage of manager *   quality of each rest worker
                                                       _____________________________
                                                          quality of manager

     Important: 
    new wage of each rest worker >= min_wage of each rest worker

    wage of manager * quality of each rest worker
                      ____________________________  >= min_wage of each rest worker
                        quality of manager 


    wage of manager              min_wage of each rest worker
    __________________    >=    ________________________________
   quality of manager               quality of each rest worker


    therefor ratio of manager >= ratio of each rest worker 

    or ratio of manager * quality of each rest worker >= min_wage of each rest worker

    sort the ratios in ascending order
    

    Now check for k min wages using max-heap for each manager loop

    TC: O(n*(n + n*log(k)))
    SC: O(n)
*/
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {

        double result = DBL_MAX;

        vector<pair<double,int>> ratios;

        for(int i = 0; i<wage.size(); i++){

                ratios.push_back(make_pair(((double) wage[i] / (double) quality[i]), quality[i]));

        }

        sort(ratios.begin(), ratios.end());

        for(int manager = k-1; manager<wage.size(); manager++){

            vector<double> group;

            double manager_ratio = ratios[manager].first;

            for(int worker = 0; worker<=manager; worker++){

                    double worker_wage = (double) manager_ratio * ratios[worker].second;
                
                    
                        group.push_back(worker_wage);
                    
            }

            if(group.size()<k){
                continue;
            }

            double sum = 0;

            priority_queue<double> pq;

            for(auto g: group){

                sum+=g;
                pq.push(g);

                while(pq.size()>k){
                    sum-=pq.top();
                    pq.pop();
                }

            }

            result = min(result,sum);

        }
        
        return result;
    }
};




// <--------------------------------------------------------------------OPTIMAL SORTING + GREEDY + MAX-HEAP------------------------------------------------------------------------->


class Solution {
public:

/*

Optimal Greedy + Sorting + Max-Heap

This time Avoiding Repeating Addition of quality of each rest worker 


    TC: O(n*log(n))
    SC: O(n)


This time Maintaining the Ratio and Sorting according to ascending order of Ratio

Algorithm:

Considering each worker as a manager while rest worker as normal worker

Maintaining the ratio

  quality of each rest worker           new wage of each rest worker 
  __________________________     =     _______________________________
      quality of manager                      wage of manager

    
    new wage of each rest worker = wage of manager *   quality of each rest worker
                                                       _____________________________
                                                          quality of manager

    Important: 
    new wage of each rest worker >= min_wage of each rest worker

    wage of manager * quality of each rest worker
                      ____________________________  >= min_wage of each rest worker
                        quality of manager 


    wage of manager              min_wage of each rest worker
    __________________    >=    ________________________________
   quality of manager               quality of each rest worker


    therefor ratio of manager >= ratio of each rest worker 

    or ratio of manager * quality of each rest worker >= min_wage of each rest worker

    sort the ratios in ascending order
    

    Now check for k min wages using max-heap for each manager loop


*/
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {

        double result = DBL_MAX;

        vector<pair<double,int>> ratios;

        for(int i = 0; i<wage.size(); i++){

                ratios.push_back(make_pair(((double) wage[i] / (double) quality[i]), quality[i]));

        }

        sort(ratios.begin(), ratios.end());

        priority_queue<double> pq;

        double sum = 0;

        for(int i = 0; i<k; i++){
            sum+=ratios[i].second;
            pq.push(ratios[i].second);
        }

        result = sum*ratios[k-1].first;

        for(int manager = k; manager<wage.size(); manager++){

            double manager_ratio = ratios[manager].first;

                sum+=ratios[manager].second;
                pq.push(ratios[manager].second);

                while(pq.size()>k){
                    sum-=pq.top();
                    pq.pop();
                }

                result = min(result,sum*manager_ratio);

        }
        
        return result;
    }
};












