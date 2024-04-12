class Solution {
public:

/*

Deque Data Structure

deck = {11 13 15 17} 

        17
     15 17 17×   --->  15 17 
    13 17 15 17× --->  13 17 15
 11 15 13 17 15× --->  11 15 13 17

 Hence 11 15 13 17 is our ans

 TC: O(n*log(n)) + O(n) + O(n)  
 as insertion and deletion in deque is an O(1) operation

 SC: O(n) + O(n)

*/

    vector<int> deckRevealedIncreasing(vector<int>& deck) {

        // sort the vector
        sort(deck.begin(), deck.end());

        int n = deck.size();

        deque<int> dq;

        vector<int> vect;

        // O(n)
        for(int i = n-1; i>=0; i--){

            if(!dq.empty()){
                dq.push_front(dq.back());
                dq.pop_back();
            }

            dq.push_front(deck[i]);
        }

        for(auto it: dq){
            vect.push_back(it);
        }

        return vect;
    }
};
