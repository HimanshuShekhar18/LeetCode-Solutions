/*
Combinations and Permutations
Generate all Combinations and then apply Permutation on each Combination  
TC: O( n*  ( 2^n  + n * log(n) )  
SC: O( n * 2^n ) 

Be Careful of Edge Cases eg: CDC Combinations are C, D, CC, CD, DC, CDC; 
Here CD and DC are Permutations of each other; 
Hence only one should be considered
*/
class Solution {
public:

/*
    Generate all Combinations(2^n) Standard Pick Not-Pick and then apply Permutation on each Combination  
    TC: O( n* 2^n )   
    SC: O( n * 2^n ) 
*/

    set<vector<char>> ans;

    void combination(int n, int index, string tiles, vector<char>& curr){

        if(index==n){
            if(curr.size()==0) return;
            vector<char> temp = curr;
            sort(temp.begin(),temp.end());
            ans.insert(temp);
            return;
        }

        curr.push_back(tiles[index]);
        combination(n,index+1,tiles,curr);
        curr.pop_back();
        combination(n,index+1,tiles,curr);
    }

    int fact(int number){
        if(number==1) return 1;
        
        int resultfact = 1;
        for(int i = 2; i<=number; i++){
                resultfact=resultfact*i;
        }
        return resultfact;
    }

    int permutation(){
        unordered_map<char,int> mp;
        int finalans = 0;
        for(auto s: ans){
            int stringlength = s.size();
            int numeratorvalue = fact(stringlength);
            mp.clear();
            for(int i = 0; i<stringlength; i++){
                    mp[s[i]]++;
            }

            for(auto m: mp){
                int charfreq = m.second;
                numeratorvalue = numeratorvalue/fact(charfreq);
            }
            finalans+=numeratorvalue;
            
        }
        return finalans;
    }

    int numTilePossibilities(string tiles) {
        int n = tiles.length();
        vector<char> curr;
        combination(n,0,tiles,curr);
        for(auto s: ans){
            for(int i = 0; i<s.size(); i++){
                cout << s[i] << " ";
            }
            cout << endl;
        }
        return permutation();
    }
};


