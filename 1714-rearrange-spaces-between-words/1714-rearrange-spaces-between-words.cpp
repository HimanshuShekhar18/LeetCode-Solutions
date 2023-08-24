class Solution {
public:

// TC: O(n)
// SC: O(n)

    vector<string> printWords(string str, vector<string> &make)
{
    // word variable to store word
    string word;
 
    // making a string stream
    stringstream iss(str);
 
    // Read and print each word.
    while (iss >> word) make.push_back(word);

    return make;      
}

    string reorderSpaces(string text) {
        
        vector<string> make;

        printWords(text,make);

        string ans = "";

        int count = 0;

        int words = make.size();

        for(int i = 0; i<text.length(); i++){
            if(text[i]==' ') count++;
        }

        if(words==1){
            ans+=make[0];
            while(count--){
            ans+=' ';
        }
        return ans;
        }

        int width = count/(words-1);
        int extra = count%(words-1);

        for(int i=0; i<make.size()-1; i++){
            ans+=make[i];
            int spaces = width;
            while(spaces--){
                ans+=' ';
            }
        }

        ans+=make[make.size()-1];
        while(extra--){
            ans+=' ';
        }

        return ans;  
    }
};