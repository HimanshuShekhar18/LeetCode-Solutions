class Solution {
public:


/*
Recursion and Backtracking and reverse()
TC: O(n)
SC: O(n)
*/
    int buildSequence(int currentindex, int currentcount, string pattern, string &result){
        if(currentindex >= pattern.length()){
            result+=to_string(currentcount+1);
            return currentcount+1;
        }

        if(pattern[currentindex]=='I'){
            buildSequence(currentindex+1, currentindex+1, pattern, result);
        }
        else{
            currentcount=buildSequence(currentindex+1,currentcount,pattern,result);
        }

        result+=to_string(currentcount+1);
        return currentcount+1;
    }

    string smallestNumber(string pattern) {
        string result = "";

        buildSequence(0, 0, pattern, result);
        // Reverse the final result
        reverse(result.begin(), result.end());
        return result;
    }
};

