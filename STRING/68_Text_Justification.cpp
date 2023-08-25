class Solution {
public:

// TC: Θ(N) Where N is the size of the input data. More specifically N is the sum of the lengths of all the words.
// Space complexity: Θ(max(words[i].size()));

    vector<string> fullJustify(vector<string>& words, int maxWidth) {

        vector<string> text;
        int start = 0;

        // if we have reached to end.size() --> means last line pe hain it will be handled differently
        
        while(start<words.size()){
            int width = words[start].length();
            int end = start+1;

            while(end<words.size()){
            int max = width+words[end].length()+1;
            if(max>maxWidth) {
                break;
            }
            width=max;
            end++;
            }

            int wordcount = end-start;
           
            int width_extra = 0;
            int extra = 0;

            if(wordcount>1 && end<words.size()){   // not including the last line
            int extraspaces = maxWidth-width;
            width_extra = extraspaces/(wordcount-1);
            extra = extraspaces%(wordcount-1);
            }

            string s = "";

            for(int i = start; i<end; i++){
                
                s+=words[i];
                if(i==end-1) continue;
                int spaces = 1+width_extra+(extra-->0);
                while(spaces--){
                    s+=' ';
                }
            }


            // last line ke liye 
            if(s.length()!=maxWidth){
                int spacedalo = maxWidth-s.length();
                while(spacedalo--){
                    s+=' ';
                }
            }
            text.push_back(s);
            start=end;
        }

        return text;        
    }
};
