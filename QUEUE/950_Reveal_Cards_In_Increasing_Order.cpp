class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {

        // sort the vector
        sort(deck.begin(), deck.end());

        int n = deck.size();

        vector<int> vect(n, 0);

        int index = 0;  // for navigating the index position of vect

        int i = 0;  // for navigating the index position of deck

        // for odd 
        if (n % 2 != 0) {

            // fill the starting n/2+1 elements of deck at alternate position
            for (i = 0; index < deck.size() && i < deck.size() / 2 + 1;
                 i++) {

                vect[index] = deck[i];
                index += 2;
            }
            index = 1;

        bool skip = true;
        // rest elements by skipping position(+2) starting at index 3
        while(i<n){

            if(vect[index]==0){

                if(skip==false){
                    vect[index]=deck[i];
                    i++;
                }

                skip = !skip;

            }

            index=(index+2)%n;
        }
        }
        // for even
         else {

            // fill the starting n/2 elements of deck at alternate position
            for (i = 0; index < deck.size() && i < deck.size() / 2;
                 i++) {

                vect[index] = deck[i];
                index += 2;
            }
            index = 1;

        bool skip = false;
        // rest elements by skipping position(+2) starting at index 1
        while(i<n){

            if(vect[index]==0){

                if(skip==false){
                    vect[index]=deck[i];
                    i++;
                }

                skip = !skip;

            }

            index=(index+2)%n;
        }
        }

        return vect;
    }
};
