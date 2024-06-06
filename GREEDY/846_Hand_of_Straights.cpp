class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

            bool flag = false;

            if(hand.size()%groupSize) return flag;

           

            unordered_map<int,int> mp;

            for(int i = 0; i<hand.size(); i++){
                mp[hand[i]]++;
            }

            priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> q;
        
            for(auto it: mp){
                q.push({it.first,it.second});
            }

            int k = groupSize;

            while(!q.empty()){

                vector<int> vect;

                int last = q.top().first;
                q.pop();
                vect.push_back(last);

                    while( groupSize>1 ){
                        
                        int top = q.top().first;
        
                        if(top!=last+1) {
                            return false;
                        }
                        q.pop();
                        vect.push_back(top);
                        last = top;
                        groupSize--;
                    }

                    for(int i = 0; i<k; i++){
                        if(--mp[vect[i]]>0) {
                            q.push({vect[i],mp[vect[i]]});
                        }
                  
                    }
                    groupSize = k;
            }

            return true;
    }
};





// <------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------>



class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

            bool flag = false;

            if(hand.size()%groupSize) return flag;

            map<int,int> mp;

            for(int i = 0; i<hand.size(); i++){
                mp[hand[i]]++;
            }

            priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> q;
        
            while(!mp.empty()){

                int curr = mp.begin()->first;

                for(int i = 0; i<groupSize; i++){

                       if(mp[curr+i] == 0) return false;

                       mp[curr+i]--;

                       if(mp[curr+i]<1) mp.erase(curr+i);

                }  
            }

            return true;
    }
};


