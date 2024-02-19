class Solution {
public:

/*
STL reverse() and string comparison
TC: O(n^2)
SC: O( word ka length )
*/

    string firstPalindrome(vector<string>& words) {

       
        for(int i = 0; i<words.size(); i++){
            string str = words[i];

            reverse(str.begin(),str.end());

            if(str==words[i]) {
                return words[i];
            }
        }

        return "";
    }
};



// <---------------------------------------------------------TWO POINTERS ALGORITHM-------------------------------------------------------------------------->


class Solution {
public:

/*
Two Pointer Algorithm
TC: O(n^2)
SC: O(1)
*/

    string firstPalindrome(vector<string>& words) {
       
        for(int i = 0; i<words.size(); i++){
            

            int start = 0;
            int end = words[i].length()-1;

            bool flag = true;

            while(start<=end){
                if(words[i][start]==words[i][end]){
                    start++;
                    end--;
                }
                else {
                    flag = false;
                    break;
                }
            }

            if(flag) return words[i];
        }

        return "";
    }
};










